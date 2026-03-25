#pragma once


#include <stdexcept>
#include "tts/date/errors.hpp"


namespace tts {
    // exceptions!
    class DateError : public std::runtime_error {
        
        /**
         * Custom exception class for Date specific
         * error handling.
        */

    public:
        explicit DateError(const err::date &code_) :
            std::runtime_error(err::to_str(code_)) {}
    };
} // namespace tts.
