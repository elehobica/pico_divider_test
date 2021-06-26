/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <cstdio>
#include <cstdlib>
#include "pico/stdlib.h"
#include "hardware/divider.h"

static repeating_timer_t timer;
static const uint32_t SampRateHz = 44100;
static const float SampRateHz_div_1000 = 44.1;
uint32_t dummy = 0;

static inline uint32_t _millis(void)
{
    return to_ms_since_boot(get_absolute_time());
}

bool timer_callback(repeating_timer_t *rt) {
    uint32_t millis;
    uint32_t sec;
    for (int i = 0; i < 100; i++) {
        uint32_t millis_ref = (rand() & 0x007fffff) + 1;
        uint32_t samplesPlayed = (uint32_t) ((float) millis_ref * SampRateHz_div_1000);

        //dummy += (uint32_t) ((uint64_t) samplesPlayed * 1000 / SampRateHz);
        dummy += (uint32_t) ((float) samplesPlayed * 1000.0f / (float) SampRateHz); // seems only float division affects to 64bit division in main badly
        //dummy += (samplesPlayed ) / SampRateHz;
    }
    return true; // keep repeating
}

int main()
{
    srand(0);
    stdio_init_all();
    sleep_ms(1000);

    puts("START");
    if (!add_repeating_timer_us(-1000, timer_callback, nullptr, &timer)) {
        return 0;
    }

    int count = 0;
    while (true) {
        //uint32_t millis_ref = _millis(); // failure occurs only when dividend is large enough
        uint32_t millis_ref = (rand() & 0x007fffff) + 1;
        uint32_t samplesPlayed = (uint32_t) ((float) millis_ref * SampRateHz_div_1000);
        uint32_t millis = (uint32_t) ((uint64_t) samplesPlayed * 1000 / SampRateHz);

        if (millis < millis_ref - 1 || millis > millis_ref + 1) {
            printf("ERROR [calc_64bit][%d] samplesPlayed = %lu, millis_ref = %d, millis = %lu\n", count, samplesPlayed, millis_ref, millis);
        }
        count++;
        if (_millis() > 10 * 1000) { break; }
    }

    printf("dummy = %d\n", dummy); // Not to delete dummy by optimization
    printf("END\n");
    return 0;
}
