#pragma once


#include "types.hpp"


namespace tts {
    class Date final {
        public:
            i32 value;

        // copy-accessors!
        [[nodiscard]] 
        inline constexpr i32 to_serial_date(void) const {
            return value;
        }
    };
} // namespace tts.
