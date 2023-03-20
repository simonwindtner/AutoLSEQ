#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

class PluginState : public juce::AudioProcessorValueTreeState
{
public:
  explicit PluginState(juce::AudioProcessor&);

  auto getState() -> juce::XmlElement;
  void setState(const juce::XmlElement&);
};
