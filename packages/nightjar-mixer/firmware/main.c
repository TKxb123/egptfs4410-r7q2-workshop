/*
 * Nightjar Eight-Channel Mixer - main control firmware (Rev C)
 * Released with the production design package.
 */

#include "board.h"

static volatile uint32_t g_tick;

void board_tick_isr(void)
{
    g_tick++;
}

static void panel_refresh(void)
{
    /* nightjar-mixer: refresh the panel latches from the shadow registers */
    PANEL_LATCH = panel_shadow;
}

int main(void)
{
    board_init();
    panel_init();
    for (;;) {
        if ((g_tick % 10u) == 0u) {
            panel_refresh();
        }
        board_idle();
    }
}
