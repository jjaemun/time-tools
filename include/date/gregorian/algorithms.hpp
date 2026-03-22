#pragma once


#include "cmp.hpp"
#include "types.hpp"


namespace tts::gregorian {
    // algorithms!
    [[nodiscard]]
    constexpr bool is_leap(i32 year) noexcept {

        /**
         * Compuetes whether year is a leap year.
        */

        return (cmpeq(year % 4, 0) && cmpneq(year % 100, 0))
                || cmpeq(year % 400, 0);
    }

    [[nodiscard]]
    constexpr u16 days_in_month(i32 year, u16 month) noexcept {
        
        /**
         * Computes days in current month and adjusts for leap year.
        */

        switch (month) {
            case (1):
                // january.
                [[fallthrough]];

            case (3):  
                // march.
                [[fallthrough]];

            case (5):
                // may.
                [[fallthrough]];

            case (7):
                // july.
                [[fallthrough]];

            case (8):
                // august.
                [[fallthrough]];

            case (10):
                // october.
                [[fallthrough]];
                                
            case (12): 
                // december.
                return 31;

            case (4):
                // april.
                [[fallthrough]];
            
            case (6):
                // june.
                [[fallthrough]];

            case (9):
                // september.
                [[fallthrough]];

            case (11):
                // november.
                return 30;
                        
            case (2):
                if (is_leap(year)) [[unlikely]]
                    return 29;
                    return 28;

            default:
                __builtin_unreachable();
        }
    }
} // namespace gregorian.
