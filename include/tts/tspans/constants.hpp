#pragma once


#include "tts/types.hpp"


namespace tts::timespan {
    // constants!
    constexpr i64 SECONDS{1};

        /**
         * Number of seconds in a second. Base (reference) unit 
         * for timespans.
        */

    constexpr i64 MINUTES{60};
        
        /**
         * Number of seconds in a minute.
        */   
 
    constexpr i64 HOURS{60 * 60};
        
        /**
         * Number of seconds in an hour.
        */   
 
    constexpr i64 DAYS{24 * 60 * 60};
        
        /**
         * Number of seconds in a day.
        */   
 
    constexpr i64 WEEKS{7 * 24 * 60 * 60};
        
        /**
         * Number of seconds in a week.
        */   

} // namespace tts::timespan.
