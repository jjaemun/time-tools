#pragma once 


#include "civil.hpp"

namespace tts::gregorian {
    // predicates!
    [[nodiscard]]
    constexpr bool is_leap(CivilDate civil) noexcept {
        return civil.is_leap();
    }
        
    [[nodiscard]]
    constexpr bool is_start_of_month(CivilDate civil) noexcept {
        return civil.is_start_of_month();
    }

    [[nodiscard]]
    constexpr bool is_end_of_month(CivilDate civil) noexcept {
        return civil.is_end_of_month();
    }

    [[nodiscard]]
    constexpr bool is_start_of_year(CivilDate civil) noexcept {
        return civil.is_start_of_year();
    }
    
    [[nodiscard]] 
    constexpr bool is_end_of_year(CivilDate civil) noexcept {
        return civil.is_end_of_year();
    }
} // namespace tts::gregorian.
