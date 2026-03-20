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
        constexpr i32 OFFSET{0};
        constexpr i32 MIN{3652};
        constexpr i32 MAX{84370};
    }

    namespace excel::date {
        constexpr i32 OFFSET{25569};
        constexpr i32 MIN{OFFSET + unix::date::MIN};
        constexpr i32 MAX{OFFSET + unix::date::MAX};     
    }
    
    namespace murex::date {
        //TODO.
    }
 
    namespace julian::date {
        constexpr i32 OFFSET{2440588};
        constexpr i32 MIN{OFFSET + unix::date::MIN};
        constexpr i32 MAX{OFFSET + unix::date::MAX};
    }

} // namespace tts.
