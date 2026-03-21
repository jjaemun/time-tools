#pragma once


#include <cassert>


namespace tts {
    // assertions!
    template <typename T>
    constexpr void assert_eq(T a, T b) noexcept {
        assert(a == b);
    }
         
    template <typename T>
    constexpr void assert_neq(T a, T b) noexcept {
        assert(a != b);
    }

    template <typename T>
    constexpr void assert_lt(T a, T b) noexcept {
        assert(a < b);
    }
    
    template <typename T>
    constexpr void assert_le(T a, T b) noexcept {
        assert(a <= b);
    }
    
    template <typename T>
    constexpr void assert_gt(T a, T b) noexcept {
        assert(a > b);
    }
    
    template <typename T>
    constexpr void assert_ge(T a, T b) noexcept {
        assert(a >= b);
    }
} // namespace tts.
