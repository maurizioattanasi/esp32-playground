/** --------------------------------
 * driver.h
 * Created on Wed Nov 16 2022
 *
 * Maurizio Attanasi
 *
 * Copyright (c) 2022 ATech
 * --------------------------------
 **/

#pragma once

namespace esp32Playground
{
    class Driver
    {
    private:
        bool _state;
        
    public:
        Driver(/* args */);
        ~Driver();

    public:
        void Init(void);
        void SetState(bool state);
        bool GetState(void);
    };
}
