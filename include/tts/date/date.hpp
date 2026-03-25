#pragma once


#include "tts/date/constants.hpp"
#include "tts/date/errors.hpp"
#include "tts/date/exceptions.hpp"
#include "tts/date/validation.hpp"
#include "tts/gregorian/gregorian.hpp"


namespace tts {
    class Date final {
    
        /** 
         * Date abstraction. Internally tracks days from
         * unix epoch (native). Guarantees valid state.
        */

    private:
        i32 value;

        // constructor!
        explicit constexpr Date(i32 value_) noexcept 
            : value(value_) {}

    public:
        // runtime-named-constructors!
    
            /**
             * Non-constexpr to avoid cryptic compile errors (if throw
             * path). General purpose constructor should be preferred. 
            */

        [[nodiscard]]
        static Date from_unix_serial(i32 serial) {
            if (!unix::date::is_valid(serial))
                throw DateError(err::date::invalid);
    
            return Date{serial};
        }
    
        [[nodiscard]]
        static Date from_excel_serial(i32 serial) {
            if (!excel::date::is_valid(serial))
                throw DateError(err::date::invalid);
    
            return Date{serial - excel::date::OFFSET};
        }

        [[nodiscard]]
        static Date from_murex_serial(i32 serial) {
            if (!murex::date::is_valid(serial))
                throw DateError(err::date::invalid);

            return Date{serial - murex::date::OFFSET};
        }

        [[nodiscard]]
        static Date from_julian_serial(i32 serial) {
            if (!julian::date::is_valid(serial))
                throw DateError(err::date::invalid);

            return Date{serial - julian::date::OFFSET};
        }

        [[nodiscard]]
        static Date from_civil(CivilDate civil) {
            const auto serial = gregorian::unix_serial_from_civil(civil);
            if (!unix::date::is_valid(serial))
                throw DateError(err::date::invalid);

            return Date{serial};
        }

        // compile-time-named-constructors!

            /**
             * Beware **unsafe**, should be avoided unless date is compile
             * time valid.
            */

        [[nodiscard]]
        static constexpr Date from_unix_serial_unsafe(i32 serial) noexcept {
            return Date{serial};
        }
    
        [[nodiscard]]
        static constexpr Date from_excel_serial_unsafe(i32 serial) noexcept {
            return Date{serial - excel::date::OFFSET};
        }

        [[nodiscard]]
        static constexpr Date from_murex_serial_unsafe(i32 serial) noexcept {
            return Date{serial - murex::date::OFFSET};
        }

        [[nodiscard]]
        static constexpr Date from_julian_serial_unsafe(i32 serial) noexcept {
            return Date{serial - julian::date::OFFSET};
        }

        [[nodiscard]]
        static constexpr Date from_civil_unsafe(CivilDate civil) noexcept {
            const auto serial = gregorian::unix_serial_from_civil(civil);
            return Date{serial};
        }

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
            return gregorian::civil_from_unix_serial(value);
        }

        // immutable-ref-accessor!
        [[nodiscard]]
        constexpr const i32 &as_unix_serial() const noexcept {
            return value;
        }

        // mutable-ref-accessor!
        constexpr i32 &as_mut_unix_serial() noexcept {

            /**
             * Beware **unsafe**, it invokes mutability and so maintaining 
             * a valid state is the callee's responsibility.
            */

            return value;
        }       

        // gregorian decompositions!
        [[nodiscard]]
        constexpr i32 year() const noexcept {
            return to_civil().get_year();
        }

        [[nodiscard]]
        constexpr u16 month() const noexcept {
            return to_civil().get_month();
        }

        [[nodiscard]]
        constexpr u16 day() const noexcept {
            return to_civil().get_day();
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
