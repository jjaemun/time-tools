#pragma once


#include "tts/timespans/timespans.hpp"

namespace tts {
    // prefix!
    template <typename T, i64 N>
    constexpr TimeSpan<T, N> &operator++(TimeSpan<T, N> &tspan) noexcept {
        ++tspan.as_mut_count();
        return tspan;
    }

    template <typename T, i64 N>
    constexpr TimeSpan<T, N> &operator--(TimeSpan<T, N> &tspan) noexcept {
        --tspan.as_mut_count();
        return tspan;
    }
   
    // postfix!
    template <typename T, i64 N>
    constexpr TimeSpan<T, N> operator++(TimeSpan<T, N> &tspan, int) noexcept {
        const auto deepcopy = tspan;
        ++tspan.as_mut_count();

        return deepcopy;
    }

    template <typename T, i64 N>
    constexpr TimeSpan<T, N> operator--(TimeSpan<T, N> &tspan, int) noexcept {
        const auto deepcopy = tspan;
        --tspan.as_mut_count();

        return deepcopy;
    }
    
    // pos!
    template <typename T, i64 N>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator+(TimeSpan<T, N> tspan) noexcept {
         //no-op
        return tspan;
    }

    // neg!
    template <typename T, i64 N>
    [[nodiscard]]
    constexpr TimeSpan<T, N> operator-(TimeSpan<T, N> tspan) noexcept {
        
        /**
         * Timespan is passed by value since it is trivially copyable, 
         * returns its negative copy counterpart. Non-mutating tform.
        */

        return TimeSpan<T, N>{-tspan.count()};
    }
} // namespace tts.  
