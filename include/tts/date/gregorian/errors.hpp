#pragma once


#include <string>


namespace tts::err {
    // types!
    enum class gregorian {
        year,
        month,
        day 
    };

    // descriptors!
    [[nodiscard]]
    inline std::string to_str(gregorian code) {

        /**
         * Converts gregorian submodule error code to str.
        */

        switch (code) {
            case (gregorian::year):
                return "Year outside valid interval.";
            
            case (gregorian::month):
                return "Month outside valid interval.";

            case (gregorian::day):
                return "Day outside valid interval.";

            default:
                // c++23 only std::unreachable().
                __builtin_unreachable(); 
        }
    }
} // namespace tts::err.


