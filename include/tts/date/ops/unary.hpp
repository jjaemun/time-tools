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
    [[nodiscard]]
    inline Date operator++(Date &date, int) {
        if (!cmplt(date.to_unix_serial(), unix::date::MAX))
            throw DateError(err::date::overflow);

        auto deepcopy = date;
        ++date.as_mut_unix_serial();

        return deepcopy;
    }

    [[nodiscard]]
    inline Date operator--(Date &date, int) {
        if (!cmpgt(date.to_unix_serial(), unix::date::MIN))
            throw DateError(err::date::underflow);

        auto deepcopy = date;
        --date.as_mut_unix_serial();

        return deepcopy;
    }
} //namespace tts.
