# [English](https://github.com/VIEWESMART/UEDX24320028ESP32-3.5inch-320_480-Display/blob/main/firmware/README.md)

# 文件夹说明

本文件夹主要用于存放烧录固件，方便大家对相关功能进行验证。

## 1. lvgl_smiulate_ios.bin
这是一个模拟 IOS 的用户界面（UI），我们在其中实现了多项功能，包括设置、天气、音乐、手电筒以及游戏功能。相应的代码已开源，开发者能够基于此进一步拓展其他功能。下方附有对应的展示图片和视频。

 <p align="center" width="80%">
    <img src="https://github.com/VIEWESMART/UEDX24320028ESP32-3.5inch-320_480-Display/blob/main/image/smiulate_ios.png" alt="">
  </p>

### 使用方法
* 准备一张 Micro SD 卡。
* 在 SD 卡内创建 “music” 和 “nes\rom” 两个文件夹。“music” 文件夹用于存放 mp3 音乐文件，“nes\rom” 文件夹下直接放置.nes 格式的游戏文件。小游戏的下载地址为：[小游戏下载地址](https://www.consoleroms.com/roms/nes)
  
* 对于天气功能，可手动调整区域码。在代码中找到对应的区域码设置项，设定后系统将默认显示该地区的天气状况。
  
注意：此开发板未连接 SD 卡检测模块，不存在 SD 卡检测程序。若不插入 SD 卡或没有建立对应的目录，设备将会重启。

## 2. portig_lvgl_h35.bin
此固件包含一个 lvgl 演示示例程序，程序相关图片如下：

<p align="center" width="80%">
    <img src="https://github.com/VIEWESMART/UEDX24320028ESP32-3.5inch-320_480-Display/blob/main/image/3.5_h.png" alt="">
</p>
