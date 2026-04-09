#pragma once


#include <string>
#include <functional>


#include "tts/tenors/tenors.hpp"


namespace std {
    // hash!
    template <>
    struct hash<tts::Tenor> {

        /**
         * Performance hit due to str tform; however it is the simplest 
         * method to differentiate tenors. Not a final decision.
        */

        [[nodiscard]]
        std::size_t operator()(const tts::Tenor &tenor) const noexcept {
            return std::hash<std::string>{}(tenor.to_str());
        }
    };
} // namespace std.



