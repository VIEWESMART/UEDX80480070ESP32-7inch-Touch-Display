import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import display
from esphome.const import (
    CONF_AUTO_CLEAR_ENABLED,
    CONF_BRIGHTNESS,
    CONF_ID,
    CONF_LAMBDA,
    CONF_PAGES,
)
from esphome import pins
from . import viewe_display_ns, VieweDisplay

CONF_BACKLIGHT_PIN = "backlight_pin"

CONFIG_SCHEMA = cv.All(
    display.FULL_DISPLAY_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(VieweDisplay),
            cv.Optional(CONF_AUTO_CLEAR_ENABLED, default=True): cv.boolean,
            cv.Optional(CONF_BACKLIGHT_PIN): pins.gpio_output_pin_schema,
            cv.Optional(CONF_BRIGHTNESS, default=1.0): cv.percentage,
        }
    ).extend(cv.COMPONENT_SCHEMA),
    cv.has_at_most_one_key(CONF_LAMBDA, CONF_PAGES),
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await display.register_display(var, config)

    if CONF_AUTO_CLEAR_ENABLED in config:
        cg.add(var.set_auto_clear(config[CONF_AUTO_CLEAR_ENABLED]))

    if CONF_BACKLIGHT_PIN in config:
        pin = await cg.gpio_pin_expression(config[CONF_BACKLIGHT_PIN])
        cg.add(var.set_backlight_pin(pin))
    
    if CONF_BRIGHTNESS in config:
        cg.add(var.set_brightness(config[CONF_BRIGHTNESS]))

    if CONF_LAMBDA in config:
        lambda_ = await cg.process_lambda(
            config[CONF_LAMBDA], [(display.DisplayRef, "it")], return_type=cg.void
        )
        cg.add(var.set_writer(lambda_))