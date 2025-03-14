file(GLOB_RECURSE SOURCES include/*.c)
idf_component_register(SRCS "nesgame.c" ${SOURCES}
                    INCLUDE_DIRS . "include"
                    REQUIRES driver esp_event spi_flash nvs_flash sdcard volume lvgl)
#target_compile_options(${COMPONENT_LIB} PRIVATE -w)