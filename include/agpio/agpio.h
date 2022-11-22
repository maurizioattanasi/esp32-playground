/** --------------------------------
 * agpio.h
 * Created on Tue Nov 22 2022
 *
 * Maurizio Attanasi
 *
 * Copyright (c) 2022 ATech
 * --------------------------------
 **/

#pragma once

#include "driver/gpio.h"

namespace AGPIO
{
    class GpioBase
    {
    protected:
        gpio_num_t _pin;
        bool _activeLow;

    private:
        /* data */
    };

    class GpioInput : GpioBase
    {
    private:
        esp_err_t _init(const gpio_num_t pin, const bool activeLow);

    public:
        GpioInput(const gpio_num_t pin, const bool activeLow);
        GpioInput(const gpio_num_t pin);
        GpioInput(void);

    public:
        esp_err_t Init(const gpio_num_t pin, const bool activeLow);
        esp_err_t Init(const gpio_num_t pin);

    public:
        int Read(void);
    };

    class GpioOutput : public GpioBase
    {
    private:
        int _level = 0;
        esp_err_t _init(const gpio_num_t pin, const bool activeLow);

    public:
        GpioOutput(const gpio_num_t pin, const bool activeLow);
        GpioOutput(const gpio_num_t pin);
        GpioOutput(void);

    public:
        esp_err_t Init(const gpio_num_t pin, const bool activeLow);
        esp_err_t Init(const gpio_num_t pin);

    public:
        esp_err_t On(void);
        esp_err_t Off(void);
        esp_err_t Toggle(void);
        esp_err_t SetLevel(int level);
    };
}