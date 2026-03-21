#pragma once


#include "constants.hpp"
#include "date.hpp"
#include "exceptions.hpp"
#include "validation.hpp"


namespace tts {
    
    // copy-to-conversions.
    [[nodiscard]]
    constexpr i32 to_unix_serial(Date date) noexcept {
        return  date.value;
    }

    [[nodiscard]]
    constexpr i32 to_excel_serial(Date date) noexcept {
        return  date.value + excel::date::OFFSET;
    }
    [[nodiscard]]
    constexpr i32 to_murex_serial(Date date) noexcept {
        return  date.value + murex::date::OFFSET;
    }
    [[nodiscard]]
    constexpr i32 to_julian_serial(Date date) noexcept {
        return  date.value + julian::date::OFFSET;
    }
 
    // copy-from-conversions.
    [[nodiscard]]
    constexpr Date from_unix_serial(i32 serial) {
        if (!unix::date::is_valid(serial))
            throw DateError(err::date::invalid);

        return Date{serial};
    }

    [[nodiscard]]
    constexpr Date from_excel_serial(i32 serial) {
        if (!excel::date::is_valid(serial))
            throw DateError(err::date::invalid);

        return Date{serial - excel::date::OFFSET};
    }

    [[nodiscard]]
    constexpr Date from_murex_serial(i32 serial) {
        if (!murex::date::is_valid(serial))
            throw DateError(err::date::invalid);

        return Date{serial - murex::date::OFFSET};
    }

    [[nodiscard]]
    constexpr Date from_julian_serial(i32 serial) {
        if (!julian::date::is_valid(serial))
            throw DateError(err::date::invalid);

        return Date{serial - julian::date::OFFSET};
    }

} // namespace tts.

