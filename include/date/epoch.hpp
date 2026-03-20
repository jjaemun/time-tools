#pragma once


#include "types.hpp"


namespace tts {
    // types.
    enum class epoch {
        unix,
        excel,
        murex,
        julian
    };

    // constants.
    namespace unix {
        constexpr i32 OFFSET = (i32)0;
        constexpr i32 MIN = (i32)-25567;
        constexpr i32 MAX = (i32)84557;
    } // namespace unix.
 
    namespace excel {
        constexpr i32 OFFSET = (i32)25569;
        constexpr i32 MIN = OFFSET + unix::MIN;
        constexpr i32 MAX = OFFSET + unix::MAX;     
    } // namespace excel.
    
    namespace murex {
        constexpr i32 OFFSET{};
        constexpr i32 MIN{};
        constexpr i32 MAX{};     
    } // namespace murex.
 
    namespace julian {
        constexpr i32 OFFSET = (i32)2440588;
        constexpr i32 MIN = OFFSET + unix::MIN;
        constexpr i32 MAX = OFFSET + unix::MAX;
    } // namespace julian.
} // namespace tts.
