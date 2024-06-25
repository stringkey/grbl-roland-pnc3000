#include "roland_pnc3000.h"

void panel_init()
{
    FEED_RATE_PORT = (FEED_RATE_PORT & ~FEED_RATE_MASK);
    FEED_RATE_DDR |= FEED_RATE_MASK;
}

void update_feed_rate(uint16_t feed_rate)
{
    FEED_RATE_PORT = (FEED_RATE_PORT & ~FEED_RATE_MASK) | (feed_rate & FEED_RATE_MASK);
}
