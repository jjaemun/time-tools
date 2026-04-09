#pragma once


#include <string_view>
#include <regex>


namespace tts::regex {
    // validation!
    inline bool matches(std::string_view str, const std::regex &pattern) {
        
        /**
         * Checks whether string parse is valid.
        */

        return std::regex_match(str.begin(), str.end(), pattern);
    }
} // namespace tts::regex.
