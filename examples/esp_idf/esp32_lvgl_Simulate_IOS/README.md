|支持的目标 |ESP32-S3 UEDX32480035E-WB-A系列 |
|-----------------|-------- |

# 项目说明
该示例是一个仿iOS的UI界面，我们在其中实现了天气、设置、音乐、手电筒、娱乐游戏等

## 如何使用示例
电量显示是接收其他芯片通过串口发送的电量。
首次开机联网后自动获取时间。
SD卡刷新需要存在如下文件夹
/music/
/nes/rom/

天气功能请修改components/weather/weather.c文件void weather_get_task(void *arg)函数中的key值为高德开放平台天气接口KEY值。
char *key = "1234567890abcdefghijklmnopqrstuvwxyz";

## 示例文件夹内容

项目包含一个 C 语言 [main.c]（main/main.c） 的源文件。该文件位于main文件夹。
