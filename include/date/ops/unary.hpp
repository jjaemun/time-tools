#pragma once 


#include "cmp.hpp"
#include "date/constants.hpp"
#include "date/exceptions.hpp"
#include "date/date.hpp"


namespace tts {
    // prefix!
    inline Date &operator++(Date &date) {
        if (!cmplt(date.value, unix::date::MAX))
            throw DateError(err::date::overflow);

        ++date.value;
        return date;
    }
    
    inline Date &operator--(Date &date) {
        if (!cmpgt(date.value, unix::date::MIN))
            throw DateError(err::date::underflow);

        --date.value;
        return date;
    }

    //postfix!
    [[nodiscard]]
    inline Date operator++(Date &date, int) {
        if (!cmplt(date.value, unix::date::MAX))
            throw DateError(err::date::overflow);

        Date deepcopy{date};
        ++date.value;

        return deepcopy;
    }

    [[nodiscard]]
    inline Date operator--(Date &date, int) {
        if (!cmpgt(date.value, unix::date::MIN))
            throw DateError(err::date::underflow);

        Date deepcopy{date};
        --date.value;

        return deepcopy;
    }
} //namespace tts.
