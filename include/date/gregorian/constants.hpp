#pragma once


#include "types.hpp"


namespace tts::gregorian {
    // constants! 
    constexpr i32 OFFSET{719468}; 
 
        /**
         * Proleptic gregorian epoch shift (from unix), sets origin
         * at 0000-03-01.
        */

    constexpr i32 DAYS{365};
    
        /**
         * Days in a year.
        */

    constexpr i32 ENCODING{153};

        /**
         * Month encoding for 30/31 day pattern starting from March 1st, 
         * to push February as the last month of the year. This increases 
         * computation stability whenever there are leap years.
        */

    constexpr i32 CYCLE4Y{1460};

        /**
         * Days in a 4-year cycle excluding leap days.
        */

    constexpr i32 CYCLE100Y{36524};

        /**
         * Days in a 100-year cycle excluding the 400-year correction.
        */

    namespace era {
        constexpr i32 YEARS{400}; 

            /**
             * Years in an era.
            */

        constexpr i32 DAYS{146097}; 

            /**
             * Days in an era.
            */

   } // namespace era.

    namespace year {
        constexpr i32 MIN{1980};
            
            /**
             * Years lower bound.
            */

        constexpr i32 MAX{2200};
            
            /**
             * Years upper bound.
            */

    } // namespace year.

    namespace month {
        constexpr u16 MIN{1};
            
            /**
             * Civil date months lower bound.
            */

        constexpr u16 MAX{12};
            
            /**
             * Civil date months upper bound.
            */

    } // namespace year.

    namespace day {
        constexpr u16 MIN{1};
            
            /**
             * Civil date days lower bound.
            */

        constexpr u16 MAX{31};
            
            /**
             * Civil date days upper bound.
            */

    } // namespace year.
} // namespace tts::gregorian.
