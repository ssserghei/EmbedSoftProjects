#include <atmel_start.h>

#define  LED_Green PIN_PA00
#define  LED_Blue PIN_PA22
#define  button_pin PIN_PA23


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	/* Replace with your application code */
	while (1) {
		delay_ms(100);
		gpio_toggle_pin_level(LED_Green);
		if(gpio_get_pin_level(button_pin))
		{
			gpio_set_pin_level(LED_Blue, 1);			
		} else
			{
				gpio_set_pin_level(LED_Blue, 0);
			}
		
	}
}
