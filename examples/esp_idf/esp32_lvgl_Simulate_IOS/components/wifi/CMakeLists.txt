idf_component_register(SRCS "wifi.c" ${SOURCES}
                       INCLUDE_DIRS . "include" "../../main/ui"
                       REQUIRES esp_wifi nvs_flash lvgl)