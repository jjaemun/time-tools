#pragma once


#include "tts/date/date.hpp"


namespace tts {
    // safe copy-from-conversions.
    [[nodiscard]]
    Date from_unix_serial(i32 serial) {
        return Date::from_unix_serial(serial);
    }

    [[nodiscard]]
    Date from_excel_serial(i32 serial) {
        return Date::from_excel_serial(serial);
    }

    [[nodiscard]]
    Date from_murex_serial(i32 serial) {
        return Date::from_murex_serial(serial);
    }

    [[nodiscard]]
    Date from_julian_serial(i32 serial) {
        return Date::from_julian_serial(serial);
    }

    [[nodiscard]]
    Date from_civil(CivilDate civil) {
        return Date::from_civil(civil);
    }
 
    // unsafe copy-from-conversions.
    [[nodiscard]]
    constexpr Date from_unix_serial_unsafe(i32 serial) noexcept {
        return Date::from_unix_serial_unsafe(serial);
    }

    [[nodiscard]]
    constexpr Date from_excel_serial_unsafe(i32 serial) noexcept {
        return Date::from_excel_serial_unsafe(serial);
    }

    [[nodiscard]]
    constexpr Date from_murex_serial_unsafe(i32 serial) noexcept {
        return Date::from_murex_serial_unsafe(serial);
    }

    [[nodiscard]]
    constexpr Date from_julian_serial_unsafe(i32 serial) noexcept {
        return Date::from_julian_serial_unsafe(serial);
    }

    [[nodiscard]]
    constexpr Date from_civil_unsafe(CivilDate civil) noexcept {
        return Date::from_civil_unsafe(civil);
    }
    
    // copy-to-conversions.
    [[nodiscard]]
    constexpr i32 to_unix_serial(Date date) noexcept {
        return  date.to_unix_serial();
    }

    [[nodiscard]]
    constexpr i32 to_excel_serial(Date date) noexcept {
        return  date.to_excel_serial();
    }

    [[nodiscard]]
    constexpr i32 to_murex_serial(Date date) noexcept {
        return  date.to_murex_serial();
    }

    [[nodiscard]]
    constexpr i32 to_julian_serial(Date date) noexcept {
        return  date.to_julian_serial();
    }
 
    [[nodiscard]]
    constexpr CivilDate to_civil(Date date) noexcept {
        return  date.to_civil();
    }
} // namespace tts.

