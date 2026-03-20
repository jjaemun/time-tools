#pragma once


#include "epoch.hpp"


namespace tts {

    /**
     * Internally tts uses unix epoch convention for serials, and so all dates
     * are expressed relative to the origin 1970-01-01. Additionally, dates are
     * restricted to the (inclusive) interval 1980-01-01 and 2200-12-31.
     */

    // constants.
    namespace unix::date {
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

