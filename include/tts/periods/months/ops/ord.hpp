#pragma once


#include "tts/cmp.hpp"
#include "tts/periods/months/months.hpp"


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
    constexpr auto operator<=>(Months lhs, Months rhs) noexcept {
        return lhs.count() <=> rhs.count();
    }

    // (in)equality! 
    [[nodiscard]]
    constexpr bool operator==(Months lhs, Months rhs) noexcept {
        
        /**
         * In spaceship path, inequality is automatically derived from the
         * equality operator overload.
         */

        return cmpeq(lhs.count(), rhs.count());
    }
    #else

    // partial ord!
    [[nodiscard]]
    constexpr bool operator<=(Months lhs, Months rhs) noexcept {
        return cmple(lhs.count(), rhs.count());
    }

    [[nodiscard]]
    constexpr bool operator>=(Months lhs, Months rhs) noexcept {
        return cmpge(lhs.count(), rhs.count());
    }

    // total ord!
    [[nodiscard]]
    constexpr bool operator<(Months lhs, Months rhs) noexcept {
        return cmplt(lhs.count(), rhs.count());
    }

    [[nodiscard]]
    constexpr bool operator>(Months lhs, Months rhs) noexcept {
        return cmpgt(lhs.count(), rhs.count());
    }

    // (in)equality! 
    [[nodiscard]]
    constexpr bool operator==(Months lhs, Months rhs) noexcept {
        return cmpeq(lhs.count(), rhs.count());
    }

    [[nodiscard]]
    constexpr bool operator!=(Months lhs, Months rhs) noexcept {
        return cmpneq(lhs.count(), rhs.count());
    }   
    #endif
} // namespace tts.
