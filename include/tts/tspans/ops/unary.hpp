#pragma once


#include "tts/tspans/tspans.hpp"

namespace tts {
    // prefix!
    template <typename T, i32 N>
    constexpr TimeSpan<T, N> &operator++(TimeSpan<T, N> &tspan) noexcept {
        ++tspan.as_mut_count();
        return tspan;
    }

    template <typename T, i32 N>
    constexpr TimeSpan<T, N> &operator--(TimeSpan<T, N> &tspan) noexcept {
        --tspan.as_mut_count();
        return tspan;
    }
   
    // postfix!
    template <typename T, i32 N>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator++(TimeSpan<T, N> &tspan, int) noexcept {
        const auto deepcopy = tspan;
        ++tspan.as_mut_count();

        return deepcopy;
    }

    template <typename T, i32 N>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator--(TimeSpan<T, N> &tspan, int) noexcept {
        const auto deepcopy = tspan;
        --tspan.as_mut_count();

        return deepcopy;
    }
} // namespace tts.  
