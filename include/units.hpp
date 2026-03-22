#pragma once


#include "types.hpp"


namespace tts {
    // units!
    enum class month : u16 {
        january   = 1,
        february  = 2,
        march     = 3,
        april     = 4,
        may       = 5,
        june      = 6,
        july      = 7,
        august    = 8,
        september = 9,
        october   = 10,
        november  = 11,
        december  = 12,
    };

    enum class weekday : u16 {
        monday    = 0,
        tuesday   = 1,
        wednesday = 2,
        thursday  = 3,
        friday    = 4,
        saturday  = 5,
        sunday    = 6,
    };
} // namespace tts.
