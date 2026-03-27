#pragma once


#include "tts/cmp.hpp"
#include "tts/tspans/tpans.hpp"


namespace tts {
    
        /**
         * TimeSpan pairwise comparisons occur in the finest scale, to avoid 
         * information loss. We retrive coarsness directly from the template
         * parametersand keep instantiations constexpr friendly.
        */

    #if (defined(__cpp_impl_three_way_comparison) \
            && defined(__cpp_lib_three_way_comparison))
    
        /**
         * As of writing this, it is unclear whether spaceship implementation
         * is banned for cmp operations. Regardless, some future-proof-ing is
         * never too bad (C++20), especially when it saves lines of code.
         */

    // spaceship!
    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr auto operator<=>(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
        if constexpr (N > M)
            return lhs.to<U, M>().count() <=> rhs.count();
        else
            return lhs.count() <=> rhs.to<T, N>().count();
    }

    // (in)equality! 
    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr bool operator==(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
        
        /**
         * In spaceship path, inequality is automatically derived from the
         * equality operator overload.
         */
	
	    if constexpr (N > M)
            return cmpeq(lhs.to<U, M>().count(), rhs.count());
        else 
            return cmpeq(lhs.count(), rhs.to<T, N>().count());
    }
    #else

    // partial ord!
    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr bool operator<=(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
	    if constexpr (N > M)
            return cmple(lhs.to<U, M>().count(), rhs.count());
        else 
            return cmple(lhs.count(), rhs.to<T, N>().count());
    }

    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr bool operator>=(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
	    if constexpr (N > M)
            return cmpge(lhs.to<U, M>().count(), rhs.count());
        else 
            return cmpge(lhs.count(), rhs.to<T, N>().count());
    }

    // total ord!
    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr bool operator<(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
	    if constexpr (N > M)
            return cmplt(lhs.to<U, M>().count(), rhs.count());
        else 
            return cmplt(lhs.count(), rhs.to<T, N>().count());
    }

    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr bool operator>(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
	    if constexpr (N > M)
            return cmpgt(lhs.to<U, M>().count(), rhs.count());
        else 
            return cmpgt(lhs.count(), rhs.to<T, N>().count());
    }

    // (in)equality! 
    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr bool operator==(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
	    if constexpr (N > M)
            return cmpeq(lhs.to<U, M>().count(), rhs.count());
        else 
            return cmpeq(lhs.count(), rhs.to<T, N>().count());
    }

    template <typename T, i32 N, typename U, i32 M>
    [[nodiscard]]
    constexpr bool operator!=(TimeSpan<T, N> lhs, TimeSpan<U, M> rhs) noexcept {
	    if constexpr (N > M)
            return cmpneq(lhs.to<U, M>().count(), rhs.count());
        else 
            return cmpneq(lhs.count(), rhs.to<T, N>().count());
    }
    #endif

} // namespace tts.

} // namespace tts.
