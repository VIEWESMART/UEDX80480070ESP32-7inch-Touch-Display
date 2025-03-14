idf_component_register(SRCS "uart.c" ${SOURCES}
                    INCLUDE_DIRS . "include" "../../main/ui"
                    REQUIRES driver lvgl)