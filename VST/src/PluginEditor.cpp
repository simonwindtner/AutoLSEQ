#include "PluginEditor.h"
#include "CoefficientParser.h"

PluginEditor::PluginEditor(PluginProcessor& p)
  : juce::AudioProcessorEditor(p)
{
  const auto width = 400;
  const auto height = 300;
  setSize(width, height);
}

void PluginEditor::paint(juce::Graphics& g)
{
  const auto textArea = getLocalBounds();
  const auto text = "Parellel Filter Processor";

  g.setColour(juce::Colours::white);
  g.drawText(text, textArea, juce::Justification::centred);
}

void PluginEditor::resized() {}
