#pragma once


#include "tts/tspans/tspans.hpp"


namespace tts {
    
    /**
     * Binary operations promote mismatching timespan scales to the coarsest
     * of the two operands. This enforces a general convention while allowing
     * finer scale return types when using inline explicit conversions.
    */

    //add!     
    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr auto operator+(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
 
        /**
         * Notice that actual return type depends on branching, and so
         * using auto fully generalises. It is the coarsest by default.
        */

        if constexpr (N > M)
            return TimeSpan<T, N>{lhs.count() + rhs.to<T, N>().count()};
        else
            return TimeSpan<U, M>{lhs.to<U, M>().count() + rhs.count()};
    }

    // sub!
    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr auto operator-(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
  
        /**
         * Notice that actual return type depends on branching, and so
         * using auto fully generalises. It is the coarsest by default.
        */

       if constexpr (N > M)
            return TimeSpan<T, N>{lhs.count() - rhs.to<T, N>().count()};
        else
            return TimeSpan<U, M>{lhs.to<U, M>().count() - rhs.count()};
    }
} // namespace tts.
