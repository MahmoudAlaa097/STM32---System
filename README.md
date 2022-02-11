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
<p><em><strong>02-GPIO (General Purpose Input Output) =></strong></em> Controls pins configurations (Input, Output...etc) & Controls pins value.</p>
