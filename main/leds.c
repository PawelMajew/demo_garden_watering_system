/*********************************************************************/
/*!
*   \file   leds.c
*
*   \brief  Led service.
*
*   \author Paweł Majewski
*
*/
/*********************************************************************/

#include "leds.h"
#include "esp_log.h"

/**********************************************************************
Macros
**********************************************************************/
#define TAG "leds"

/**********************************************************************
Function
**********************************************************************/
/*********************************************************************/
/*!
 * \brief  Initialization of selected LEDs
 *
 * \param  None
 *
 * \return None
 *
 */
/*********************************************************************/
void ledsGpioInit(void)
{
    esp_rom_gpio_pad_select_gpio(lowHydrationStatus);
    gpio_set_direction(lowHydrationStatus, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(moderateHydrationStatus);
    gpio_set_direction(moderateHydrationStatus, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(goodHydrationStatus);
    gpio_set_direction(goodHydrationStatus, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(servoStatus);
    gpio_set_direction(servoStatus, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(wifiUiStatus);
    gpio_set_direction(wifiUiStatus, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(wifiNetworkStatus);
    gpio_set_direction(wifiNetworkStatus, GPIO_MODE_OUTPUT);

}

/*********************************************************************/
/*!
 * \brief  Turn on the selected diode
 *
 * \param  led - selected diode
 *
 * \return None
 *
 */
/*********************************************************************/
void TurnOnLed(ledRole led)
{
    gpio_set_level(led, 1);
    ESP_LOGI(TAG, "led on");
}

/*********************************************************************/
/*!
 * \brief  Turn off the selected diode
 *
 * \param  led - selected diode
 *
 * \return None
 *
 */
/*********************************************************************/
void TurnOffLed(ledRole led)
{
    gpio_set_level(led, 0);
    ESP_LOGI(TAG, "led off");
}