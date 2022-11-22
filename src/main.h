
#pragma once

#include "agpio.h"

class Main final
{
public:
    void Run(void);

public:
    AGPIO::GpioOutput _led{GPIO_NUM_2};
    AGPIO::GpioInput _button{GPIO_NUM_21};
};
