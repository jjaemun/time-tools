#pragma once


#include "tts/months/months.hpp"


namespace tts {
    // mul!
    template <typename T>
    [[nodiscard]]
    constexpr Months operator*(Months months, T scalar) noexcept {

        /**
         * Months ops ergonomics layer. Right-scalar multiplication. 
        */

        const auto scaled = months.count() * static_cast<i32>(scalar);
        return Months{scaled};
    }

    template <typename T>
    [[nodiscard]]
    constexpr Months operator*(T scalar, Months months) noexcept {
 
        /**
         * Left-scalar multiplication, invokes right-scalar mul due to 
         * commutativity of the product and to unify implementation.
        */

       return months * scalar;
    }
   
    // div!
    template <typename T>
    [[nodiscard]]
    constexpr Months operator/(Months months, T scalar) noexcept {

        /**
         * Left-scalar division, even under the premise of completeness, 
         * makes no sense and so it is omitted here.
        */

        const auto scaled = months.count() / static_cast<i32>(scalar);
        return Months{scaled};
    }
} // namespace tts.
