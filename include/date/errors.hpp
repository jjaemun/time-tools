#pragma once


#include <string_view>
#include <utility>


namespace tts::err {
    // types!
    enum class date {
        invalid
    };

    // descriptors!
    inline std::string_view to_str(date code) {

        /**
         * Converts date submodule error code to str view.
        */

        switch (code) {
            case (date::invalid):
                return "Date outside valid interval.";
            
            default:
                std::unreachable();
        }
    }
} // namespace tts::err.


