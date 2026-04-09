#pragma once


#include <stdexcept>
#include "tts/tenors/errors.hpp"


namespace tts {
    // exceptions!
    class TenorError : public std::runtime_error {
        
        /**
         * Custom exception class for tenor specific
         * error handling.
        */

    public:
        explicit TenorError(const err::tenor &code_) :
            std::runtime_error(err::to_str(code_)) {}
    };
} // namespace tts.
