#pragma once


#include "tts/periods/months/months.hpp"


namespace tts {
    // prefix!
    constexpr Months &operator++(Months &months) noexcept {
        ++months.as_mut_count();
        return months;
    }

    constexpr Months &operator--(Months &months) noexcept {
        --months.as_mut_count();
        return months;
    }

    // postfix!
    constexpr Months operator++(Months &months, int) noexcept {
        const auto deepcopy = months;
        ++months.as_mut_count();

        return deepcopy;
    }

    constexpr Months operator--(Months &months, int) noexcept {
        const auto deepcopy = months;
        --months.as_mut_count();

        return deepcopy;
    }

    //pos!
    [[nodiscard]]
    constexpr Months operator+(Months months) noexcept {
        // no-op.
        return months;
    }

    [[nodiscard]]
    constexpr Months operator-(Months months) noexcept {
        
        /**
         * Months is passed by value since it is trivially copyable,
         * returns its negative copy counterpart. Non-mutating tform.
        */

        return Months{-months.count()};
    }
} // namespace tts.
