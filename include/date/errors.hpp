#pragma once


#include <string>


namespace tts::err {
    // types!
    enum class date {
        invalid,
        overflow,
        underflow
    };

    // descriptors!
    [[nodiscard]]
    inline std::string to_str(date code) {

        /**
         * Converts date submodule error code to str view.
        */

        switch (code) {
            case (date::invalid):
                return "Date outside valid interval.";
            
            case (date::overflow):
                return "Date arithmetic overflow.";

            case (date::underflow):
                return "Date arithmetic underflow.";

            default:
                // c++23 only std::unreachable().
                __builtin_unreachable(); 
        }
    }
} // namespace tts::err.


