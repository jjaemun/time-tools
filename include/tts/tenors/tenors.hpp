#pragma once 


#include "tts/types.hpp"
#include "tts/periods/tenors/units.hpp"
#include "tts/periods/tenors/regex.hpp"


namespace tts {
    class Tenor final {
        
        /**
         * Tenor (period) abstraction. Can be either linear or 
         * non-linear. Delegates to strong types downstream.
        */

    private:
        i32 value;
        tenor::units units;

    public:


} // namespace tts.
