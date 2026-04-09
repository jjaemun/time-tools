#pragma once


#include "tts/years/years.hpp"


namespace tts {
    // add!
    [[nodiscard]]
    constexpr Years operator+(Years lhs, Years rhs) noexcept {
        
        /**
         * Value semantics follow from trivial copiability of
         * years. 
        */

        return Years{lhs.count() + rhs.count()};
    }

    // sub!
    [[nodiscard]]
    constexpr Years operator-(Years lhs, Years rhs) noexcept {
        
        /**
         * Value semantics follow from trivial copiability of
         * years. 
        */

        return Years{lhs.count() - rhs.count()};
    }
} // namespace tts.
