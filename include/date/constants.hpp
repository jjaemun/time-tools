#pragma once


#include "epoch.hpp"


namespace tts {

    /**
     * Internally tts uses unix epoch convention for serials, and so all dates
     * are expressed relative to the origin 1970-01-01. Additionally, dates are
     * restricted to the inclusive interval between 1980-01-01 and 2200-12-31.
     */

    // constants.
    namespace unix::date {
        constexpr i32 OFFSET{0}; // 1970-1-1
        constexpr i32 MIN{3652};
        constexpr i32 MAX{84370};
    }

    namespace excel::date {
        constexpr i32 OFFSET{-25569}; // 1899-12-30
        constexpr i32 MIN{OFFSET + unix::date::MIN};
        constexpr i32 MAX{OFFSET + unix::date::MAX};     
    }
    
    namespace murex::date {
        constexpr i32 OFFSET{3652}; // 1980-1-1
        constexpr i32 MIN{OFFSET + unix::date::MIN};
        constexpr i32 MAX{OFFSET + unix::date::MAX};     
    }
 
    namespace julian::date {
        constexpr i32 OFFSET{-2440588}; // 4713-1-1 b.C. julian / 4714-11-24 b.C. gregorian
        constexpr i32 MIN{OFFSET + unix::date::MIN};
        constexpr i32 MAX{OFFSET + unix::date::MAX};
    }

} // namespace tts.
