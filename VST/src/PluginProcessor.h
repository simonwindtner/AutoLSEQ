#pragma once
#include "FilterBank.h"
#include "PluginBase.h"
#include "PluginState.h"

class PluginProcessor : public PluginBase
{
public:
  PluginProcessor();

  void prepareToPlay(double sampleRate, int bufferSize) override;
  void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

  void getStateInformation(juce::MemoryBlock& destData) override;
  void setStateInformation(const void* data, int sizeInBytes) override;

  juce::AudioProcessorEditor* createEditor() override;

private:
  PluginState params;

  FilterBank leftFilters;
  FilterBank rightFilters;
};
