#pragma once


#include "constants.hpp"


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
        constexpr i32 to_unix_serial(void) const noexcept {
            return value;
        }

        [[nodiscard]] 
        constexpr i32 to_excel_serial(void) const noexcept {
            return value + excel::date::OFFSET;
        }

        [[nodiscard]] 
        constexpr i32 to_murex_serial(void) const noexcept {
            return value + murex::date::OFFSET;
        }
        
        [[nodiscard]] 
        constexpr i32 to_julian_serial(void) const noexcept {
            return value + julian::date::OFFSET;
        }

        // immutable-ref-accessor!
        [[nodiscard]]
        constexpr const i32 &as_unix_serial(void) const noexcept {
            return value;
        }

        // mutable-ref-accessor!
        constexpr i32 &as_mut_unix_serial(void) noexcept {
            return value;
        }       
  
    };
} // namespace tts.
