#pragma once 


#include "tts/cmp.hpp"
#include "tts/date/constants.hpp"
#include "tts/date/date.hpp"
#include "tts/date/exceptions.hpp"


namespace tts {
    // prefix!
    inline Date &operator++(Date &date) {
        if (!cmplt(date.to_unix_serial(), unix::date::MAX))
            throw DateError(err::date::overflow);

        ++date.as_mut_unix_serial();
        return date;
    }
    
    inline Date &operator--(Date &date) {
        if (!cmpgt(date.to_unix_serial(), unix::date::MIN))
            throw DateError(err::date::underflow);

        --date.as_mut_unix_serial();
        return date;
    }

    //postfix!
    inline Date operator++(Date &date, int) {
        if (!cmplt(date.to_unix_serial(), unix::date::MAX))
            throw DateError(err::date::overflow);

        const auto deepcopy = date;
        ++date.as_mut_unix_serial();

        return deepcopy;
    }

    inline Date operator--(Date &date, int) {
        if (!cmpgt(date.to_unix_serial(), unix::date::MIN))
            throw DateError(err::date::underflow);

        const auto deepcopy = date;
        --date.as_mut_unix_serial();

        return deepcopy;
    }

    // plus!
    constexpr Date operator+(Date date) noexcept {

        /**
         * Value semantics follow from Date being trivially copyable.
        */

        // no-op.
        return date;
    }

    // neg!
    constexpr Date operator-(Date date) = delete;
    
        /**
         * Date negation is unsafe by definition. Every date is valid by 
         * construction  (positive almost surely, relative to the epoch).
         * Negatives are surely below the  minimum date, thus invalid.
        */
        
} //namespace tts.
