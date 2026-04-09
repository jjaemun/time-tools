#pragma once


#include "tts/years/years.hpp"


namespace tts {
    // mul!
    template <typename T>
    [[nodiscard]]
    constexpr Years operator*(Years years, T scalar) noexcept {

        /**
         * Years ops ergonomics layer. Right-scalar multiplication. 
        */

        const auto scaled = years.count() * static_cast<i32>(scalar);
        return Years{scaled};
    }

    template <typename T>
    [[nodiscard]]
    constexpr Years operator*(T scalar, Years years) noexcept {
 
        /**
         * Left-scalar multiplication, invokes right-scalar mul due to 
         * commutativity of the product and to unify implementation.
        */

       return years * scalar;
    }
   
    // div!
    template <typename T>
    [[nodiscard]]
    constexpr Years operator/(Years years, T scalar) noexcept {

        /**
         * Left-scalar division, even under the premise of completeness, 
         * makes no sense and so it is omitted here.
        */

        const auto scaled = years.count() / static_cast<i32>(scalar);
        return Years{scaled};
    }
} // namespace tts.
