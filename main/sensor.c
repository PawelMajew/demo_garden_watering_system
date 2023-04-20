/*********************************************************************/
/*!
*   \file   sensor.c
*
*   \brief  Soil moisture sensor support.
*
*   \author Paweł Majewski
*
*/
/*********************************************************************/

#include "sensor.h"

/**********************************************************************
Local Function
**********************************************************************/
/*********************************************************************/
/*!
 * \brief  Converting data into percentages.
 *
 * \param  sample - data converted to percentages.
 * \param  in_min - minimum data input value.
 * \param  in_max - maximum data input value.
 * \param  out_min - minimum data output value.
 * \param  out_max - maximum data output value.
 *
 * \return Value in percent.
 *
 */
/*********************************************************************/
static int32_t mape(int32_t sample, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
    return (sample - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*********************************************************************/
/*!
 * \brief  Averaging the received data.
 *
 * \param  data - Pointer where the result is stored.
 *
 * \return None
 *
 */
/*********************************************************************/
static void averageResult(sensorData* data)
{
    int32_t tempData = 0;
    uint8_t sample = 0;
    uint8_t nrOfAvgValues = 10;

    for(sample = 0; sample < nrOfAvgValues; sample++)
    {
        sensorGetRawData(data);
        uint32_t value = data->rawData;
        tempData += value;
    }
    tempData = tempData / nrOfAvgValues;
    data->averageData = tempData;
}

/**********************************************************************
 Global Function
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
void sensorInit(void)
{
    adc1_config_width(ADC_WIDTH_BIT_11);
    adc1_config_channel_atten( ADC1_CHANNEL_0, ADC_ATTEN_DB_11);
}

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
void sensorGetRawData(sensorData* data)
{
    data->rawData = adc1_get_raw(ADC1_CHANNEL_0);
}

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
void sensorGetVoltageResult(sensorData* data)
{
    esp_adc_cal_characteristics_t adc_cal;

    esp_adc_cal_characterize( ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_11, 1100, &adc_cal);
    averageResult(data);
    data->voltage = esp_adc_cal_raw_to_voltage((data->averageData), &adc_cal);
}

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
void sensorGetPercentageResult(sensorData* data)
{
    uint8_t tempData = 0;
    
    averageResult(data);
    tempData = mape(data->averageData, 1530, 680, 0, 100);
    if (tempData >= 100)
    {
        tempData = 100;
    } 
    if (tempData <= 0)
    {
        tempData = 0;
    }

    data->percentageResult = tempData;
}