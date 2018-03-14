/*
 * UARTproj.h
 *
 *  Created on: Mar 12, 2018
 *      Author: kaylak
 */

#ifndef UARTPROJ_H_
#define UARTPROJ_H_

uint32_t ClockSRCFreq;
void UART_CONFIG(void);
void MENU_DISPLAY(void);
void UART_send_byteA0(uint8_t data);
void UART_send_byteA0(uint8_t data);
void UART_send_A0(const uint8_t * data, uint32_t length);
void UART_send_A6(const uint8_t * data, uint32_t length);
void UART6_IRQHandler(void);
void UART0_IRQHandler(void);
void itoa(int n, char s[]);
void reverse(char s[]);

void TIMER_CONFIG(void);
void TimerA_0_IRQHandler();

#endif /* UARTPROJ_H_ */
