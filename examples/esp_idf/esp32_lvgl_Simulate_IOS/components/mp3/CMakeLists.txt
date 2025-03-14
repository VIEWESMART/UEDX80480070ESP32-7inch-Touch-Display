# file(GLOB_RECURSE SOURCES include/*.c)
idf_component_register(SRCS "mp3.c" ${SOURCES}
                    INCLUDE_DIRS . "include" 
                    REQUIRES driver sdcard volume)