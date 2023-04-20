/*********************************************************************/
/*!
*   \file   example_engine.h
*
*   \brief  Example engine presenting the operation of the servo, led and 
*           soil moisture sensor.
*
*   \author Paweł Majewski
*
*/
/*********************************************************************/
#ifndef EXAMPLE_ENGINE_H
#define EXAMPLE_ENGINE_H

#include "sensor.h"
#include "servo.h"
#include "leds.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

/**********************************************************************
Function Declarations
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
void engine(void);

#endif /*EXAMPLE_ENGINE_H*/