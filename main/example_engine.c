/*********************************************************************/
/*!
*   \file   example_engine.c
*
*   \brief  Example engine presenting the operation of the servo, led and 
*           soil moisture sensor.
*
*   \author Paweł Majewski
*
*/
/*********************************************************************/

#include "example_engine.h"

/**********************************************************************
Function
**********************************************************************/
/*********************************************************************/
/*!
 * \brief  Example engine presenting the operation of the servo, led and 
 *         soil moisture sensor.
 *
 * \param  None
 *
 * \return None
 *
 */
/*********************************************************************/
void engine(void)
{
    sensorData data;
    sensorGetPercentageResult(&data);
    printf("Percentages: %d %%\n",data.percentageResult);
    if ( data.percentageResult <= 10)
    {
        servoDeg180();
        TurnOnLed(servoStatus);
    } else
    {
        servoDeg0();
        TurnOffLed(servoStatus);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}