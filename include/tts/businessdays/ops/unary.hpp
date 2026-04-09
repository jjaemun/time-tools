#pragma once


#include "tts/businessdays/businessdays.hpp"


namespace tts {
    // prefix!
    constexpr BusinessDays &operator++(BusinessDays &bds) noexcept {
        ++bds.as_mut_count();
        return bds;
    }

    constexpr BusinessDays &operator--(BusinessDays &bds) noexcept {
        --bds.as_mut_count();
        return bds;
    }

    // postfix!
    constexpr BusinessDays operator++(BusinessDays &bds, int) noexcept {
        const auto deepcopy = bds;
        ++bds.as_mut_count();

        return deepcopy;
    }

    constexpr BusinessDays operator--(BusinessDays &bds, int) noexcept {
        const auto deepcopy = bds;
        --bds.as_mut_count();

        return deepcopy;
    }

    //pos!
    [[nodiscard]]
    constexpr BusinessDays operator+(BusinessDays bds) noexcept {
        // no-op.
        return bds;
    }

    [[nodiscard]]
    constexpr BusinessDays operator-(BusinessDays bds) noexcept {
        
        /**
         * BusinessDays is passed by value since it is trivially copyable,
         * returns its negative copy counterpart. Non-mutating tform.
        */

        return BusinessDays{-bds.count()};
    }
} // namespace tts.
