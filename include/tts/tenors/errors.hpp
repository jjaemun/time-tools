#pragma once


#include <string>


namespace tts::err {
    // types!
    enum class tenor {
        invalid,
        empty,
        conversion
    };

    // descriptors!
    [[nodiscard]]
    inline std::string to_str(tenor code) {

        /**
         * Converts date submodule error code to str.
        */

        switch (code) {
            case (tenor::invalid):
                return "Invalid string pattern.";
            
            case (tenor::empty):
                return "No tenor provided.";

            case (tenor::conversion):
                return "Ill-formed conversion with linear and non-linear durations."

            default:
                // c++23 only std::unreachable().
                __builtin_unreachable(); 
        }
    }
} // namespace tts::err.


