/**
 * @file util.h
 * @author Hunter Borlik
 * @version 0.1
 * @date 2019-12-17
 */
#pragma once
#ifndef DASH_UTIL_H
#define DASH_UTIL_H

#include <stdint.h>

namespace dash_util {

uint32_t get_clock_cycle_count();
void delay_us(uint32_t us);

}

#endif // DASH_UTIL_H