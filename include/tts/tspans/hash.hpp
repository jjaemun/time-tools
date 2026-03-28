#pragma once


#include <functional>
#include "tts/tspans/tspans.hpp"


namespace std {
    // hash!
    
        /**
         * It is not immediately clear whether a generalised hash should be favoured 
         * over explicit specializations for the public aliases. There is a tradeoff 
         * between lines of code, explicitness and coverage. Hazardous?
        */

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
