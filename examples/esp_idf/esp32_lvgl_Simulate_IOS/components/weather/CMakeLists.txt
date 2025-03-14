idf_component_register(SRCS "weather.c" ${SOURCES}
                    INCLUDE_DIRS . "include"
                    REQUIRES wifi json esp_http_client esp-tls)