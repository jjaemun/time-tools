#pragma once 


#include <tuple>


#include "tts/types.hpp"
#include "tts/gregorian/prelude.hpp"


namespace tts::holidays {
    // algorithms!
    [[nodiscard]]
    constexpr std::tuple<i32, u16, u16> ymd_easter_from_year(i32 year) noexcept {
        
        /**
         * Computes easter sunday for a given year (Astronomical Algorihtms, 
         * Willman-Bell ch.9, Meeus J., 1998). Valid if year is valid only.
        */
   
        // intermediates.
        
        // metonic moon cycle (every 19 years).
        const auto metonic = year % 19;
        // current century.
        const auto century = year / 100;
        // year of century.
        const auto yoc = year % 100;

        
        // leap years in current century.
        const auto centleaps = century / 4;
        // non-leap years.
        const auto centnoleaps = century % 4;
        // current year leaps.
        const auto yearleaps = yoc / 4;
        // current year non-leaps.
        const auto yearnoleaps = yoc % 4;

       // leap years correction.
        const auto leapcorr = (century + 8) / 25;
        // moon correction.
        const auto mooncorr = (century - leapcorr + 1) / 3;
        // paschal full mooon date.
        const auto epact = (19 * metonic + century - 
            centleaps - mooncorr + 15) % 30;

        // weekday alignment.
        const auto alignment = (32 + 2 * centnoleaps + 2 * 
            yearleaps - epact - yearnoleaps) % 7;
        // easter conditioning / shifting.
        const auto condition = (metonic + 11 * epact + 
            22 * alignment) / 451;

        // civil date components. 
        const auto month = static_cast<u16>
            ((epact+ alignment - 7 * condition + 
                114) / 31);
        const auto day = static_cast<u16>
            (((epact + alignment - 7 * condition + 
                114) % 31) + 1);

        return std::make_tuple(year, month, day);
    }
}
