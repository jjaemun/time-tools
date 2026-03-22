#pragma once


#include "algorithms.hpp"
#include "constants.hpp"


namespace tts::gregorian {
    // validation! 
    [[nodiscard]]
    constexpr bool is_valid_year(i32 year) noexcept {
        return cmpge(year, year::MIN) && cmple(year, year::MAX);
    }

    [[nodiscard]]
    constexpr bool is_valid_month(u16 month) noexcept {
        return cmpge(month, month::MIN) && cmple(month, month::MAX);
    }

    [[nodiscard]]
    constexpr bool is_valid_day(i32 year, u16 month, u16 day) noexcept {
        const auto MAXDAYS = gregorian::days_in_month(year, month);
        return cmpge(day, day::MIN) && cmple(day, MAXDAYS);
    }
} // namespace tts::gregorian.
