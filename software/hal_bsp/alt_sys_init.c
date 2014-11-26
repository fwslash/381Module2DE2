/*
 * alt_sys_init.c - HAL initialization source
 *
 * Machine generated for CPU 'nios2_system' in SOPC Builder design 'nios2_system'
 * SOPC Builder design path: C:/Users/Harry/Documents/UBC/EECE381/Module2/381Module2DE2/nios2_system.sopcinfo
 *
 * Generated: Thu Nov 20 16:26:44 PST 2014
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#include "system.h"
#include "sys/alt_irq.h"
#include "sys/alt_sys_init.h"

#include <stddef.h>

/*
 * Device headers
 */

#include "altera_nios2_qsys_irq.h"
#include "Altera_UP_SD_Card_Avalon_Interface.h"
#include "altera_avalon_jtag_uart.h"
#include "altera_avalon_timer.h"
#include "altera_up_avalon_audio.h"
#include "altera_up_avalon_audio_and_video_config.h"
#include "altera_up_avalon_character_lcd.h"
#include "altera_up_avalon_ps2.h"
#include "altera_up_avalon_usb.h"
#include "altera_up_avalon_video_character_buffer_with_dma.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"

/*
 * Allocate the device storage
 */

ALTERA_NIOS2_QSYS_IRQ_INSTANCE ( NIOS2_SYSTEM, nios2_system);
ALTERA_AVALON_JTAG_UART_INSTANCE ( JTAG, JTAG);
ALTERA_AVALON_TIMER_INSTANCE ( SDCARD_TIMER, sdcard_timer);
ALTERA_AVALON_TIMER_INSTANCE ( TIMER_0, timer_0);
ALTERA_UP_AVALON_AUDIO_AND_VIDEO_CONFIG_INSTANCE ( AUDIO_AND_VIDEO_CONFIG_0, audio_and_video_config_0);
ALTERA_UP_AVALON_AUDIO_INSTANCE ( AUDIO_0, audio_0);
ALTERA_UP_AVALON_CHARACTER_LCD_INSTANCE ( CHARACTER_LCD_0, character_lcd_0);
ALTERA_UP_AVALON_PS2_INSTANCE ( PS2_0, ps2_0);
ALTERA_UP_AVALON_USB_INSTANCE ( USB_0, usb_0);
ALTERA_UP_AVALON_VIDEO_CHARACTER_BUFFER_WITH_DMA_INSTANCE ( VIDEO_CHARACTER_BUFFER_WITH_DMA_0, video_character_buffer_with_dma_0);
ALTERA_UP_AVALON_VIDEO_PIXEL_BUFFER_DMA_INSTANCE ( VIDEO_PIXEL_BUFFER_DMA, video_pixel_buffer_dma);
ALTERA_UP_SD_CARD_AVALON_INTERFACE_INSTANCE ( ALTERA_UP_SD_CARD_AVALON_INTERFACE_0, Altera_UP_SD_Card_Avalon_Interface_0);

/*
 * Initialize the interrupt controller devices
 * and then enable interrupts in the CPU.
 * Called before alt_sys_init().
 * The "base" parameter is ignored and only
 * present for backwards-compatibility.
 */

void alt_irq_init ( const void* base )
{
    ALTERA_NIOS2_QSYS_IRQ_INIT ( NIOS2_SYSTEM, nios2_system);
    alt_irq_cpu_enable_interrupts();
}

/*
 * Initialize the non-interrupt controller devices.
 * Called after alt_irq_init().
 */

void alt_sys_init( void )
{
    ALTERA_AVALON_TIMER_INIT ( SDCARD_TIMER, sdcard_timer);
    ALTERA_AVALON_TIMER_INIT ( TIMER_0, timer_0);
    ALTERA_AVALON_JTAG_UART_INIT ( JTAG, JTAG);
    ALTERA_UP_AVALON_AUDIO_AND_VIDEO_CONFIG_INIT ( AUDIO_AND_VIDEO_CONFIG_0, audio_and_video_config_0);
    ALTERA_UP_AVALON_AUDIO_INIT ( AUDIO_0, audio_0);
    ALTERA_UP_AVALON_CHARACTER_LCD_INIT ( CHARACTER_LCD_0, character_lcd_0);
    ALTERA_UP_AVALON_PS2_INIT ( PS2_0, ps2_0);
    ALTERA_UP_AVALON_USB_INIT ( USB_0, usb_0);
    ALTERA_UP_AVALON_VIDEO_CHARACTER_BUFFER_WITH_DMA_INIT ( VIDEO_CHARACTER_BUFFER_WITH_DMA_0, video_character_buffer_with_dma_0);
    ALTERA_UP_AVALON_VIDEO_PIXEL_BUFFER_DMA_INIT ( VIDEO_PIXEL_BUFFER_DMA, video_pixel_buffer_dma);
    ALTERA_UP_SD_CARD_AVALON_INTERFACE_INIT ( ALTERA_UP_SD_CARD_AVALON_INTERFACE_0, Altera_UP_SD_Card_Avalon_Interface_0);
}