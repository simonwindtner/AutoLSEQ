#pragma once
#include <juce_audio_basics/juce_audio_basics.h>
#include <rapidcsv.h>

class CoefficientParser
{
public:
  CoefficientParser(const std::string& filePath);

  std::vector<juce::IIRCoefficients> getIIRCoefficients() const;
  double getFIRCoefficient() const;

private:
  std::vector<juce::IIRCoefficients> coefficients;
  double firCoefficient = 1.0;
};
