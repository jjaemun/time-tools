#pragma once


#include "constants.hpp"
#include "gregorian/gregorian.hpp"


namespace tts {
    class Date final {
    
        /** 
         * Date abstraction. Internally tracks days from
         * unix epoch (native).
        */

    public:
        i32 value;

        // copy-accessors!
        [[nodiscard]] 
        constexpr i32 to_unix_serial() const noexcept {
            return value;
        }

        [[nodiscard]] 
        constexpr i32 to_excel_serial() const noexcept {
            return value + excel::date::OFFSET;
        }

        [[nodiscard]] 
        constexpr i32 to_murex_serial() const noexcept {
            return value + murex::date::OFFSET;
        }
        
        [[nodiscard]] 
        constexpr i32 to_julian_serial() const noexcept {
            return value + julian::date::OFFSET;
        }
        
        [[nodiscard]] 
        constexpr CivilDate to_civil() const noexcept {
            return gregorian::civil_from_serial(value);
        }

        // immutable-ref-accessor!
        [[nodiscard]]
        constexpr const i32 &as_unix_serial() const noexcept {
            return value;
        }

        // mutable-ref-accessor!
        constexpr i32 &as_mut_unix_serial() noexcept {
            return value;
        }       

        // gregorian decompositions!
        [[nodiscard]]
        constexpr i32 year() const noexcept {
            return to_civil().year;
        }

        [[nodiscard]]
        constexpr u16 month() const noexcept {
            return to_civil().month;
        }

        [[nodiscard]]
        constexpr u16 day() const noexcept {
            return to_civil().day;
        }

        // serial predicates!
        [[nodiscard]]
        constexpr bool is_weekend() const noexcept {
        
            /**
             * Because 1970-01-01 (unix epoch) was a thursday, we offset
             * by 3 then check from 'monday'.
            */

            return (value + 3) % 7 >= 5;
        }

        [[nodiscard]]
        constexpr bool is_weekday() const noexcept {
            return (!is_weekend());
        }

        // gregorian predicates!
        [[nodiscard]]
        constexpr bool is_leap() const noexcept {
            return to_civil().is_leap();
        }
        
        [[nodiscard]]
        constexpr bool is_start_of_month() const noexcept {
            return to_civil().is_start_of_month();
        }
        
        [[nodiscard]]
        constexpr bool is_end_of_month() const noexcept {
            return to_civil().is_end_of_month();
        }
         
        [[nodiscard]]
        constexpr bool is_start_of_year() const noexcept {
            return to_civil().is_start_of_year();
        }
 
        [[nodiscard]]
        constexpr bool is_end_of_year() const noexcept {
            return to_civil().is_end_of_year();
        }

        // attr!
        [[nodiscard]]
        constexpr u16 days_in_month() const noexcept {
            return to_civil().days_in_month();
        }
    };
} // namespace tts.
