/*
 *	InfoNES
 *		SDL ports by mata      03/04/19
 *              Modified by Jay        06/02/25
 *
 * 	Start Date: 2003.04.19
 */

#include "InfoNES_System.h"

#include "lvgl/lvgl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "InfoNES.h"
#include "InfoNES_pAPU.h"
#include "nesgame.h"
#include "volume.h"
#include <math.h>
/*-------------------------------------------------------------------*/
/*  ROM image file information                                       */
/*-------------------------------------------------------------------*/
extern i2s_chan_handle_t tx_chan; // I2S tx channel handler
char szRomName[256];
char szSaveName[256];
int nSRAM_SaveFlag;

/*-------------------------------------------------------------------*/
/*  Constants ( Linux specific )                                     */
/*-------------------------------------------------------------------*/

#define VBOX_SIZE 0
// static const char * VERSION = "InfoNES v0.97J RC1";

/*-------------------------------------------------------------------*/
/*  Global Variables ( SDL specific )                                */
/*-------------------------------------------------------------------*/

bool quit = false;

/* for video */

/* For Sound Emulation */
// BYTE final_wave[2048];
int16_t *final_wave;
int waveptr;
int wavflag;
int wavdone;

/* Pad state */
DWORD dwPad1;
DWORD dwPad2;
DWORD dwSystem;

/*-------------------------------------------------------------------*/
/*  Function prototypes ( SDL specific )                             */
/*-------------------------------------------------------------------*/

// void poll_event(void);

/* Palette data */
// WORD NesPalette[64] =
//     {
//         0x39ce, 0x1071, 0x0015, 0x2013, 0x440e, 0x5402, 0x5000, 0x3c20,
//         0x20a0, 0x0100, 0x0140, 0x00e2, 0x0ceb, 0x0000, 0x0000, 0x0000,
//         0x5ef7, 0x01dd, 0x10fd, 0x401e, 0x5c17, 0x700b, 0x6ca0, 0x6521,
//         0x45c0, 0x0240, 0x02a0, 0x0247, 0x0211, 0x0000, 0x0000, 0x0000,
//         0x7fff, 0x1eff, 0x2e5f, 0x223f, 0x79ff, 0x7dd6, 0x7dcc, 0x7e67,
//         0x7ae7, 0x4342, 0x2769, 0x2ff3, 0x03bb, 0x0000, 0x0000, 0x0000,
//         0x7fff, 0x579f, 0x635f, 0x6b3f, 0x7f1f, 0x7f1b, 0x7ef6, 0x7f75,
//         0x7f94, 0x73f4, 0x57d7, 0x5bf9, 0x4ffe, 0x0000, 0x0000, 0x0000
// };
WORD NesPalette[64] =
    {
        0x8E73, 0xf120, 0x3500, 0x3340, 0x0e88, 0x02a8, 0x00a0, 0x4078,
        0x4041, 0x0002, 0x8002, 0xc201, 0xcb19, 0x0000, 0x0000, 0x0000,
        0xf7bd, 0xbd03, 0xfd21, 0x3e80, 0x37b8, 0x0be0, 0x40d9, 0x41ca,
        0x808b, 0x8004, 0x4005, 0x8704, 0x3104, 0x0000, 0x0000, 0x0000,
        0xffff, 0xff3d, 0xbf5c, 0x7f44, 0xfff3, 0xb6fb, 0x8cfb, 0xc7fc,
        0xc7f5, 0x8286, 0xc94e, 0xf35f, 0x7b07, 0x0000, 0x0000, 0x0000,
        0xffff, 0x3faf, 0xbfc6, 0x7fd6, 0x3ffe, 0x3bfe, 0xf6fd, 0xf5fe,
        0x34ff, 0xf4e7, 0xb7af, 0xf9b7, 0xfe9f, 0x0000, 0x0000, 0x0000};
/*===================================================================*/
/*                                                                   */
/*           LoadSRAM() : Load a SRAM                                */
/*                                                                   */
/*===================================================================*/
/* Start application */
int start_application(char *filename)
{
  /* Set a ROM image name */
  strcpy(szRomName, filename);

  /* Load cassette */
  if (InfoNES_Load(szRomName) == 0)
  {
    /* Load SRAM */
    // LoadSRAM();

    /* Success */
    return 1;
  }
  /* Failure */
  return 0;
}

/*===================================================================*/
/*                                                                   */
/*           LoadSRAM() : Load a SRAM                                */
/*                                                                   */
/*===================================================================*/
int LoadSRAM()
{
  /*
   *  Load a SRAM
   *
   *  Return values
   *     0 : Normally
   *    -1 : SRAM data couldn't be read
   */

  FILE *fp;
  unsigned char pSrcBuf[SRAM_SIZE];
  unsigned char chData;
  unsigned char chTag;
  int nRunLen;
  int nDecoded;
  int nDecLen;
  int nIdx;

  // It doesn't need to save it
  nSRAM_SaveFlag = 0;

  // It is finished if the ROM doesn't have SRAM
  if (!ROM_SRAM)
    return 0;

  // There is necessity to save it
  nSRAM_SaveFlag = 1;

  // The preparation of the SRAM file name
  strcpy(szSaveName, szRomName);
  strcpy(strrchr(szSaveName, '.') + 1, "srm");

  /*-------------------------------------------------------------------*/
  /*  Read a SRAM data                                                 */
  /*-------------------------------------------------------------------*/

  // Open SRAM file
  fp = fopen(szSaveName, "rb");
  if (fp == NULL)
    return -1;

  // Read SRAM data
  fread(pSrcBuf, SRAM_SIZE, 1, fp);

  // Close SRAM file
  fclose(fp);

  /*-------------------------------------------------------------------*/
  /*  Extract a SRAM data                                              */
  /*-------------------------------------------------------------------*/

  nDecoded = 0;
  nDecLen = 0;

  chTag = pSrcBuf[nDecoded++];

  while (nDecLen < 8192)
  {
    chData = pSrcBuf[nDecoded++];

    if (chData == chTag)
    {
      chData = pSrcBuf[nDecoded++];
      nRunLen = pSrcBuf[nDecoded++];
      for (nIdx = 0; nIdx < nRunLen + 1; ++nIdx)
      {
        SRAM[nDecLen++] = chData;
      }
    }
    else
    {
      SRAM[nDecLen++] = chData;
    }
  }

  // Successful
  return 0;
}

/*===================================================================*/
/*                                                                   */
/*           SaveSRAM() : Save a SRAM                                */
/*                                                                   */
/*===================================================================*/
int SaveSRAM()
{
  /*
   *  Save a SRAM
   *
   *  Return values
   *     0 : Normally
   *    -1 : SRAM data couldn't be written
   */

  FILE *fp;
  int nUsedTable[256];
  unsigned char chData;
  unsigned char chPrevData;
  unsigned char chTag;
  int nIdx;
  int nEncoded;
  int nEncLen;
  int nRunLen;
  unsigned char pDstBuf[SRAM_SIZE];

  if (!nSRAM_SaveFlag)
    return 0; // It doesn't need to save it

  /*-------------------------------------------------------------------*/
  /*  Compress a SRAM data                                             */
  /*-------------------------------------------------------------------*/

  memset(nUsedTable, 0, sizeof nUsedTable);

  for (nIdx = 0; nIdx < SRAM_SIZE; ++nIdx)
  {
    ++nUsedTable[SRAM[nIdx++]];
  }
  for (nIdx = 1, chTag = 0; nIdx < 256; ++nIdx)
  {
    if (nUsedTable[nIdx] < nUsedTable[chTag])
      chTag = nIdx;
  }

  nEncoded = 0;
  nEncLen = 0;
  nRunLen = 1;

  pDstBuf[nEncLen++] = chTag;

  chPrevData = SRAM[nEncoded++];

  while (nEncoded < SRAM_SIZE && nEncLen < SRAM_SIZE - 133)
  {
    chData = SRAM[nEncoded++];

    if (chPrevData == chData && nRunLen < 256)
      ++nRunLen;
    else
    {
      if (nRunLen >= 4 || chPrevData == chTag)
      {
        pDstBuf[nEncLen++] = chTag;
        pDstBuf[nEncLen++] = chPrevData;
        pDstBuf[nEncLen++] = nRunLen - 1;
      }
      else
      {
        for (nIdx = 0; nIdx < nRunLen; ++nIdx)
          pDstBuf[nEncLen++] = chPrevData;
      }

      chPrevData = chData;
      nRunLen = 1;
    }
  }
  if (nRunLen >= 4 || chPrevData == chTag)
  {
    pDstBuf[nEncLen++] = chTag;
    pDstBuf[nEncLen++] = chPrevData;
    pDstBuf[nEncLen++] = nRunLen - 1;
  }
  else
  {
    for (nIdx = 0; nIdx < nRunLen; ++nIdx)
      pDstBuf[nEncLen++] = chPrevData;
  }

  /*-------------------------------------------------------------------*/
  /*  Write a SRAM data                                                */
  /*-------------------------------------------------------------------*/

  // Open SRAM file
  fp = fopen(szSaveName, "wb");
  if (fp == NULL)
    return -1;

  // Write SRAM data
  fwrite(pDstBuf, nEncLen, 1, fp);

  // Close SRAM file
  fclose(fp);

  // Successful
  return 0;
}

/*===================================================================*/
/*                                                                   */
/*                  InfoNES_Menu() : Menu screen                     */
/*                                                                   */
/*===================================================================*/
int InfoNES_Menu(void)
{
  if (stats == 0)
  {
    return -1;
    printf("%d\n", stats);
  }
  return 0;
  // if(quit) return -1;
}

/* Read ROM image file */
int InfoNES_ReadRom(const char *pszFileName)
{
  FILE *fp;

  /* Open ROM file */
  fp = fopen(pszFileName, "rb");
  if (fp == NULL)
    return -1;

  /* Read ROM Header */
  fread(&NesHeader, sizeof NesHeader, 1, fp);
  if (memcmp(NesHeader.byID, "NES\x1a", 4) != 0)
  {
    /* not .nes file */
    fclose(fp);
    return -1;
  }

  /* Clear SRAM */
  memset(SRAM, 0, SRAM_SIZE);

  /* If trainer presents Read Triner at 0x7000-0x71ff */
  if (NesHeader.byInfo1 & 4)
  {
    fread(&SRAM[0x1000], 512, 1, fp);
  }

  /* Allocate Memory for ROM Image */
  ROM = (BYTE *)malloc(NesHeader.byRomSize * 0x4000);

  /* Read ROM Image */
  fread(ROM, 0x4000, NesHeader.byRomSize, fp);

  if (NesHeader.byVRomSize > 0)
  {
    /* Allocate Memory for VROM Image */
    VROM = (BYTE *)malloc(NesHeader.byVRomSize * 0x2000);

    /* Read VROM Image */
    fread(VROM, 0x2000, NesHeader.byVRomSize, fp);
  }

  /* File close */
  fclose(fp);

  /* Successful */
  return 0;
}

/* Release a memory for ROM */
void InfoNES_ReleaseRom()
{
  if (ROM)
  {
    free(ROM);
    ROM = NULL;
  }

  if (VROM)
  {
    free(VROM);
    VROM = NULL;
  }
}

/* Transfer the contents of work frame on the screen */
void InfoNES_LoadFrame()
{
  nes_flush();
}

/* Get a joypad state */
void InfoNES_PadState(DWORD *pdwPad1, DWORD *pdwPad2, DWORD *pdwSystem)
{
  // poll_event();
  *pdwPad1 = dwPad1;
  *pdwPad2 = dwPad2;
  *pdwSystem = dwSystem;
}

/* memcpy */
void *InfoNES_MemoryCopy(void *dest, const void *src, int count)
{
  memcpy(dest, src, count);
  return dest;
}

/* memset */
void *InfoNES_MemorySet(void *dest, int c, int count)
{
  memset(dest, c, count);
  return dest;
}

/* Print debug message */
void InfoNES_DebugPrint(char *pszMsg)
{
  // fprintf(stderr,"%s\n", pszMsg);
  printf("[错误]: %s\n", pszMsg);
}

/* Wait */
void InfoNES_Wait() {}

/* Sound Initialize */
void InfoNES_SoundInit(void) {}

void waveout(void *udat, BYTE *stream, int len)
{
  if (!wavdone)
  {
    /* we always expect that len is 1024 */
    memcpy(stream, &final_wave[(wavflag - 1) << 10], len);
    wavflag = 0;
    wavdone = 1;
  }
}

/* Sound Open */
// samples_per_sync=735
// sample_rate =44100
int InfoNES_SoundOpen(int samples_per_sync, int sample_rate)
{
  std_cfg.slot_cfg.slot_mode = I2S_SLOT_MODE_MONO; // 改变单声道
  std_cfg.slot_cfg.data_bit_width = I2S_DATA_BIT_WIDTH_16BIT;
  std_cfg.clk_cfg.sample_rate_hz = sample_rate;
  i2s_channel_reconfig_std_clock(tx_chan, &std_cfg.clk_cfg);
  i2s_channel_reconfig_std_slot(tx_chan, &std_cfg.slot_cfg);
  gpio_set_direction(GPIO_NUM_9, GPIO_MODE_OUTPUT); // 功放开关，1为高电平，0为低电平);
  gpio_set_level(GPIO_NUM_9, 1);                    // 打开功放
  ESP_ERROR_CHECK(i2s_channel_enable(tx_chan));
  ESP_LOGI("NES", "打开功放");
  final_wave = heap_caps_malloc(samples_per_sync * 2 * sizeof(int16_t), MALLOC_CAP_DMA);
  memset(final_wave, 0, samples_per_sync * sizeof(int16_t));
  /* Successful */
  return 1;
}

/* Sound Close */
void InfoNES_SoundClose(void)
{
}

/* Sound Output 5 Waves - 2 Pulse, 1 Triangle, 1 Noise. 1 DPCM */
void InfoNES_SoundOutput(int samples, BYTE *wave1, BYTE *wave2, BYTE *wave3, BYTE *wave4, BYTE *wave5)
{
  int i;
  size_t bytes_written;
  wavdone = 0;
  for (i = 0; i < samples; i++)
  {
    // 将8位样本转换为16位，减去128以使数据居中于零点
    int32_t sum = (wave1[i] + 0x80) + (wave2[i] + 0x80) + (wave3[i] + 0x80) + (wave4[i] + 0x80) + (wave5[i] + 0x80);
    final_wave[i] = (int16_t)((sum / 5) << 8);
    // 混音器，直接计算
    // output = pulse_out + tnd_out
    // pulse_out = 0.00752 * (pulse1 + pulse2)
    // tnd_out = 0.00851 * triangle + 0.00494 * noise + 0.00335 * dmc
  }

  wavdone = 1;
  i2s_channel_write(tx_chan, final_wave, samples * sizeof(int16_t), &bytes_written, pdMS_TO_TICKS(500));
}

/* Print system message */
void InfoNES_MessageBox(char *pszMsg, ...) {}
