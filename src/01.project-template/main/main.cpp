#include <stdio.h>

#include "esp_log.h"

#define TAG "ESP-PLAYGROUND"

extern "C" void app_main(void)
{
    ESP_LOGI(TAG, "Have fun!");
}