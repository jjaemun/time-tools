#pragma once


#include "tts/months/months.hpp"


namespace tts {
    // add!
    [[nodiscard]]
    constexpr Months operator+(Months lhs, Months rhs) noexcept {
        
        /**
         * Value semantics follow from trivial copiability of
         * months. 
        */

        return Months{lhs.count() + rhs.count()};
    }

    // sub!
    [[nodiscard]]
    constexpr Months operator-(Months lhs, Months rhs) noexcept {
        
        /**
         * Value semantics follow from trivial copiability of
         * months. 
        */

        return Months{lhs.count() - rhs.count()};
    }
} // namespace tts.
