# STM32-System
This repository contains a layered architecture drivers of STM32 (ARM Cortex M3) 

## Note:
<p>Every MCAL & HAL driver has 4 files (1 source file and 3 header files)<br>
<em><strong>XYZ_program.c =></strong></em> This source file contains functions implementations.<br>
<em><strong>XYZ_interface.h =></strong></em> This header file contains public functions prototypes.<br>
<em><strong>XYZ_config.h =></strong></em> This header file contains peripheral pre-build configuations that user should select.<br>
<em><strong>XYZ_private.h =></strong></em> This header file contains peripheral registers (in case of MCAL) and private functions prototypes.<br><p>

## 01-LIB:
<p><em><strong>01-STD_TYPES.h =></strong></em> This header file contains user defined types that will be used in all drivers.<br>
<em><strong>02-BIT_MATH.h =></strong></em>This header file contains some bit manipulations that will be used in all drivers.</p>

## 02-MCAL:
<p><em><strong>01-RCC (Reset & Control Clock) =></strong></em> Select system clock, Enable & Disable Peripheral Clock.<br>
<em><strong>02-GPIO (General Purpose Input Output) =></strong></em> Controls pins configurations (Input, Output...etc) & Controls pins value.<br>
<em><strong>03-NVIC (Nested Vectored Interrupt Controller) =></strong></em> Controls all interrupts but manages only external interrupts.<br>
<em><strong>04-EXTI (External Interrupts) =></strong></em> Controls external interrupts.<br>
<em><strong>05-AFIO (Alternative Function Input Output) =></strong></em> Controls pins' alternative function configuration.<br>
<em><strong>06-STK (SysTick Timer) =></strong></em> 24-bit Count down timer.<br>
<em><strong>07-SPI (Serial Peripheral Interface) =></strong></em> Communication Protocol.<br>
<em><strong>08-UART (Universal Asynchronous Receiver Transmitter) =></strong></em> Communication Protocol.</p>

## 03-HAL:
<p><em><strong>01-SEVSEG (Seven Segement) =></strong></em> Seven Segement display interface.<br>
<em><strong>02-LED =></strong></em> LED interface.<br>
<em><strong>03-LEDMRX (LED Martix) =></strong></em> LED Martix display interface.<br>
<em><strong>04-IR (InfraRed) =></strong></em> NEC InfraRed Communciation Protocol.<br>
<em><strong>05-STP (Serial To Parallel) =></strong></em> Serial to parallel communication.<br>
<em><strong>06-TFT (Thin Film Transistor) =></strong></em> Thin Film Transistor display interface.</p>

## 04-SERVICES:
<p><em><strong>OS (Operating System) =></strong></em> Simple RTOS scheduler.</p>
