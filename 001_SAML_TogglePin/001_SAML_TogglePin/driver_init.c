/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

void system_init(void)
{
	init_mcu();

	// GPIO on PA00

	gpio_set_pin_level(PA00,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA00, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA00, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA01

	gpio_set_pin_level(PA01,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA01, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA01, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA02

	gpio_set_pin_level(PA02,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA02, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA02, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA03

	gpio_set_pin_level(PA03,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA03, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA03, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA04

	gpio_set_pin_level(PA04,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA04, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA04, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA05

	// Set pin direction to input
	gpio_set_pin_direction(PA05, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PA05,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA05, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA08

	gpio_set_pin_level(PA08,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA08, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA08, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA14

	gpio_set_pin_level(PA14,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA14, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA14, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA15

	gpio_set_pin_level(PA15,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA15, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA15, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA16

	gpio_set_pin_level(PA16,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA16, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA16, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA17

	gpio_set_pin_level(PA17,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA17, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA17, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA18

	gpio_set_pin_level(PA18,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA18, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA18, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA19

	gpio_set_pin_level(PA19,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA19, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA19, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA22

	gpio_set_pin_level(PA22,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA22, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA22, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA23

	// Set pin direction to input
	gpio_set_pin_direction(PA23, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PA23,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(PA23, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA30

	gpio_set_pin_level(PA30,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA30, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA30, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA31

	gpio_set_pin_level(PA31,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA31, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA31, GPIO_PIN_FUNCTION_OFF);
}
