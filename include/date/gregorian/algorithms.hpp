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
