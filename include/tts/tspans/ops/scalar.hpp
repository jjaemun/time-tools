#pragma once


#include "tts/tspans/tspans.hpp"


namespace tts {
    // scalar!
    template <typename T, i32 N, typename U>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator*(TimeSpan<T, N> tspan, U scalar) noexcept {
        return TimeSpan<T, N>{static_cast<T>(tspan.count() * scalar)};
    }

    template <typename U, typename T, i32 N>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator*(U scalar, TimeSpan<T, N> tspan) noexcept {
        return TimeSpan<T, N>{static_cast<T>(tspan.count() * scalar)};
    }
    
    template <typename T, i32 N, typename U>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator/(TimeSpan<T, N> tspan, U scalar) noexcept {

        /**
         * Left scalar div, even under the premise of completeness, makes no
         * sense and so it is omitted here.
        */

        return TimeSpan<T, N>{static_cast<T>(tspan.count() / scalar)};
    }
} // namespace tts.
