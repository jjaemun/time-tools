#pragma once 


#include "tts/businessdays/businessdays.hpp"
#include "tts/businessdays/ops/binary.hpp"
#include "tts/businessdays/ops/scalar.hpp"


namespace tts {
    // add-assign!
    constexpr BusinessDays &operator+=(BusinessDays &lhs, BusinessDays rhs) noexcept {
        lhs.as_mut_count() += rhs.count();
        return lhs;
    }
   
    // sub-assign!
    constexpr BusinessDays &operator-=(BusinessDays &lhs, BusinessDays rhs) noexcept {
        lhs.as_mut_count() -= rhs.count();
        return lhs;
    }

    // scalar mul-assign!
    template <typename T>
    constexpr BusinessDays &operator*=(BusinessDays &bds, T scalar) noexcept {
        bds.as_mut_count() *= scalar;
        return bds;
    }

    // scalar div-assign!
    template <typename T>
    constexpr BusinessDays &operator/=(BusinessDays &bds, T scalar) noexcept {
        bds.as_mut_count() /= scalar;
        return bds;
    }
} // namespace tts.


