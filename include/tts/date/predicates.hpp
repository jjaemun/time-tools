#pragma once


#include "tts/date/date.hpp"


namespace tts {
    // serial predicates!
    [[nodiscard]]
    constexpr bool is_weekend(Date date) noexcept {
        return date.is_weekend();
    }

    [[nodiscard]]
    constexpr bool is_weekday(Date date) noexcept {
        return date.is_weekday();
    }

    // gregorian predicates!
    [[nodiscard]]
    constexpr bool is_leap(Date date) noexcept {
        return date.is_leap();
    }
        
    [[nodiscard]]
    constexpr bool is_start_of_month(Date date) noexcept {
        return date.is_start_of_month();
    }
        
    [[nodiscard]]
    constexpr bool is_end_of_month(Date date) noexcept {
        return date.is_end_of_month();
    }
         
    [[nodiscard]]
    constexpr bool is_start_of_year(Date date) noexcept {
        return date.is_start_of_year();
    }
 
    [[nodiscard]]
    constexpr bool is_end_of_year(Date date) noexcept {
        return date.is_end_of_year();
    }
} // namespace tts.
