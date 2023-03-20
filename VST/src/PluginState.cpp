#include "PluginState.h"

namespace {
auto createParameterLayout() -> juce::AudioProcessorValueTreeState::ParameterLayout
{
  return {};
}
} // namespace

PluginState::PluginState(juce::AudioProcessor& parent)
  : juce::AudioProcessorValueTreeState{ parent, nullptr, "params", createParameterLayout() }
{
}

auto PluginState::getState() -> juce::XmlElement
{
  return *copyState().createXml();
}

void PluginState::setState(const juce::XmlElement& xml)
{
  if (xml.hasTagName(state.getType()))
    replaceState(juce::ValueTree::fromXml(xml));
}
