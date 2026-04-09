#pragma once


#include "tts/businessdays/businessdays.hpp"


namespace tts {
    // add!
    [[nodiscard]]
    constexpr BusinessDays operator+(BusinessDays lhs, BusinessDays rhs) noexcept {
        
        /**
         * Value semantics follow from trivial copiability of
         * businessdays. 
        */

        return BusinessDays{lhs.count() + rhs.count()};
    }

    // sub!
    [[nodiscard]]
    constexpr BusinessDays operator-(BusinessDays lhs, BusinessDays rhs) noexcept {
        
        /**
         * Value semantics follow from trivial copiability of
         * businessdays. 
        */

        return BusinessDays{lhs.count() - rhs.count()};
    }
} // namespace tts.
