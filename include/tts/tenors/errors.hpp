#pragma once


#include <string>


namespace tts::err {
    // types!
    enum class tenor {
        invalid,
        empty 
    };

    // descriptors!
    [[nodiscard]]
    inline std::string to_str(tenor code) {

        /**
         * Converts date submodule error code to str.
        */

        switch (code) {
            case (tenor::invalid):
                return "String pattern does not match.";
            
            case (tenor::empty):
                return "No tenor provided.";

            default:
                // c++23 only std::unreachable().
                __builtin_unreachable(); 
        }
    }
} // namespace tts::err.


