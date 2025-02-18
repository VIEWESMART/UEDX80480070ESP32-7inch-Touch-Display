cmake_minimum_required(VERSION 3.12.4)

# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# if(NOT ESP_PLATFORM)
#   project(lvgl LANGUAGES C CXX ASM HOMEPAGE_URL https://github.com/lvgl/lvgl)
# endif()

# set(LVGL_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

# if(ESP_PLATFORM)
#   include(${CMAKE_CURRENT_LIST_DIR}/env_support/cmake/esp.cmake)
# elseif(ZEPHYR_BASE)
#   include(${CMAKE_CURRENT_LIST_DIR}/env_support/cmake/zephyr.cmake)
# elseif(MICROPY_DIR)
#   include(${CMAKE_CURRENT_LIST_DIR}/env_support/cmake/micropython.cmake)
# else()
#   include(${CMAKE_CURRENT_LIST_DIR}/env_support/cmake/custom.cmake)
# endif()

# #[[
#     unfortunately CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS does not work for global data. 
#     for global data we still need decl specs.
#     Check out the docs to learn more about the limitations of CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS
#     https://cmake.org/cmake/help/latest/prop_tgt/WINDOWS_EXPORT_ALL_SYMBOLS.html#prop_tgt:WINDOWS_EXPORT_ALL_SYMBOLS

#     For all compiled sources within the library (i.e. basically all lvgl files) we need to use dllexport.
#     For all compiled sources from outside the library (i.e. files which include lvgl headers) we need to use dllimport.
#     We can do this by using CMakes INTERFACE and PRIVATE keyword.
#   ]]
# if (MSVC)
#   target_compile_definitions(lvgl
#     INTERFACE LV_ATTRIBUTE_EXTERN_DATA=__declspec\(dllimport\)
#     PRIVATE LV_ATTRIBUTE_EXTERN_DATA=__declspec\(dllexport\)
#   )
# endif()

cmake_minimum_required(VERSION 3.12.4)

# if(NOT ESP_PLATFORM)
#   project(lvgl HOMEPAGE_URL https://github.com/lvgl/lvgl)
# endif()

# set(LVGL_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

# if(ESP_PLATFORM)
#   include(${CMAKE_CURRENT_LIST_DIR}/cmake/esp.cmake)
# elseif(ZEPHYR_BASE)
#   include(${CMAKE_CURRENT_LIST_DIR}/cmake/zephyr.cmake)
# elseif(MICROPY_DIR)
#   include(${CMAKE_CURRENT_LIST_DIR}/cmake/micropython.cmake)
# else()
#   include(${CMAKE_CURRENT_LIST_DIR}/cmake/custom.cmake)
# endif()

idf_component_register(
    SRC_DIRS
        "src"
        "src/stdlib"
        "src/tick"
        "src/indev"
        "src/display"
        "src/core"
        "src/draw"
        "src/font"
        # "src/drivers"
        # "src/drivers/display"
        "src/drivers/display/drm"
        "src/drivers/display/fb"
        "src/drivers/display/ili9341"
        "src/drivers/display/lcd"
        "src/drivers/display/st7735"
        "src/drivers/display/st7789"
        "src/drivers/display/st7796"
        "src/drivers/display/tft_espi"
        "src/drivers/evdev"
        "src/drivers/nuttx"
        "src/drivers/sdl"
        "src/drivers/windows"
        "src/drivers/x11"
        "src/misc"
        "src/misc/cache"
        # "src/libs"
        "src/libs/barcode"
        "src/libs/bin_decoder"
        "src/libs/bmp"
        "src/libs/ffmpeg"
        "src/libs/freetype"
        "src/libs/gif"
        "src/libs/libjpeg_turbo"
        "src/libs/libpng"
        "src/libs/lodepng"
        "src/libs/lz4"
        "src/libs/qrcode"
        "src/libs/rle"
        "src/libs/rlottie"
        "src/libs/thorvg"
        "src/libs/tiny_ttf"
        "src/libs/tjpgd"
        "src/libs/fsdrv"
        "src/osal"
        # "src/others"
        "src/others/file_explorer"
        "src/others/fragment"
        "src/others/gridnav"
        "src/others/ime"
        "src/others/imgfont"
        "src/others/monkey"
        "src/others/observer"
        "src/others/snapshot"
        "src/others/sysmon"
        "src/others/vg_lite_tvg"
        "src/stdlib"
        "src/stdlib/builtin"
        "src/stdlib/clib"
        "src/stdlib/micropython"
        "src/stdlib/rtthread"
        "src/themes"
        "src/themes/default"
        "src/themes/mono"
        "src/themes/simple"
        "src/layouts"
        "src/draw/sw"
        # "src/draw/sw/arm2d"
        "src/draw/sw/blend"
        # "src/draw/sw/blend/arm2d"
        "src/draw/sw/blend/neon"
        # "src/draw/nxp"
        "src/draw/nxp/pxp"
        "src/draw/nxp/vglite"
        # "src/draw/renesas"
        "src/draw/renesas/dave2d"
        "src/draw/sdl"
        "src/draw/vg_lite"
        "src/layouts/flex"
        "src/layouts/grid"
        # "src/widgets"
        "src/widgets/animimage"
        "src/widgets/arc"
        "src/widgets/bar"
        "src/widgets/button"
        "src/widgets/buttonmatrix"
        "src/widgets/calendar"
        "src/widgets/canvas"
        "src/widgets/chart"
        "src/widgets/checkbox"
        "src/widgets/dropdown"
        "src/widgets/image"
        "src/widgets/imagebutton"
        "src/widgets/keyboard"
        "src/widgets/label"
        "src/widgets/led"
        "src/widgets/line"
        "src/widgets/list"
        "src/widgets/menu"
        "src/widgets/msgbox"
        "src/widgets/objx_templ"
        "src/widgets/roller"
        "src/widgets/scale"
        "src/widgets/slider"
        "src/widgets/span"
        "src/widgets/spinbox"
        "src/widgets/spinner"
        "src/widgets/switch"
        "src/widgets/table"
        "src/widgets/tabview"
        "src/widgets/textarea"
        "src/widgets/tileview"
        "src/widgets/win"
        "porting"
        "demos"
        "demos/benchmark"
        "demos/benchmark/assets"
        "demos/flex_layout"
        "demos/keypad_encoder"
        "demos/multilang"
        "demos/multilang/assets"
        "demos/music"
        "demos/music/assets"
        "demos/render"
        "demos/render/assets"
        "demos/scroll"
        "demos/stress"
        # "demos/stress/assets"
        "demos/transform"
        "demos/transform/assets"
        "demos/widgets"
        "demos/widgets/assets"

    INCLUDE_DIRS
        "."
        "src"
        "src/stdlib"
        "src/tick"
        "src/indev"
        "src/display"
        "src/core"
        "src/draw"
        "src/font"
        "src/drivers"
        "src/misc"
        "src/misc/cache"
        "src/libs"
        "src/osal"
        "src/others"
        "src/others/file_explorer"
        "src/others/fragment"
        "src/others/gridnav"
        "src/others/ime"
        "src/others/imgfont"
        "src/others/monkey"
        "src/others/observer"
        "src/others/snapshot"
        "src/others/sysmon"
        "src/others/vg_lite_tvg"
        "src/stdlib"
        "src/stdlib/builtin"
        "src/stdlib/clib"
        "src/stdlib/micropython"
        "src/stdlib/rtthread"
        "src/themes"
        "src/themes/default"
        "src/themes/mono"
        "src/themes/simple"
        "src/widgets"
        "src/layouts"
        "src/draw/sw"
        "src/draw/sw/arm2d"
        "src/draw/sw/blend"
        "src/draw/sw/blend/arm2d"
        "src/draw/sw/blend/neon"
        "src/draw/nxp"
        "src/draw/nxp/pxp"
        "src/draw/nxp/vglite"
        "src/draw/renesas"
        "src/draw/renesas/dave2d"
        "src/draw/sdl"
        "src/draw/vg_lite"
        "src/drivers/display"
        "src/drivers/display/drm"
        "src/drivers/display/fb"
        "src/drivers/display/ili9341"
        "src/drivers/display/lcd"
        "src/drivers/display/st7735"
        "src/drivers/display/st7789"
        "src/drivers/display/st7796"
        "src/drivers/display/tft_espi"
        "src/drivers/evdev"
        "src/drivers/nuttx"
        "src/drivers/sdl"
        "src/drivers/windows"
        "src/drivers/x11"
        "src/layouts/flex"
        "src/layouts/grid"
        "src/libs/barcode"
        "src/libs/bin_decoder"
        "src/libs/bmp"
        "src/libs/ffmpeg"
        "src/libs/freetype"
        "src/libs/gif"
        "src/libs/libjpeg_turbo"
        "src/libs/libpng"
        "src/libs/lodepng"
        "src/libs/lz4"
        "src/libs/qrcode"
        "src/libs/rle"
        "src/libs/rlottie"
        "src/libs/thorvg"
        "src/libs/tiny_ttf"
        "src/libs/tjpgd"
        "src/libs/fsdrv"
        "src/widgets/animimage"
        "src/widgets/arc"
        "src/widgets/bar"
        "src/widgets/button"
        "src/widgets/buttonmatrix"
        "src/widgets/calendar"
        "src/widgets/canvas"
        "src/widgets/chart"
        "src/widgets/checkbox"
        "src/widgets/dropdown"
        "src/widgets/image"
        "src/widgets/imagebutton"
        "src/widgets/keyboard"
        "src/widgets/label"
        "src/widgets/led"
        "src/widgets/line"
        "src/widgets/list"
        "src/widgets/menu"
        "src/widgets/msgbox"
        "src/widgets/objx_templ"
        "src/widgets/roller"
        "src/widgets/scale"
        "src/widgets/slider"
        "src/widgets/span"
        "src/widgets/spinbox"
        "src/widgets/spinner"
        "src/widgets/switch"
        "src/widgets/table"
        "src/widgets/tabview"
        "src/widgets/textarea"
        "src/widgets/tileview"
        "src/widgets/win"
        "porting"
        "demos"
        "demos/benchmark"
        "demos/benchmark/assets"
        "demos/flex_layout"
        "demos/keypad_encoder"
        "demos/multilang"
        "demos/multilang/assets"
        "demos/music"
        "demos/music/assets"
        "demos/render"
        "demos/render/assets"
        "demos/scroll"
        "demos/stress"
        "demos/transform"
        "demos/transform/assets"
        "demos/widgets"
        "demos/widgets/assets"
        
    REQUIRES
    # lvgl_esp32_drivers
        driver
        spiffs
        esp_common 
        log
        esp_timer
        lvgl
        )

        

