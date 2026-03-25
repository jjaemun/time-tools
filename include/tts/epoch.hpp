#pragma once


#include "tts/types.hpp"


#ifdef unix
#undef unix
#endif


namespace tts {
    // epochs!
    enum class epoch {
        unix,
        excel,
        murex,
        julian
    };
} // namespace tts.
