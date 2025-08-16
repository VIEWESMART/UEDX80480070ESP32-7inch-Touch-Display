import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import display, esp32
from esphome.const import CONF_ID

DEPENDENCIES = ["esp32"]
CODEOWNERS = ["@jtbnz"]
AUTO_LOAD = ["display"]

def validate_esp32_variant(config):
    """Validate that ESP32-S3 variant is being used."""
    if not esp32.get_esp32_variant() == esp32.const.VARIANT_ESP32S3:
        raise cv.Invalid("This component requires ESP32-S3 variant")
    return config

viewe_display_ns = cg.esphome_ns.namespace("viewe_display")
VieweDisplay = viewe_display_ns.class_(
    "VieweDisplay", display.DisplayBuffer
)