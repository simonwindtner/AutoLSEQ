target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
  Main.cpp
  PluginProcessor.cpp
  PluginEditor.cpp
  PluginState.cpp
  StereoFilter.cpp
  FilterBank.cpp
  CoefficientParser.cpp
)
