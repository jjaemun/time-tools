# --gregorian.

add_executable(
    convtests
    convtests.cpp
)

target_link_libraries(
    convtests PRIVATE
    GTest::gtest_main
    tts
)
