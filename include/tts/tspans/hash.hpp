#pragma once


#include <functional>
#include "tts/date/tspan.hpp"


namespace std {
    // hash!
    template <>
    struct hash<tts::Seconds> {
        // seconds.
        [[nodiscard]]
        std::size_t operator()(const tts::Seconds &seconds) const noexcept {
            return std::hash<tts::i64>{}(seconds.as_count());
        }
    };

    template <>
    struct hash<tts::Minutes> {
        //minutes.
        [[nodiscard]]
        std::size_t operator()(const tts::Minutes &minutes) const noexcept {
            return std::hash<tts::i32>{}(minutes.as_count());
        }
    };

    template <>
    struct hash<tts::Hours> {
        // hours.
        [[nodiscard]]
        std::size_t operator()(const tts::Hours &hours) const noexcept {
            return std::hash<tts::i32>{}(hours.as_count());
        }
    };

    template <>
    struct hash<tts::Days> {
        // days. 
        [[nodiscard]]
        std::size_t operator()(const tts::Days &days) const noexcept {
            return std::hash<tts::i32>{}(days.as_count());
        }
    };


    template <>
    struct hash<tts::Weeks> {
        // weeks.
        [[nodiscard]]
        std::size_t operator()(const tts::Weeks &weeks) const noexcept {
            return std::hash<tts::i32>{}(weeks.as_count());
        }
    };
} // namespace std.
