#pragma once


#include "date/date.hpp"
#include "cmp.hpp"


namespace tts {
    #if defined(__cpp_impl_three_way_comparison) && defined(__cpp_lib_three_way_comparison)
    
        /**
         * As of writing this, it is unclear whether spaceship implementation
         * is allowed for cmp operations. Regardless, some future-proof-ing is
         * never too bad (C++20).
         */

    // spaceship!
    [[nodiscard]]
    constexpr auto operator<=>(Date lhs, Date rhs) noexcept {
        return lhs.value <=> rhs.value;
    }

    #else 
        
        /**
         * Explicit six fallback --standard implementation.
        */

    // partial ord!
    [[nodiscard]]
    constexpr bool operator<=(Date lhs, Date rhs) noexcept {
        return cmple(lhs.value, rhs.value);
    }

    [[nodiscard]]
    constexpr bool operator>=(Date lhs, Date rhs) noexcept {
        return cmpge(lhs.value, rhs.value);
    }

    // total ord!
    [[nodiscard]]
    constexpr bool operator<(Date lhs, Date rhs) noexcept {
        return cmplt(lhs.value, rhs.value);
    }

    [[nodiscard]]
    constexpr bool operator>(Date lhs, Date rhs) noexcept {
        return cmpgt(lhs.value, rhs.value);
    }

    #endif

    // (in)equality! 
    [[nodiscard]]
    constexpr bool operator==(Date lhs, Date rhs) noexcept {
        return cmpeq(lhs.value, rhs.value);
    }

    [[nodiscard]]
    constexpr bool operator!=(Date lhs, Date rhs) noexcept {
        return cmpne(lhs.value, rhs.value);
    }   
} // namespace tts.
