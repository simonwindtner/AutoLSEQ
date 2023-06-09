cmake_minimum_required(VERSION 3.22)

project(PARALLEL_FILTER_PROCESSOR
    VERSION     0.1.0
    LANGUAGES   CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Cross-compile for x86 on Apple M1 machines:
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")

include(Dependencies.cmake)

juce_add_plugin(${CMAKE_PROJECT_NAME}
  COMPANY_NAME              Leon
  PLUGIN_MANUFACTURER_CODE  Leon
  PLUGIN_CODE               Filt

  # NEEDS_MIDI_INPUT must be true if IS_SYNTH is true, or AU validation will fail:
  IS_SYNTH                  FALSE
  NEEDS_MIDI_INPUT          FALSE

  FORMATS                   VST3 Standalone
  COPY_PLUGIN_AFTER_BUILD   TRUE
)

target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
  # Enabling this requires the VST2 SDK, which is no longer bundled with the
  # latest JUCE versions:
  JUCE_VST3_CAN_REPLACE_VST2=0

  # This one's important because it gets rid of the "gtk header not found" error
  # when compiling under Ubuntu:
  JUCE_WEB_BROWSER=0

  # Disabling the splash screen is only legal if you purchase a JUCE license, or
  # if you license your project using the GNU Public License.
  # - https://www.gnu.org/licenses
  # - https://juce.com/juce-6-licence
  JUCE_DISPLAY_SPLASH_SCREEN=0
)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
  juce::juce_audio_utils

  juce::juce_recommended_config_flags
  juce::juce_recommended_lto_flags
  juce::juce_recommended_warning_flags
)

add_subdirectory(src)
