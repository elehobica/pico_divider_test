/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <cstdio>
#include <cstdlib>
#include "pico/stdlib.h"
#include "hardware/sync.h"
#include "hardware/divider.h"

static repeating_timer_t timer;
static const uint32_t TIMER_HZ = 1000;
static const uint32_t SampRateHz = 44100;
static const float SampRateHz_div_1000 = 44.1;
static const int loopCount = 1000;
static bool p_en = false;
spin_lock_t *spin_lock;
uint32_t dummy = 0;

static inline uint32_t _micros(void)
{
    return to_us_since_boot(get_absolute_time());
}

static inline uint32_t _millis(void)
{
    return to_ms_since_boot(get_absolute_time());
}

bool timer_callback(repeating_timer_t *rt) {
    uint32_t millis;
    for (int i = 0; i < 100; i++) {
        /*
        uint32_t save = spin_lock_blocking(spin_lock);
        millis = hw_divider_u32_quotient_inlined(rand(), SampRateHz);
        spin_unlock(spin_lock, save);
        */
        millis = (uint32_t) ((uint64_t) rand() * 1000 / SampRateHz);
        dummy += millis;
        millis = (uint32_t) ((float) rand() * 1000.0f / (float) SampRateHz);
        dummy += millis;
    }
    return true; // keep repeating
}

uint32_t calc_64bit(uint32_t samplesPlayed)
{
    uint millis = 0;
    uint32_t start = _micros();
    //uint32_t save = spin_lock_blocking(spin_lock);
    millis = (uint32_t) ((uint64_t) samplesPlayed * 1000 / SampRateHz);
    //spin_unlock(spin_lock, save);
    uint32_t diff = _micros() - start;
    if (p_en) printf("[calc_64bit] diff = %lu us\n", diff);
    return millis;
}

uint32_t calc_float(uint32_t samplesPlayed)
{
    uint millis = 0;
    uint32_t start = _micros();
    //uint32_t save = spin_lock_blocking(spin_lock);
    millis = (uint32_t) ((float) samplesPlayed * 1000.0f / (float) SampRateHz);
    //spin_unlock(spin_lock, save);
    uint32_t diff = _micros() - start;
    if (p_en) printf("[calc_float] diff = %lu us\n", diff);
    return millis;
}

uint32_t calc_divider(uint32_t samplesPlayed)
{
    uint32_t sec;
    uint32_t modulo;
    uint32_t millis;
    uint32_t start = _micros();
    //uint32_t save = spin_lock_blocking(spin_lock);
    sec = hw_divider_u32_quotient_inlined(samplesPlayed, SampRateHz);
    modulo = hw_divider_u32_remainder_inlined(samplesPlayed, SampRateHz);
    millis = hw_divider_u32_quotient_inlined(modulo * 1000, SampRateHz);
    //spin_unlock(spin_lock, save);
    millis += sec * 1000;
    uint32_t diff = _micros() - start;
    if (p_en) printf("[calc_divider] diff = %lu us\n", diff);
    return millis;
}

#if 0
uint32_t calc_64bit_multi(uint32_t samplesPlayed)
{
    uint millis = 0;
    uint32_t start = _micros();
    for (int i = 0; i < loopCount; i++) {
        samplesPlayed = rand();
        millis += (uint32_t) ((uint64_t) samplesPlayed * 1000 / SampRateHz);
    }
    uint32_t diff = _micros() - start;
    printf("[calc_64bit] diff = %lu us\n", diff);
    return millis;
}

uint32_t calc_float_multi(uint32_t samplesPlayed)
{
    uint millis = 0;
    uint32_t start = _micros();
    for (int i = 0; i < loopCount; i++) {
        samplesPlayed = rand();
        millis += (uint32_t) ((float) samplesPlayed * 1000.0f / (float) SampRateHz);
    }
    uint32_t diff = _micros() - start;
    printf("[calc_float] diff = %lu us\n", diff);
    return millis;
}

uint32_t calc_divider_multi(uint32_t samplesPlayed)
{
    uint32_t sec;
    uint32_t modulo;
    uint32_t millis;
    uint32_t start = _micros();
    for (int i = 0; i < loopCount; i++) {
        samplesPlayed = rand();
        sec = hw_divider_u32_quotient_inlined(samplesPlayed, SampRateHz);
        modulo = hw_divider_u32_remainder_inlined(samplesPlayed, SampRateHz);
        millis = hw_divider_u32_quotient_inlined(modulo * 1000, SampRateHz);
        millis += sec * 1000;
    }
    uint32_t diff = _micros() - start;
    printf("[calc_divider] diff = %lu us\n", diff);
    return millis;
}
#endif

int main()
{
    srand(0);

    stdio_init_all();
    sleep_ms(1000);

    puts("START");
    //printf("RAND_MAX = %d\n", RAND_MAX);

    spin_lock = spin_lock_init(spin_lock_claim_unused(true));

    if (!add_repeating_timer_us(-1000000 / TIMER_HZ, timer_callback, nullptr, &timer)) {
        //printf("Failed to add timer\n");
        return 0;
    }

    uint32_t millis_ref = _millis();
    uint32_t millis;
    uint32_t count = 0;
    while (millis_ref < 2000 * 1000) {
        millis_ref = _millis();
        uint32_t samplesPlayed = (uint32_t) ((float) millis_ref * SampRateHz_div_1000);

        millis = calc_64bit(samplesPlayed);
        if (millis < millis_ref - 1 || millis > millis_ref + 1) {
            printf("ERROR [calc_64bit][%d] samplesPlayed = %lu, millis_ref = %d, millis = %lu\n", count, samplesPlayed, millis_ref, millis);
        }

        millis = calc_float(samplesPlayed);
        if (millis < millis_ref - 1 || millis > millis_ref + 1) {
            printf("ERROR [calc_float][%d] samplesPlayed = %lu, millis_ref = %d, millis = %lu\n", count, samplesPlayed, millis_ref, millis);
        }

        /*
        millis = calc_divider(samplesPlayed);
        if (millis < millis_ref - 1 || millis > millis_ref + 1) {
            printf("ERROR [calc_divider][%d] samplesPlayed = %lu, millis_ref = %d, millis = %lu\n", count, samplesPlayed, millis_ref, millis);
        }
        */
        count++;
    }

    printf("dummy = %d\n", dummy); // Not to be delete dummy by optimization
    printf("END\n");
    spin_lock_unclaim(spin_lock_get_num(spin_lock));
    return 0;
}
