<h1 align = "center">VIEWE ESP32-S3 Smart Display Quick Guide</h1>

<p align="center" width="80%">
    <img src="image/7inch.jpg" alt="">
</p>

## **English | [中文](./README_CN.md)**

## Introduction to the Repository Directory

```
├── Libraries              Library files required for the Arduino example  
├── Schematic              The circuit schematic of the product   
├── examples               Sample files, including the IDF framework and the Arduino framework
├── firmware               firmware
├── image                  Product or sample project related images
├── information            Product specifications, including the IC or peripherals involved
├── tools                  Burn tool and image conversion tool
└── README.md              This is the file you are currently reading,Give a brief introduction to the product
```

## Version iteration:
|   Development board Version   |  Screen size   |   Resolution  | Update date        |Update description|
| :-------------------------------: | :-------------------------------: | :-------------------------------: | :-------------------------------: |:-------------------------------: |
| UEDX80480070E-WB-A V1.1 | 7ich |  800*480  |2024-07-23      | Original version   |

## PurchaseLink

| Product                     | SOC           |  FLASH  |  PSRAM   | Link                   |
| :------------------------: | :-----------: |:-------: | :---------: | :------------------: |
| UEDX80480070E-WB-A V1.1   | ESP32S3R8 |   16M   | 8M (Octal SPI) | [VIEWE Mall](https://viewedisplay.com/product/esp32-7-inch-800x480-rgb-ips-tft-display-touch-screen-arduino-lvgl-uart/)  |

## Directory
- [Describe](#describe)
- [Module](#module)
- [QuickStart](#quickstart)
- [PinOverview](#pinoverview)
- [FAQ](#faq)
- [Schematic](#Schematic)
- [Information](#information)
- [DependentLibraries](#dependentlibraries)

## Describe

UEDX80480070ESP32-7inch-Display-800_480 is a development board with square 7inch 800 * 480 resolution display, based on ESP32S3, suitable for the development of microcontroller projects with display.


## Module

### 1.MCU

* Chip: ESP32-S3-R8
* PSRAM: 8M (Octal SPI) 
* FLASH: 16M
* For more details, please visit[Espressif ESP32-S3 Datashee](https://www.espressif.com.cn/sites/default/files/documentation/esp32-s3_datasheet_en.pdf)

### 2. Screen

* Size: 7-inch IPS screen
* Resolution: 800x480px
* Screen type: IPS
* Driver chip: EK9716BD3+EK73002AB2
* Compatibility library:  ESP32_Display_Panel
* Bus communication protocol: RGB

### 3. Touch

* Chip: GT911
* Bus communication protocol: IIC


## QuickStart

### Examples Support

| Example | Support IDE And Version| Description | Picture |
| ------  | ------  | ------ | ------ | 
| [ESP-IDF](./examples/ESP-IDF) | `[ESP-IDF V5.1/5.2/5.3]` | idf driver example code |  |
| [PanelTest](./examples/PanelTest) |`[Arduino IDE][esp32_v2.0.14]` | Product factory original testing |  |
| [Porting](./examples/Porting) | `[Arduino IDE][esp32_v3.0 above]` | LVGL example code |  |
| [WiFiClock](./examples/WiFiClock) | `[Arduino IDE][esp32_v2.0.14]` | SquareLine porting example for Arduino |  |
| [PlatformIO](./examples/PlatformIO) | `[Platformio IDE]` |  |  |


| Firmware | Description | Picture |
| ------  | ------  | ------ |
| [ESP-IDF](./firmware/[T-Display-S3-AMOLED-1.43_V1.0][Original_Test]_firmware_V1.0.0.bin) | Original |  |
| [PanelTest](./firmware/[T-Display-S3-AMOLED-1.43_V1.0][Light_Sleep_Wake_Up]_firmware_V1.0.0.bin) | Original |  |
| [Porting](./firmware/[T-Display-S3-AMOLED-1.43_V1.0][Deep_Sleep_Wake_Up]_firmware_V1.0.0.bin) | Original |  |
| [WiFiClock](./firmware/[T-Display-S3-AMOLED-1.75_V1.0][Original_Test_H0175Y003AM]_firmware_V1.0.2.bin) | Original |  |

### PlatformIO
1. Install[VisualStudioCode](https://code.visualstudio.com/Download),Choose installation based on your system type.

2. Open the "Extension" section of the Visual Studio Code software sidebar(Alternatively, use "<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>X</kbd>" to open the extension),Search for the "PlatformIO IDE" extension and download it.

3. During the installation of the extension, you can go to GitHub to download the program. You can download the main branch by clicking on the "<> Code" with green text.

4. After the installation of the extension is completed, open the Explorer in the sidebar(Alternatively, use "<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>E</kbd>" go open it),Click "Open Folder", find the project code you just downloaded (the entire folder), then find the PlatformIO folder and click "Add". At this point, the project file will be added to your workspace.

5. Open the "platformio.ini" file in the project folder (PlatformIO will automatically open the "platformio.ini" file corresponding to the added folder). Under the "[platformio]" section, uncomment and select the example program you want to burn (it should start with "default_envs = xxx") Then click "<kbd>[√](image/4.png)</kbd>" in the bottom left corner to compile,If the compilation is correct, connect the microcontroller to the computer and click "<kbd>[→](image/5.png)</kbd>" in the bottom left corner to download the program.

### Arduino
1. Install[Arduino](https://www.arduino.cc/en/software),Choose installation based on your system type.

2. Open the "example" directory within the project folder, select the example project folder, and open the file ending with ".ino" to open the Arduino IDE project workspace.

3. Open the "Tools" menu at the top right -> Select "Board" -> "Board Manager." Find or search for "esp32" and download the board files from the author named "Espressif Systems." Then, go back to the "Board" menu and select the development board type under "ESP32 Arduino." The selected development board type should match the one specified in the "platformio.ini" file under the [env] section with the header "board = xxx." If there is no corresponding development board, you may need to manually add the development board from the "board" directory within your project folder.

4. Open menu bar "[File](image/6.png)" -> "[Preferences](image/6.png)" ,Find "[Sketchbook location](image/7.png)"  here,copy and paste all library files and folders from the "libraries" folder in the project directory into the "libraries" folder in this directory.

5. Select the correct settings in the Tools menu, as shown in the table below.

#### ESP32-S3
| Setting                               | Value                                 |
| :-------------------------------: | :-------------------------------: |
| Board                                 | ESP32S3 Dev Module           |
| CPU Frequency                   | 240MHz (WiFi)                    |
| Core Debug Level                | None                                 |
| USB CDC On Boot                | Disabled                              |
| USB DFU On Boot                | Disabled                             |
| Events Run On                     | Core 1                               |  
| Flash Mode                         | QIO 80MHz                         |
| Flash Size                           | 16MB (128Mb)                    |
| Arduino Runs On                  | Core 1                               |
| USB Firmware MSC On Boot | Disabled                             |
| Partition Scheme                | 16M Flash (3MB APP/9.9MB FATFS) |
| PSRAM                                | OPI PSRAM                         |
| Upload Mode                     |     UART0/Hardware CDC            |
| Upload Speed                     | 921600                               |
| USB Mode                           | Hardware CDC and JTAG     |

6. Select the correct port.

7. Click "<kbd>[√](image/8.png)</kbd>" in the upper right corner to compile,If the compilation is correct, connect the microcontroller to the computer,Click "<kbd>[→](image/9.png)</kbd>" in the upper right corner to download.

### firmware download
1. Open the project file "tools" and locate the ESP32 burning tool. Open it.

2. Select the correct burning chip and burning method, then click "OK." As shown in the picture, follow steps 1->2->3->4->5 to burn the program. If the burning is not successful, press and hold the "BOOT-0" button and then download and burn again.

3. Burn the file in the root directory of the project file "[firmware](./firmware/)" file,There is a description of the firmware file version inside, just choose the appropriate version to download.

<p align="center" width="100%">
    <img src="image/10.png" alt="example">
    <img src="image/11.png" alt="example">
</p>


## PinOverview

| IPS Screen Pin  | ESP32S3 Pin|
| :------------------: | :------------------:|
| DE         | IO40       |
| VS         | IO41       |
| HS         | IO439       |
| PCLK       | IO42       |
|   R0       |  IO45   |
|   R1       |  IO48   |
|   R2       |  IO47   |
|   R3       |  IO21   |
|   R4       |  IO14   |
|   G0       |  IO5   |
|   G1       |  IO6   |
|   G2       |  IO7   |
|   G3       |  IO15   |
|   G4       |  IO16   |
|   G5       |  IO4   |
|   B0       |  IO8   |
|   B1       |  IO3   |
|   B2       |  IO46   |
|   B3       |  IO9   |
|   B4       |  IO1   |
| RST        | IO39       |
| BACKLIGHT  | IO2       |

| Touch Chip Pin  | ESP32S3 Pin|
| :------------------: | :------------------:|
| RST         | IO38 |
| INT         | IO18 |
| SDA         | IO19 |
| SCL         | IO20 |

| USB (CH340C) Pin  | ESP32S3 Pin|
| :------------------: | :------------------:|
| D+(USB-DP)    | IO20       |
| D-(USB-DN)    | IO19       |

| button Pin  | ESP32S3 Pin|
| :------------------: | :------------------:|
|   boot    | IO0       |
|   reset   | chip-en   |

| SD Card Pin  | ESP32S3 Pin|
| :------------------: | :------------------:|
| D1         | IO18       |
| D2         | IO15       |
| MOSI        | IO17       |
| MISO         | IO16       |

| UART/RS485 Pin  | ESP32S3 Pin|
| :------------------: | :------------------:|
| UARTTX         | IO43(RXD0)      |
| UARTRX         | IO44(TXD0)      |

| RGB LED Pin  | ESP32S3 Pin|
| :------------------: | :------------------:|
| RGB LED         | IO0 |



## FAQ

* Q. After reading the above tutorials, I still don't know how to build a programming environment. What should I do?
* A. If you still don't understand how to build an environment after reading the above tutorials, you can refer to the [VIEWE-FAQ]() document instructions to build it.

<br />

* Q. Why does Arduino IDE prompt me to update library files when I open it? Should I update them or not?
* A. Choose not to update library files. Different versions of library files may not be mutually compatible, so it is not recommended to update library files.

<br />

* Q. Why is there no serial data output on the "Uart" interface on my board? Is it defective and unusable?
* A. The default project configuration uses the USB interface as Uart0 serial output for debugging purposes. The "Uart" interface is connected to Uart0, so it won't output any data without configuration.<br />For PlatformIO users, please open the project file "platformio.ini" and modify the option under "build_flags = xxx" from "-D ARDUINO_USB_CDC_ON_BOOT=true" to "-D ARDUINO_USB_CDC_ON_BOOT=false" to enable external "Uart" interface.<br />For Arduino users, open the "Tools" menu and select "USB CDC On Boot: Disabled" to enable the external "Uart" interface.

<br />

* Q. Why is my board continuously failing to download the program?
* A. Please hold down the "BOOT" button and try downloading the program again.

## Schematic
<p align="center" width="100%">
    <img src="Schematic/UEDX80480070E-WB-A%20V1.1%20sch.png" alt="example">
</p>

## Information
[products specification](information/UEDX80480070E-WB-A%20V2.0%20SPEC.pdf)

[Display Datasheet](information/ALL-UE070WV-RB40-A092A.pdf)

[Touch IC Datasheet_EN](information/GT911_EN_Datasheet.pdf)

[Touch IC Datasheet_CN](information/GT911_CN_Datasheet.pdf)

[5050RGB-LED](information/C2843785_RGB%2BLED(Built-in%20IC)_XL-5050RGBC-WS2812B_specification_WJ1123912.PDF)

[CH340C](information/C84681_USB%20Conversion%20chip_CH340C_specification_WJ1187874.PDF)

## DependentLibraries
* [ESP32_Display_Panel>0.2.1](https://github.com/esp-arduino-libs/ESP32_Display_Panel) (Please [download](./Libraries/ESP32_Display_Panel) the library first as the latest version has not been released yet)
* [ESP32_IO_Expander](https://github.com/esp-arduino-libs/ESP32_IO_Expander) (Please [download](./Libraries/ESP32_IO_Expander) the library first as the latest version has not been released yet)
* [NTPClient-3.2.1](https://github.com/bitbank2/JPEGDEC)
* [ArduinoJson-6.21.3](https://github.com/bblanchon/ArduinoJson.git)
* [lvgl-8.4.0](https://lvgl.io)



