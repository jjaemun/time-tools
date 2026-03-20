#pragma once


#include "types.hpp"


namespace tts {

    /**
     * Dates require that we track some time origin or 'epoch', which determines
     * their interpretation. Conversions to/from different applications must be 
     * carefully handled to preserve temporal significance.
    */

    // types.
    enum class epoch {
        unix,
        excel,
        murex,
        julian
    };

} // namespace tts.
