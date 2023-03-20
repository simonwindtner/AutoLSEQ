#include "StereoFilter.h"

void StereoFilter::setCoefficients(const juce::IIRCoefficients& coeffs)
{
  filterLeft.setCoefficients(coeffs);
  filterRight.setCoefficients(coeffs);
}

void StereoFilter::setCoefficients(const juce::IIRCoefficients& left,
                                   const juce::IIRCoefficients& right)
{
  filterLeft.setCoefficients(left);
  filterRight.setCoefficients(right);
}

void StereoFilter::processSamples(juce::AudioBuffer<float>& audio)
{
  assert(audio.getNumChannels() == 2);
  const auto numSamples = audio.getNumSamples();

  auto* audioLeft = audio.getWritePointer(0);
  auto* audioRight = audio.getWritePointer(1);

  filterLeft.processSamples(audioLeft, numSamples);
  filterRight.processSamples(audioRight, numSamples);
}
