#include "FilterBank.h"

void FilterBank::setupFilters(const std::vector<juce::IIRCoefficients>& coeffs, double parallelGain) 
{
  const auto maxPossibleNumSamples = 4096;
  const auto numFilters = coeffs.size();

  filters = std::vector<FilterWithMemory>(numFilters);

  for (auto i = 0U; i < numFilters; ++i) {
    filters[i].filter.setCoefficients(coeffs[i]);
    filters[i].audioData.reserve(maxPossibleNumSamples);
  }

  firGain = parallelGain;
}

void FilterBank::setChannel(size_t channelToSet)
{
  selectedChannel = channelToSet;
}

void FilterBank::processSamples(juce::AudioBuffer<float>& audio)
{
  assert(audio.getNumChannels() >= selectedChannel);
  const auto numSamples = audio.getNumSamples();
  auto* firstSample = audio.getWritePointer(selectedChannel);

  const auto firAudioData = std::vector<float>(firstSample, firstSample + numSamples);

  // Process each parallel stage individually:
  for (auto& filter : filters) {
    filter.audioData = std::vector<float>(firstSample, firstSample + numSamples);
    filter.filter.processSamples(filter.audioData.data(), numSamples);
  }

  // Sum all parallel stages:
  auto result = std::vector<float>(numSamples);
  for (auto i = 0U; i < numSamples; ++i) {
    for (auto& filter : filters)
      result[i] += filter.audioData[i];
  }

  // Apply final FIR stage:
  for (auto i = 0U; i < audio.getNumSamples(); ++i) {
    result[i] += firAudioData[i] * firGain;
  }

  // Copy result into original audio buffer:
  audio.copyFrom(selectedChannel, 0, result.data(), numSamples);
}
