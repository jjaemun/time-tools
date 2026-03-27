#pragma once


#include "tts/tspans/tspans.hpp"


namespace tts {
    // mul!
    template <typename T, i32 N, typename U>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator*(TimeSpan<T, N> tspan, U scalar) noexcept {

        /**
         * TimeSpan ops ergonomics layer. Right-scalar multiplication. 
        */

        const auto scaled = static_cast<T>(tspan.count() * scalar);
        return TimeSpan<T, N>{scaled};
    }

    template <typename U, typename T, i32 N>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator*(U scalar, TimeSpan<T, N> tspan) noexcept {
 
        /**
         * Left-scalar multiplication, invokes right-scalar mul due to 
         * commutativity of the product and to unify implementation.
        */

       return tspan * scalar;
    }
   
    // div!
    template <typename T, i32 N, typename U>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator/(TimeSpan<T, N> tspan, U scalar) noexcept {

        /**
         * Left-scalar division, even under the premise of completeness, 
         * makes no sense and so it is omitted here.
        */

        const auto scaled = static_cast<T>(tspan.count() / scalar);
        return TimeSpan<T, N>{scaled};
    }
} // namespace tts.
