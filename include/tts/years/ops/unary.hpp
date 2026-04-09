#pragma once


#include "tts/years/years.hpp"


namespace tts {
    // prefix!
    constexpr Years &operator++(Years &years) noexcept {
        ++years.as_mut_count();
        return years;
    }

    constexpr Years &operator--(Years &years) noexcept {
        --years.as_mut_count();
        return years;
    }

    // postfix!
    constexpr Years operator++(Years &years, int) noexcept {
        const auto deepcopy = years;
        ++years.as_mut_count();

        return deepcopy;
    }

    constexpr Years operator--(Years &years, int) noexcept {
        const auto deepcopy = years;
        --years.as_mut_count();

        return deepcopy;
    }

    //pos!
    [[nodiscard]]
    constexpr Years operator+(Years years) noexcept {
        // no-op.
        return years;
    }

    [[nodiscard]]
    constexpr Years operator-(Years years) noexcept {
        
        /**
         * Years is passed by value since it is trivially copyable,
         * returns its negative copy counterpart. Non-mutating tform.
        */

        return Years{-years.count()};
    }
} // namespace tts.
