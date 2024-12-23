idf_component_register(
    SRC_DIRS
        "." 
    INCLUDE_DIRS
        "include"
    REQUIRES driver 
    esp_common 
    log
    lvgl_touch
    esp_lcd
   )
