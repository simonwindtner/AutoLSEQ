#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

class PluginBase : public juce::AudioProcessor
{
public:
  PluginBase()
    : AudioProcessor{ JucePlugin_IsSynth
                        ? BusesProperties{}.withOutput("out", juce::AudioChannelSet::stereo(), true)
                        : BusesProperties{}
                            .withInput("in", juce::AudioChannelSet::stereo())
                            .withOutput("out", juce::AudioChannelSet::stereo(), true) }
  {
  }

  void prepareToPlay(double, int) override {}
  void releaseResources() override {}

  auto hasEditor() const -> bool override { return true; }
  auto createEditor() -> juce::AudioProcessorEditor* override
  {
    return new juce::GenericAudioProcessorEditor(*this);
  }

  auto getName() const -> const juce::String override { return JucePlugin_Name; }

  auto acceptsMidi() const -> bool override { return JucePlugin_WantsMidiInput; }
  auto producesMidi() const -> bool override { return JucePlugin_ProducesMidiOutput; }
  auto isMidiEffect() const -> bool override { return JucePlugin_IsMidiEffect; }

  auto getTailLengthSeconds() const -> double override { return 0.0; }

  auto getNumPrograms() -> int override { return 1; }

  auto getCurrentProgram() -> int override { return 0; }
  void setCurrentProgram(int) override {}

  auto getProgramName(int) -> const juce::String override { return ""; }
  void changeProgramName(int, const juce::String&) override {}

  void getStateInformation(juce::MemoryBlock&) override {}
  void setStateInformation(const void*, int) override {}
};
