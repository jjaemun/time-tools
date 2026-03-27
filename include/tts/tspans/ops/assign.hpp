#pragma once 


#include "tts/tspans/tspans.hpp"
#include "tts/tspans/ops/binary.hpp"
#include "tts/tspans/ops/scalar.hpp"


namespace tts {
    // add-assign!
    template <typename T, i64 N, typename U, i64 M>
    constexpr TimeSpan<T, N> &operator+=(TimeSpan<T, N> &lhs, TimeSpan<U, M> rhs) noexcept {
        lhs.as_mut_count() += rhs.to<T, N>().count();
        return lhs;
    }
   
    // sub-assign!
    template <typename T, i64 N, typename U, i64 M>
    constexpr TimeSpan<T, N> &operator-=(TimeSpan<T, N> &lhs, TimeSpan<U, M> rhs) noexcept {
        lhs.as_mut_count() -= rhs.to<T, N>().count();
        return lhs;
    }

    // scalar mul-assign!
    template <typename T, i64 N, typename U>
    constexpr TimeSpan<T, N> &operator*=(TimeSpan<T, N> &tspan, U scalar) noexcept {
        tspan.as_mut_count() *= scalar;
        return tspan;
    }

    // scalar div-assign!
    template <typename T, i64 N, typename U>
    constexpr TimeSpan<T, N> &operator/=(TimeSpan<T, N> &tspan, U scalar) noexcept {
        tspan.as_mut_count() /= scalar;
        return tspan;
    }
} // namespace tts.


