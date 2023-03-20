#pragma once
#include <juce_audio_basics/juce_audio_basics.h>

class StereoFilter
{
public:
  void setCoefficients(const juce::IIRCoefficients&);
  void setCoefficients(const juce::IIRCoefficients& left, const juce::IIRCoefficients& right);

  void processSamples(juce::AudioBuffer<float>&);

private:
  juce::IIRFilter filterLeft;
  juce::IIRFilter filterRight;
};
