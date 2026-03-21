#pragma once


#include <stdexcept>
#include "errors.hpp"


namespace tts {
    // exceptions!
    class DateError : public std::runtime_error {
        
        /**
         * Custom exception class for Date specific
         * error handling.
        */

        public:
            explicit DateError(const err::date &code) :
                std::runtime_error(err::to_str(code)) {}
    };
} // namespace tts.
