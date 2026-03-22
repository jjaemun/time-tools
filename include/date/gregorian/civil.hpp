#pragma once


#include "types.hpp"
#include "cmp.hpp"


namespace tts {
    class CivilDate final {
    
        /** 
         * Human-readable (proletic gregorian) date abstraction. Should only
         * exist through tts::Date at the boundary, i.e., no native computations.
        */

    public:
        i32 year;
        u16 month;
        u16 day;

        // attr!
        [[nodiscard]]
        constexpr u16 days_in_month() const noexcept {
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
                    if (is_leap()) [[unlikely]]
                        return 29;
                    return 28;

                default:
                    __builtin_unreachable();
            }
        }

        // predicates!
        [[nodiscard]]
        constexpr bool is_leap() const noexcept {
            return (cmpeq(year % 4, 0) && cmpneq(year % 100, 0))
                || cmpeq(year % 400, 0);
        }

        [[nodiscard]]
        constexpr bool is_start_of_month() const noexcept {
            return cmpeq(day, (u16)1);         
        }

        [[nodiscard]]
        constexpr bool is_end_of_month() const noexcept {
            return cmpeq(day, days_in_month());         
        }
        
        [[nodiscard]]
        constexpr bool is_start_of_year() const noexcept {
            return (is_start_of_month() &&
                cmpeq(month, (u16)1));         
        }
        
        [[nodiscard]]
        constexpr bool is_end_of_year() const noexcept {
            return (cmpeq(day, (u16)31) && 
                cmpeq(month, (u16)12));         
        }
    };
} // namespace tts.
