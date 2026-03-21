#pragma once


#include "constants.hpp"


namespace tts {
    class Date final {
    
        /** 
         * Date abstraction. Internally tracks days from
         * unix epoch (native).
        */

    private:
        i32 value;

    public:
        // copy-accessors!
        [[nodiscard]] 
        inline constexpr i32 to_unix_serial(void) const {
            return value;
        }

        [[nodiscard]] 
        inline constexpr i32 to_excel_serial(void) const {
            return value + excel::date::OFFSET;
        }

        [[nodiscard]] 
        inline constexpr i32 to_murex_serial(void) const {
            return value + murex::date::OFFSET;
        }
        
        [[nodiscard]] 
        inline constexpr i32 to_julian_serial(void) const {
            return value + julian::date::OFFSET;
        }

        // mutable-ref-accessors!
        [[nodiscard]] 
        inline constexpr i32 &as_unix_serial(void) {
            return value;
        }       

    };
} // namespace tts.
