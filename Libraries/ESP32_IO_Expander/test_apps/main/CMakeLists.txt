idf_component_register(SRCS "test_app_main.cpp")

target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-missing-field-initializers)
