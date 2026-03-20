#pragma once


#ifdef unix
#undef unix
#endif


#include "types.hpp"


namespace tts {

    // types.
    enum class epoch {
        unix,
        excel,
        murex,
        julian
    };

} // namespace tts.
