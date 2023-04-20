/*********************************************************************/
/*!
*   \file   sensor.h
*
*   \brief  Soil moisture sensor support.
*
*   \author Paweł Majewski
*
*/
/*********************************************************************/
#ifndef SENSOR_H
#define SENSOR_H

#include "driver/adc.h"
#include "esp_adc_cal.h"

/**********************************************************************
Data Types
**********************************************************************/
/* Space for read values from the sensor. */
typedef struct 
{
    uint32_t rawData;
    uint32_t averageData;
    uint8_t percentageResult;
    uint16_t voltage;
} sensorData;

/**********************************************************************
Function Declarations
**********************************************************************/
/*********************************************************************/
/*!
 * \brief  Sensor initialization.
 *
 * \param  None
 *
 * \return None
 *
 */
/*********************************************************************/
void sensorInit(void);

/*********************************************************************/
/*!
 * \brief  Reading raw data from the sensor.
 *
 * \param  data - Pointer where the result is stored.
 *
 * \return None
 *
 */
/*********************************************************************/
void sensorGetRawData(sensorData* data);

/*********************************************************************/
/*!
 * \brief  Converting of averaged data to a voltage value.
 *
 * \param  data - Pointer where the result is stored.
 *
 * \return None
 *
 */
/*********************************************************************/
void sensorGetVoltageResult(sensorData* data);

/*********************************************************************/
/*!
 * \brief  Converting of averaged data to a percentage value.
 *
 * \param  data - Pointer where the result is stored.
 *
 * \return None
 *
 */
/*********************************************************************/
void sensorGetPercentageResult(sensorData* data);

#endif /*SENSOR_H*/