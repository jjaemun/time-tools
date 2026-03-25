#pragma once


#include "tts/cmp.hpp"
#include "tts/date/constants.hpp"
#include "tts/types.hpp"


namespace tts {
    // validation! 
    namespace unix::date {
        [[nodiscard]]
        constexpr bool is_valid(i32 serial) noexcept {
            return cmpge(serial, MIN) && cmple(serial, MAX);
        }
    }// namespace unix::date.

    namespace excel::date {
        [[nodiscard]]
        constexpr bool is_valid(i32 serial) noexcept {
            return cmpge(serial, MIN) && cmple(serial, MAX);
        }
    }// namespace excel::date.

    namespace murex::date {
        [[nodiscard]]
        constexpr bool is_valid(i32 serial) noexcept {
            return cmpge(serial, MIN) && cmple(serial, MAX);
        }
    }// namespace murex::date.

    namespace julian::date {
        [[nodiscard]]
        constexpr bool is_valid(i32 serial) noexcept {
            return cmpge(serial, MIN) && cmple(serial, MAX);
        }
    }// namespace julian::date.
} // namespace tts.
