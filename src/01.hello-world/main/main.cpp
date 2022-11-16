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
#include"freertos/task.h"

extern "C" void app_main(void)
{    
    int i = 0;
    while (1)
    {
        std::cout << "Have fun! " << i++ << std::endl;
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }    
}