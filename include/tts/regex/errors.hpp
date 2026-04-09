#pragma once


#include <string>


namespace tts::err {
    // types!
    enum class regex {
        invalid
    };

    // descriptors!
    [[nodiscard]]
    inline std::string to_str(regex code) {

        /**
         * Converts date submodule error code to str.
        */

        switch (code) {
            case (regex::invalid):
                return "String pattern cannot be parsed.";
            
            default:
                // c++23 only std::unreachable().
                __builtin_unreachable(); 
        }
    }
} // namespace tts::err.


