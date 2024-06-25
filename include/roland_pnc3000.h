#ifndef GRBL_ROLAND_PNC3000_H
#define GRBL_ROLAND_PNC3000_H

#include "grbl.h"

// Define feed rate output pins
#define FEED_RATE_DDR   DDRC
#define FEED_RATE_PORT  PORTC
#define FEED_RATE_BIT0   0 // Analog pins, used as outputs
#define FEED_RATE_BIT1   1
#define FEED_RATE_BIT2   2
#define FEED_RATE_BIT3   3

#define FEED_RATE_MASK ((1<<FEED_RATE_BIT0)|(1<<FEED_RATE_BIT1)|(1<<FEED_RATE_BIT2)|(1<<FEED_RATE_BIT3))

void panel_init();

void update_feed_rate(uint16_t feed_rate);

#endif //GRBL_ROLAND_PNC3000_H
