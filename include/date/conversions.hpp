#pragma once


#include "constants.hpp"
#include "date.hpp"


namespace tts {
    
    // copy-to-conversions.
    [[nodiscard]]
    constexpr i32 to_unix_date(Date date) {
        return  date.value;
    }

    [[nodiscard]]
    constexpr i32 to_excel_date(Date date) {
        return  date.value + excel::date::OFFSET;
    }

    [[nodiscard]]
    constexpr i32 to_julian_date(Date date) {
        return  date.value + julian::date::OFFSET;
    }
 
    // copy-from-conversions.
    [[nodiscard]]
    constexpr Date from_unix_date(i32 serial) {
        assert_valid(serial, unix::date::MIN, unix::date::MAX);
        return Date{serial};
    }

    [[nodiscard]]
    constexpr Date from_excel_date(i32 serial) {
        return Date{serial - excel::date::OFFSET};
    }

    [[nodiscard]]
    constexpr Date from_julian_date(i32 serial) {
        return Date{serial - julian::date::OFFSET};
    }

} // namespace tts.

