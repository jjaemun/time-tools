#pragma once


#include "types.hpp"


namespace tts::gregorian {
    // constants! 
    constexpr i32 OFFSET{719468}; 
 
    /**
     * Proleptic gregorian epoch shift (from unix epoch),
     * sets origin at 0000-03-01.
    */

    constexpr i32 DAYS{365};
    
    /**
     * Days in a year.
    */

    constexpr i32 ENCODING{153};

    /**
     * Month encoding for 30/31 day pattern starting from 
     * March 1st, to push February as the last month of the 
     * year. This provides stability for computations since
     * a leap year will never split standard months.
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
} // namespace tts::gregorian.

