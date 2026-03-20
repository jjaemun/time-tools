#pragma once


#include "types.hpp"


namespace tts {
    // epochs.
    enum class epoch {
        unix,
        excel,
        murex,
        julian
    };

    namespace unix {
        constexpr u32 OFFSET = ;
        constexpr u32 MIN = ;
        constexpr u32 MAX = ;
    } // namespace unix.
 
    namespace excel {
        constexpr u32 OFFSET = ;
        constexpr u32 MIN = ;
        constexpr u32 MAX = ;
    } // namespace excel.
    
    namespace murex {
        constexpr u32 OFFSET = ;
        constexpr u32 MIN = ;
        constexpr u32 MAX = ;
    } // namespace murex.
 
    namespace julian {
        constexpr u32 OFFSET = ;
        constexpr u32 MIN = ;
        constexpr u32 MAX = ;
    } // namespace julian.
} // namespace tts.

