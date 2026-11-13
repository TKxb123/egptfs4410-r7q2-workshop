#ifndef NIGHTJAR_MIXER_BOARD_H
#define NIGHTJAR_MIXER_BOARD_H

/* Nightjar Eight-Channel Mixer - Rev C board map */

#define MCU_CLOCK_HZ      48000000u
#define PANEL_LATCH       (*(volatile uint32_t *)0x40010C10u)
#define PANEL_STATUS      (*(volatile uint32_t *)0x40010C14u)

void board_init(void);
void board_idle(void);
void panel_init(void);

#endif
