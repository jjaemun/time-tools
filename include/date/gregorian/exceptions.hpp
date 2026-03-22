#pragma once


#include <stdexcept>
#include "errors.hpp"


namespace tts {
    // exceptions!
    class CivilDateError : public std::runtime_error {
        
        /**
         * Custom exception class for CivilDate specific
         * error handling.
        */

    public:
        explicit CivilDateError(const err::gregorian &code_) :
            std::runtime_error(err::to_str(code_)) {}
    };
} // namespace tts.
