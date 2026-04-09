#pragma once


#include <stdexcept>
#include "tts/regex/errors.hpp"


namespace tts {
    // exceptions!
    class RegexError : public std::runtime_error {
        
        /**
         * Custom exception class for regex specific
         * error handling.
        */

    public:
        explicit RegexError(const err::regex &code_) :
            std::runtime_error(err::to_str(code_)) {}
    };
} // namespace tts.
