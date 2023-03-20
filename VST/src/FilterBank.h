#pragma once
#include <juce_audio_basics/juce_audio_basics.h>

class FilterBank
{
public:
  void setChannel(size_t channelToSet);
  void setupFilters(const std::vector<juce::IIRCoefficients>& coeffs, double firGain = 1.0);

  void processSamples(juce::AudioBuffer<float>& audio);

private:
  size_t selectedChannel;

  struct FilterWithMemory
  {
    juce::IIRFilter filter;
    std::vector<float> audioData;
  };
  std::vector<FilterWithMemory> filters;
  double firGain;
};
