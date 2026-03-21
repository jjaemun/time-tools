#pragma once


#include "types.hpp"


#ifdef unix
#undef unix
#endif


namespace tts {

    // types.
    enum class epoch {
        unix,
        excel,
        murex,
        julian
    };

} // namespace tts.
