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
#include <bits/unique_ptr.h>

namespace dash_util {

uint32_t get_clock_cycle_count();
void delay_us(uint32_t us);

}

// add make_unique (c++ 14 feature)
#if __cplusplus <= 201103L

namespace std {
    template<typename T, typename... Args>
    unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

#endif // make_unique

#endif // DASH_UTIL_H