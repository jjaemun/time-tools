#pragma once


#include "civil.hpp"
#include "cmp.hpp"
#include "constants.hpp"


namespace tts::gregorian {
    // algorithms! (H. Hinnant, (2021))
    [[nodiscard]] 
    constexpr u16 encode_month(i32 month) noexcept {
          
        /**
         * Returns integer in the range [0, 11] denoting the 
         * encoded year month (March-first) from true month.
        */       

        if (cmpgt(month, 2))
            return month - 3;
        else
            return month + 9;
    }
 
    [[nodiscard]] 
    constexpr u16 decode_month(i32 emonth) noexcept {
          
        /**
         * Returns integer in the range [1, 12] denoting the 
         * true year month (January-first) from encoded month.
        */       

        if (cmplt(emonth, 10))
            return emonth + 3;
        else
            return emonth - 9;
    }

   [[nodiscard]]
    constexpr i32 emonth_from_yday(i32 yday) noexcept {
        
        /**
         * Returns integer in the range [0, 11] denoting the 
         * encoded year month (March-first) from year day.
        */

        return (5 * yday + 2) / ENCODING;
    }

    [[nodiscard]]
    constexpr i32 yday_from_emonth(i32 emonth) noexcept {
         
        /**
         * Returns integer in the range [0, 365] denoting the 
         * year day from encoded month (March-first calendar).
        */

        return (ENCODING * emonth + 2) / 5;
    }

    [[nodiscard]]
    constexpr i32 mday_from_yday_and_emonth(i32 yday, i32 emonth) noexcept {
         
        /**
         * Returns integer in the range [1, 31] denoting the 
         * month day from year day and encoded month.
        */

        return yday - (yday_from_emonth(emonth)) + 1;
    }

    [[nodiscard]]
    constexpr i32 eyear_from_eday(i32 eday) noexcept {
         
        /**
         * Returns integer in the range [0, 399] denoting the 
         * year of era from day of era with leap correction.
        */

        return (eday - (eday / CYCLE4Y) +
           (eday / CYCLE100Y) - (eday / era::DAYS)) / DAYS;
    }

    [[nodiscard]]
    constexpr i32 eday_from_eyear(i32 eyear) noexcept {
         
        /**
         * Returns integer in the range [0, 146096] denoting 
         * the day of era from year of era.
        */

        return (DAYS * eyear + (eyear / 4)
            - (eyear / 100));
    }

    [[nodiscard]] 
    constexpr i32 yday_from_eday(i32 eday) noexcept {
        
        /**
         * Returns integer in the range [1, 365] denoting the 
         * year day from day of era.
        */
        
        const auto eyear = eyear_from_eday(eday);
        return (eday - (DAYS * eyear) +
            (eyear / 4) - (eyear / 100));
    }

    [[nodiscard]]
    constexpr i32 yday_from_eday_and_eyear(i32 eday, i32 eyear) noexcept {
        
        /**
         * Returns integer in the range [1, 365] denoting the 
         * year day from day of era and year of era.
        */
        
        return (eday - (DAYS * eyear) +
            (eyear / 4) - (eyear / 100));
    }

    [[nodiscard]]
    constexpr i32 eday_from_yday_and_eyear(i32 yday, i32 eyear) noexcept {
        
        /**
         * Returns integer in the range [1, 146096] denoting 
         * the day of era from year day and year of era.
        */
        
        return ((DAYS * eyear) + (eyear / 4) - 
            (eyear / 100) + yday);
    }

    [[nodiscard]]
    constexpr CivilDate civil_from_serial(i32 serial) noexcept {
        
        /**
         * Returns civil (human-readable) date from unix 
         * serial.
        */

        const auto gregorian = serial + OFFSET;
       
        // era.
        i32 current{}; 
        if (cmpge(gregorian, 0))
            current = gregorian / 
                era::DAYS;
        else
            // euclidean division.
            current = ((gregorian- era::DAYS) / 
                era::DAYS);
 
        // day of era.
        const auto eday = gregorian - current 
            * era::DAYS; 
        // year of era.
        const auto (eyear = eday - (eday / CYCLE4Y) + 
            (eday / CYCLE100Y) - (eday / era::DAYS)) / DAYS;  

        // year.
        const auto year = eyear + current 
            * era::YEARS;
        // day of year.
        const auto yday = eday - ((DAYS * eyear) +
            (eyear / 4) - (eyear / 100));

        // march-first encoded month.
        const auto emonth = (5 * yday + 2) / ENCODING;
        // standard month.
        const auto month = decode_month(emonth);
        // correction if month from previous year.
        const auto correction = static_cast<i32>(month <= 2);
        // month day.
        const auto day = static_cast<u16>
            (yday - (ENCODING * emonth + 2) 
                / 5 + 1);        

        return CivilDate{
            year + correction,
            month,
            day
        };
    }

    [[nodiscard]]
    constexpr i32 serial_from_civil(CivilDate civil) noexcept {

        /**
         * Returns unix serial from civil (human-readable) 
         * date.
         */

        const auto emonth = encode_month(civil.month);
        const auto year = civil.year - 
            static_cast<i32>(civil.month <= 2);

        i32 current{};
        if (cmpge(year, 0))
            current = year / era::YEARS;
        else
            // euclidean division.
            current = ((year - era::YEARS + 1)
                / era::YEARS);

        // year of era.
        const auto eyear = year - current * 
            era::YEARS;
        // day of year.
        const auto yday = civil.day - 1 + 
            (ENCODING * emonth + 2) / 5;
        // day of era.
        const auto eday = ((DAYS * eyear) + 
            (eyear / 4) - (eyear / 100) + yday);

        return (current * era::DAYS + 
            eday - OFFSET);
    }
} // namespace gregorian.
