/**
 * @file static_instance.h
 * @version 0.1
 * @date 2019-12-14
 */
#pragma once
#ifndef BSP_UTIL_STATIC_INSTANCE_H
#define BSP_UTIL_STATIC_INSTANCE_H

#include <utility>

namespace bsp {
namespace util {

template<typename T>
class StaticInstance {
public:
    StaticInstance(const StaticInstance&) = delete;
    StaticInstance(StaticInstance&&) = delete;

    StaticInstance& operator=(const StaticInstance&) = delete;
    StaticInstance& operator=(StaticInstance&&) = delete;

    template<typename... Args>
    static void constructInstance(Args&&... args) {
        if(!instance) {
            static T inst{std::forward<Args>(args)...};
            instance = &inst;
        }
    }

    static T& getInstance() {
        return *instance;
    }

protected:
    // only allow construction/destruction from base classes(should only ever happen once)
    StaticInstance() {}
    virtual ~StaticInstance() {}

private:
    static T* instance;
};

template<typename T>
T* StaticInstance<T>::instance = nullptr;

}
}

#endif // BSP_UTIL_STATIC_INSTANCE_H