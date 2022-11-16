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

#include "driver.h"

using namespace esp32Playground;
using namespace std;

Driver _driver;

extern "C" void app_main(void)
{
    int i = 0;
    _driver.Init();

    while (1)
    {
        bool state = _driver.GetState();

        cout << "Have fun! " << i++ << endl;

        if (state)
            cout << "ON" << endl;
        else
            cout << "OFF" << endl;

        _driver.SetState(!state);

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}