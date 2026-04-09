#pragma once 


#include "tts/months/months.hpp"
#include "tts/months/ops/binary.hpp"
#include "tts/months/ops/scalar.hpp"


namespace tts {
    // add-assign!
    constexpr Months &operator+=(Months &lhs, Months rhs) noexcept {
        lhs.as_mut_count() += rhs.count();
        return lhs;
    }
   
    // sub-assign!
    constexpr Months &operator-=(Months &lhs, Months rhs) noexcept {
        lhs.as_mut_count() -= rhs.count();
        return lhs;
    }

    // scalar mul-assign!
    template <typename T>
    constexpr Months &operator*=(Months &months, T scalar) noexcept {
        months.as_mut_count() *= scalar;
        return months;
    }

    // scalar div-assign!
    template <typename T>
    constexpr Months &operator/=(Months &months, T scalar) noexcept {
        months.as_mut_count() /= scalar;
        return months;
    }
} // namespace tts.


