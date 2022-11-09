#include <TestUtils.hpp>

bool equal_value(float f1, float f2)
{
  return std::abs(f1 - f2) < 10e-4f;
}
