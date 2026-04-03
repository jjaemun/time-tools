#pragma once


#include <stdexcept>
#include "tts/holidays/errors.hpp"


namespace tts {
    // exceptions!
    class HolidaysError : public std::runtime_error {
        
        /**
         * Custom exception class for Holidays specific
         * error handling.
        */

    public:
        explicit HolidaysError(const err::holidays &code_) :
            std::runtime_error(err::to_str(code_)) {}
    };
} // namespace tts.
