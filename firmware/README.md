# [中文说明](https://github.com/VIEWESMART/UEDX24320028ESP32-3.5inch-320_480-Display/blob/main/firmware/README_CN.md)
# Folder Description

This folder mainly stores the burned firmware so that everyone can verify the functions, etc.

## 1. lvgl_smiulate_ios.bin

This is a UI interface that emulates IOS. We have implemented several functions in it, including Settings, Weather, Music, Flashlight, and Games. The corresponding code has been open - sourced, and developers can further expand other functions based on this. The corresponding pictures and videos are attached below.

  <p align="center" width="80%">
    <img src="https://github.com/VIEWESMART/UEDX24320028ESP32-3.5inch-320_480-Display/blob/main/image/smiulate_ios.png" alt="">
  </p>

### How to Use?
* Prepare a Micro SD card.
* Create two folders named `music` and `nes\rom` in the SD card. The music folder is used to store mp3 files, and the.nes game files should be directly placed under the nes\rom folder. The download address of the mini-games:[here](https://www.consoleroms.com/roms/nes)
  
* For the weather function, the area code can be adjusted manually. Find the corresponding area code setting item in the code. After setting, the system will display the weather conditions of the corresponding area by default.

Note: This development board does not have an SD card detection function, so there is no SD card detection program. If the card is not inserted or the corresponding directory does not exist, the device will restart.

## 2. portig_lvgl_h35.bin
This firmware is a sample program with an lvgl demo. The pictures of the program are as follows: 

<p align="center" width="80%">
    <img src="https://github.com/VIEWESMART/UEDX24320028ESP32-3.5inch-320_480-Display/blob/main/image/3.5_h.png" alt="">
</p>
