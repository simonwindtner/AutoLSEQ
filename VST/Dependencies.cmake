################################################################################
# FetchContent
################################################################################

include(FetchContent)

################################################################################
# JUCE - AU/VST plugin framework
################################################################################

FetchContent_Declare(
  JUCE
  GIT_REPOSITORY https://github.com/juce-framework/JUCE
  GIT_TAG        7.0.5)
FetchContent_MakeAvailable(JUCE)

################################################################################
# rapidCSV - Library for parsing CSV files
################################################################################

FetchContent_Declare(
  rapidCSV
  GIT_REPOSITORY https://github.com/d99kris/rapidcsv
  GIT_TAG        v8.69)
FetchContent_MakeAvailable(rapidCSV)
include_directories(${rapidcsv_SOURCE_DIR}/src)
