#pragma once


#include "tts/businessdays/businessdays.hpp"


namespace tts {
    // mul!
    template <typename T>
    [[nodiscard]]
    constexpr BusinessDays operator*(BusinessDays bds, T scalar) noexcept {

        /**
         * BusinessDays ops ergonomics layer. Right-scalar multiplication. 
        */

        const auto scaled = bds.count() * static_cast<i32>(scalar);
        return BusinessDays{scaled};
    }

    template <typename T>
    [[nodiscard]]
    constexpr BusinessDays operator*(T scalar, BusinessDays bds) noexcept {
 
        /**
         * Left-scalar multiplication, invokes right-scalar mul due to 
         * commutativity of the product and to unify implementation.
        */

       return bds * scalar;
    }
   
    // div!
    template <typename T>
    [[nodiscard]]
    constexpr BusinessDays operator/(BusinessDays bds, T scalar) noexcept {

        /**
         * Left-scalar division, even under the premise of completeness, 
         * makes no sense and so it is omitted here.
        */

        const auto scaled = bds.count() / static_cast<i32>(scalar);
        return BusinessDays{scaled};
    }
} // namespace tts.
