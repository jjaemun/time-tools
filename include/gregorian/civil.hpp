#pragma once


#include "types.hpp"


namespace tts {
    class CivilDate final {
    
        /** 
         * Human-readable (proletic gregorian) date abstraction. Should only
         * exist through tts::Date at the boundary, i.e., no native computations.
        */

    public:
        i32 year;
        i32 month;
        i32 day;
    };
} // namespace tts.
