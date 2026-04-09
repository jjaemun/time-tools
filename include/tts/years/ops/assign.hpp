#pragma once 


#include "tts/years/years.hpp"
#include "tts/years/ops/binary.hpp"
#include "tts/years/ops/scalar.hpp"


namespace tts {
    // add-assign!
    constexpr Years &operator+=(Years &lhs, Years rhs) noexcept {
        lhs.as_mut_count() += rhs.count();
        return lhs;
    }
   
    // sub-assign!
    constexpr Years &operator-=(Years &lhs, Years rhs) noexcept {
        lhs.as_mut_count() -= rhs.count();
        return lhs;
    }

    // scalar mul-assign!
    template <typename T>
    constexpr Years &operator*=(Years &years, T scalar) noexcept {
        years.as_mut_count() *= scalar;
        return years;
    }

    // scalar div-assign!
    template <typename T>
    constexpr Years &operator/=(Years &years, T scalar) noexcept {
        years.as_mut_count() /= scalar;
        return years;
    }
} // namespace tts.


