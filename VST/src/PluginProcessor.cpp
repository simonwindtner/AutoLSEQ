#include "PluginProcessor.h"
#include "CoefficientParser.h"
#include "PluginEditor.h"
#include <juce_audio_basics/juce_audio_basics.h>

PluginProcessor::PluginProcessor()
  : params(*this)
{
}

juce::AudioProcessorEditor* PluginProcessor::createEditor()
{
  return new PluginEditor(*this);
}

void PluginProcessor::prepareToPlay(double sampleRate, int bufferSize)
{
  juce::ignoreUnused(bufferSize);
  juce::ignoreUnused(sampleRate);

  leftFilters.setChannel(0);
  rightFilters.setChannel(1);

  const auto parserLeft = CoefficientParser{ "/Users/leonmerkel/Desktop/Coeff_L.csv" };
  const auto parserRight = CoefficientParser{ "/Users/leonmerkel/Desktop/Coeff_R.csv" };

  const auto iirCoefficientsLeft = parserLeft.getIIRCoefficients();
  const auto firCoefficientLeft = parserLeft.getFIRCoefficient();

  const auto iirCoefficientsRight = parserRight.getIIRCoefficients();
  const auto firCoefficientRight = parserRight.getFIRCoefficient();

  leftFilters.setupFilters(iirCoefficientsLeft, firCoefficientLeft);
  rightFilters.setupFilters(iirCoefficientsRight, firCoefficientRight);
}

void PluginProcessor::processBlock(juce::AudioBuffer<float>& audio, juce::MidiBuffer& midi)
{
  juce::ignoreUnused(midi);

  leftFilters.processSamples(audio);
  rightFilters.processSamples(audio);
}

void PluginProcessor::getStateInformation(juce::MemoryBlock& destData)
{
  copyXmlToBinary(params.getState(), destData);
}

void PluginProcessor::setStateInformation(const void* data, int sizeInBytes)
{
  if (const auto xml = getXmlFromBinary(data, sizeInBytes))
    params.setState(*xml);
}
