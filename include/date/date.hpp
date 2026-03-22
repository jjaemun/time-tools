#pragma once


#include "constants.hpp"
#include "gregorian/gregorian.hpp"


namespace tts {
    class Date final {
    
        /** 
         * Date abstraction. Internally tracks days from
         * unix epoch (native).
        */

    public:
        i32 value;

        // copy-accessors!
        [[nodiscard]] 
        constexpr i32 to_unix_serial() const noexcept {
            return value;
        }

        [[nodiscard]] 
        constexpr i32 to_excel_serial() const noexcept {
            return value + excel::date::OFFSET;
        }

        [[nodiscard]] 
        constexpr i32 to_murex_serial() const noexcept {
            return value + murex::date::OFFSET;
        }
        
        [[nodiscard]] 
        constexpr i32 to_julian_serial() const noexcept {
            return value + julian::date::OFFSET;
        }
        
        [[nodiscard]] 
        constexpr CivilDate to_civil() const noexcept {
            return gregorian::civil_from_serial(value);
        }

        // immutable-ref-accessor!
        [[nodiscard]]
        constexpr const i32 &as_unix_serial() const noexcept {
            return value;
        }

        // mutable-ref-accessor!
        constexpr i32 &as_mut_unix_serial() noexcept {
            return value;
        }       

        // gregorian decompositions!
        [[nodiscard]]
        constexpr i32 year() const noexcept {
            return to_civil().year;
        }

        [[nodiscard]]
        constexpr u16 month() const noexcept {
            return to_civil().month;
        }

        [[nodiscard]]
        constexpr u16 day() const noexcept {
            return to_civil().day;
        }
    };
} // namespace tts.
