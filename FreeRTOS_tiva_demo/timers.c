/*
 * timers.c
 *
 *  Created on: Mar 13, 2018
 *      Author: kaylak
 */

#include "FPS.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "UARTproj.h"

void TIMER_CONFIG(void){
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    ROM_TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    ROM_TimerLoadSet(TIMER0_BASE, TIMER_A, ClockSRCFreq);  /* Set load value to the clock source frequency so we will interrupt every 1 second*/
    ROM_IntEnable(INT_TIMER0A);
    ROM_TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT /*TIMERA match interrupt*/);

}

void TimerA_0_IRQHandler() {
    ROM_TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    ROM_IntMasterDisable();
    UART_send_A0("Please press finger\n", 20);
    ROM_IntMasterEnable();
}
