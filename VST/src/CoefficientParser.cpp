#include "CoefficientParser.h"

CoefficientParser::CoefficientParser(const std::string& filePath)
{
  const auto noHeaders = rapidcsv::LabelParams{ -1, -1 };
  const auto doc = rapidcsv::Document{ filePath, noHeaders };
  const auto numRows = doc.GetRowCount();

  for (auto i = 0U; i < numRows - 1; ++i) {
    const auto row = doc.GetRow<double>(i);
    assert(row.size() == 6);
    coefficients.emplace_back(row[0], row[1], row[2], row[3], row[4], row[5]);
  }

  const auto lastRow = doc.GetRow<double>(numRows - 1);
  assert(lastRow.size() <= 6);
  firCoefficient = lastRow[0];
}

std::vector<juce::IIRCoefficients> CoefficientParser::getIIRCoefficients() const
{
  return coefficients;
}

double CoefficientParser::getFIRCoefficient() const
{
  return firCoefficient;
}
