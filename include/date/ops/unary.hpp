#pragma once 


#include "assert.hpp"
#include "date/constants.hpp"
#include "date/date.hpp"


namespace tts {
    // prefix!
    inline Date &operator++(Date &date) noexcept {
        assert_lt(date.value, unix::date::MAX);
        ++date.value;
        return date;
    }
    
    inline Date &operator--(Date &date) noexcept {
        assert_gt(date.value, unix::date::MIN);
        --date.value;
        return date;
    }

    //postfix!
    [[nodiscard]]
    inline Date operator++(Date &date, int) noexcept {
        assert_lt(date.value, unix::date::MAX);
        Date deepcopy{date};
        ++date.value;
        return deepcopy;
    }

    [[nodiscard]]
    inline Date operator--(Date &date, int) noexcept {
        assert_gt(date.value, unix::date::MIN);
        Date deepcopy{date};
        --date.value;
        return deepcopy;
    }
} //namespace tts.
