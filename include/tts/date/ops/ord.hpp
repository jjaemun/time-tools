#pragma once


#include "date/date.hpp"
#include "cmp.hpp"


namespace tts {
    #if (defined(__cpp_impl_three_way_comparison) \
            && defined(__cpp_lib_three_way_comparison))
    
        /**
         * As of writing this, it is unclear whether spaceship implementation
         * is banned for cmp operations. Regardless, some future-proof-ing is
         * never too bad (C++20), especially when it saves lines of code.
         */

    // spaceship!
    [[nodiscard]]
    constexpr auto operator<=>(Date lhs, Date rhs) noexcept {
        return lhs.as_unix_serial() <=> rhs.as_unix_serial();
    }

    // (in)equality! 
    [[nodiscard]]
    constexpr bool operator==(Date lhs, Date rhs) noexcept {
        
        /**
         * In spaceship path, inequality is automatically derived from the
         * equality operator overload.
         */

        return cmpeq(lhs.as_unix_serial(), rhs.as_unix_serial());
    }
    #else

    // partial ord!
    [[nodiscard]]
    constexpr bool operator<=(Date lhs, Date rhs) noexcept {
        return cmple(lhs.as_unix_serial(), rhs.as_unix_serial());
    }

    [[nodiscard]]
    constexpr bool operator>=(Date lhs, Date rhs) noexcept {
        return cmpge(lhs.as_unix_serial(), rhs.as_unix_serial());
    }

    // total ord!
    [[nodiscard]]
    constexpr bool operator<(Date lhs, Date rhs) noexcept {
        return cmplt(lhs.as_unix_serial(), rhs.as_unix_serial());
    }

    [[nodiscard]]
    constexpr bool operator>(Date lhs, Date rhs) noexcept {
        return cmpgt(lhs.as_unix_serial(), rhs.as_unix_serial());
    }

    // (in)equality! 
    [[nodiscard]]
    constexpr bool operator==(Date lhs, Date rhs) noexcept {
        return cmpeq(lhs.as_unix_serial(), rhs.as_unix_serial());
    }

    [[nodiscard]]
    constexpr bool operator!=(Date lhs, Date rhs) noexcept {
        return cmpneq(lhs.as_unix_serial(), rhs.as_unix_serial());
    }   
    #endif
} // namespace tts.
