#pragma once


#include "algorithms.hpp"
#include "constants.hpp"
#include "exceptions.hpp"
#include "validation.hpp"
#include "types.hpp"
#include "cmp.hpp"


namespace tts {
    class CivilDate final {
    
        /** 
         * Human-readable (proletic gregorian) date abstraction. Should only
         * exist through tts::Date at the boundary, i.e., no native computations.
        */

    private:
        i32 year;
        u16 month;
        u16 day;

        // constructor!
        explicit constexpr CivilDate(i32 year_, u16 month_, u16 day_) noexcept
            : year(year_), month(month_), day(day_) {}
        
    public:
        // runtime named-constructor!
        [[nodiscard]]
        static CivilDate from_ymd(i32 year_, u16 month_, u16 day_) {
    
            /**
             * Non-constexpr to avoid cryptic compile errors (if throw
             * path). General purpose constructor should be preferred.
            */

            if (!gregorian::is_valid_year(year_))
                throw CivilDateError(err::gregorian::year);

            if (!gregorian::is_valid_month(month_))
                throw CivilDateError(err::gregorian::month);

            if (!gregorian::is_valid_day(year_, month_, day_))
                throw CivilDateError(err::gregorian::day);
        
            return CivilDate{year_, month_, day_};
        }
    
        // compile-time named-constructor!
        [[nodiscard]]
        static constexpr CivilDate from_ymd_unsafe(i32 year_, u16 month_, u16 day_) noexcept {
 
            /**
             * Beware **unsafe**, does not check date is valid. Internal
             * usage mainly, callee owns the consequences. 
            */   

            return CivilDate{year_, month_, day_};
        }

        // accessors!
        [[nodiscard]]
        constexpr i32 get_year() const noexcept {
            return year;
        }
        
        [[nodiscard]]
        constexpr u16 get_month() const noexcept {
            return month;
        }       
        
        [[nodiscard]]
        constexpr u16 get_day() const noexcept {
            return day;
        }       

        // attr!
        [[nodiscard]]
        constexpr u16 days_in_month() const noexcept {
            return gregorian::days_in_month(year, month);
        }

        // predicates!
        [[nodiscard]]
        constexpr bool is_leap() const noexcept {
            return gregorian::is_leap(year);
        }

        [[nodiscard]]
        constexpr bool is_start_of_month() const noexcept {
            return cmpeq(day, u16{1});         
        }

        [[nodiscard]]
        constexpr bool is_end_of_month() const noexcept {
            return cmpeq(day, days_in_month());         
        }
        
        [[nodiscard]]
        constexpr bool is_start_of_year() const noexcept {
            return (is_start_of_month() &&
                cmpeq(month, u16{1}));         
        }
        
        [[nodiscard]]
        constexpr bool is_end_of_year() const noexcept {
            return (cmpeq(day, u16{31}) && 
                cmpeq(month, u16{12}));         
        }
    };
} // namespace tts.
