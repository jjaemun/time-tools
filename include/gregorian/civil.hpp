#pragma once


#include "types.hpp"


namespace tts {
    class CivilDate final {
    
        /** 
         * Human-readable (proletic gregorian) date abstraction. It is format
         * agnostic, in the sense that any representation that we decide to 
         * impose is attributed at callsite through the fmt module.
        */

    public:
        i32 year;
        i32 month;
        i32 day;
    };
} // namespace tts.
