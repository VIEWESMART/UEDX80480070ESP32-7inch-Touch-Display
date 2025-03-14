idf_component_register(SRCS "rgbled.c" "led_strip_encoder.c" ${SOURCES}
                    INCLUDE_DIRS . "include" "../../main/ui"
                    REQUIRES driver lvgl)
