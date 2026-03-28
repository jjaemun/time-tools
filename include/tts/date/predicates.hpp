#pragma once


#include "tts/date/date.hpp"


namespace tts {
    // serial predicates!
    [[nodiscard]]
    constexpr bool is_monday(Date date) noexcept {
        return date.is_monday();
    }

    [[nodiscard]]
    constexpr bool is_tuesday(Date date) noexcept {
        return date.is_tuesday();
    }

    [[nodiscard]]
    constexpr bool is_wednesday(Date date) noexcept {
        return date.is_wednesday();
    }
    
    [[nodiscard]]
    constexpr bool is_thursday(Date date) noexcept {
        return date.is_thursday();
    }

    [[nodiscard]]
    constexpr bool is_friday(Date date) noexcept {
        return date.is_friday();
    }

    [[nodiscard]]
    constexpr bool is_saturday(Date date) noexcept {
        return date.is_saturday();
    }

    [[nodiscard]]
    constexpr bool is_sunday(Date date) noexcept {
        return date.is_sunday();
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
