#pragma once


#include <string>


namespace tts::err {
    // types!
    enum class holidays {
        invalid,
        empty
    };

    // descriptors!
    [[nodiscard]]
    inline std::string to_str(holidays code) {

        /**
         * Converts holidays submodule error code to str.
        */

        switch (code) {
            case (holidays::invalid):
                return "Cannot check Date outside holidays interval.";

            case (holidays::empty):
                return "Undefined behaviour on empty Dates vector access.";

            default:
                // c++23 only std::unreachable().
                __builtin_unreachable(); 
        }
    }
} // namespace tts::err.


