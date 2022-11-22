/** --------------------------------
 * main.cpp
 * Created on Sat Nov 12 2022
 *
 * Maurizio Attanasi
 *
 * Copyright (c) 2022 ATech
 * --------------------------------
 **/

#include <iostream>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "driver.h"

#define TAG "ESP-PLAYGROUND"

using namespace esp32Playground;
using namespace std;

Driver _driver;

extern "C" void app_main(void)
{
    _driver.Init();

    while (1)
    {
        bool state = _driver.GetState();

        _driver.SetState(!state);

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}