idf_component_register(SRCS "sdcard.c" ${SOURCES}
                    INCLUDE_DIRS . "include" "../../main/ui"
                    REQUIRES driver fatfs vfs lvgl)
