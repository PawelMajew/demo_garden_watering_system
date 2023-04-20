#include <stdio.h>
#include "example_engine.h"

void app_main(void)
{
    sensorInit();
    servoInit();
    ledsGpioInit();

    while(1)
    {
        engine();
    }
}
