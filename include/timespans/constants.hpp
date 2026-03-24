#pragma once


#include "types.hpp"


namespace tts::timespan {
    // constants!
    constexpr i32 MILLISECONDS{1};

        /**
         * Base (reference) unit for timespans.
        */

    constexpr i32 SECONDS{1'000};
        
        /**
         * Number of miliseconds in a second.
        */
 
    constexpr i32 MINUTES{60 * 1'000};
        
        /**
         * Number of miliseconds in a minute.
        */   
 
    constexpr i32 HOURS{60 * 60 * 1'000};
        
        /**
         * Number of miliseconds in an hour.
        */   
 
    constexpr i32 DAYS{24 * 60 * 60 * 1'000};
        
        /**
         * Number of miliseconds in a day.
        */   
 
    constexpr i32 WEEKS{24 * 60 * 60 * 1'000};
        
        /**
         * Number of miliseconds in a week.
        */   
} // namespace tts::timespan.
