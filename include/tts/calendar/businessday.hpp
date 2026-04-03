#pragma once 


namespace tts::conventions {
    // conventions!
    enum class businessday {
        unadjusted,
        following,
        modified_following,
        preceding,
        modified_preceding,
        nearest
    };
} // namespace tts::conventions.
