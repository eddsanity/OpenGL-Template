#pragma once

#include <stdint.h>

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

namespace _e_private
{
    template<typename F>
    struct _Defer
    {
        F f;
        _Defer(F f) : f(f) {}
        ~_Defer() { f(); }
    };

    template<typename F>
    _Defer<F> defer_func(F f)
    {
        return _Defer<F>(f);
    }
}

#define DEFER_1(x, y) x##y
#define DEFER_2(x, y) DEFER_1(x, y)
#define DEFER_3(x)    DEFER_2(x, __COUNTER__)
#define defer(code)   auto DEFER_3(_defer_) = _e_private::defer_func([&](){code;})

