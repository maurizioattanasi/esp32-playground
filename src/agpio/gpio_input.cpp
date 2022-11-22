/** --------------------------------
 * gpio_input.cpp
 * Created on Tue Nov 22 2022
 *
 * Maurizio Attanasi
 *
 * Copyright (c) 2022 ATech
 * --------------------------------
 **/

#include "agpio.h"
#include "esp_log.h"

#define TAG "GpioInput"

namespace AGPIO
{
    esp_err_t GpioInput::_init(const gpio_num_t pin, const bool activeLow)
    {
        esp_err_t status{ESP_OK};

        gpio_config_t cfg;
        cfg.pin_bit_mask = 1ULL << pin;
        cfg.mode = GPIO_MODE_INPUT;
        cfg.pull_up_en = GPIO_PULLUP_DISABLE;
        cfg.pull_down_en = GPIO_PULLDOWN_DISABLE;
        cfg.intr_type = GPIO_INTR_POSEDGE;

        status |= gpio_config(&cfg);

        return status;
    }
    GpioInput::GpioInput(const gpio_num_t pin, const bool activeLow)
    {
        _init(pin, activeLow);
    }
    GpioInput::GpioInput(const gpio_num_t pin)
    {
        _init(pin, false);
    }
    GpioInput::GpioInput(void) {}

    esp_err_t GpioInput::Init(const gpio_num_t pin, const bool activeLow)
    {
        return _init(pin, activeLow);
    }
    esp_err_t GpioInput::Init(const gpio_num_t pin)
    {
        return _init(pin, false);
    }

    int GpioInput::Read(void)
    {
        int level = _activeLow ? !gpio_get_level(_pin) : gpio_get_level(_pin);
        if (level)
            ESP_LOGD(TAG, "Read::ON");
        else
            ESP_LOGD(TAG, "Read::OFF");
        return level;
    }
}