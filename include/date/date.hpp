#pragma once


#include "types.hpp"


namespace tts {

    namespace detail {

        inline bool is_leap_year(int year) {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }

    }

    class Date final {
        public:
            i32 value;

        Date(int year, int month, int day) {

            // TODO validate input

            int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            int total = 0;

            // unix as reference
            // adding completed years
            for(int reference_year = unix::date::YEAR; reference_year < year; ++reference_year)
            {
                total += detail::is_leap_year(reference_year) ? 366 : 365;
            }

            // adding current year months
            for(int reference_month = unix::date::MONTH; reference_month < month; ++reference_month)
            {
                total += month_days[reference_month - 1];
                if (reference_month == 2 && detail::is_leap_year(year))
                    total += 1;
            }

            // adding current month days
            total += day;

            value = total;
        }

        // copy-accessors!
        [[nodiscard]] 
        inline constexpr i32 to_serial_date(void) const {
            return value;
        }
    };

} // namespace tts.
