#pragma once

#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include <IOUtils.hpp>

template <typename T>
bool equal_value(const T& v1, const T& v2);

template <class Container, class Less = std::less<typename Container::value_type>>
bool equal_container(const Container& c1, const Container& c2, Less cmp = Less{})
{
  if (c1.size() != c2.size())
  {
    return false;
  }

  std::vector<typename Container::value_type> v1{c1.begin(), c1.end()};
  std::vector<typename Container::value_type> v2{c2.begin(), c2.end()};
  
  std::sort(v1.begin(), v1.end(), cmp);
  std::sort(v2.begin(), v2.end(), cmp);

  return std::equal(v1.begin(), v1.end(), v2.begin(), equal_value<typename Container::value_type>);
}

template <typename T>
bool equal_value(const T& v1, const T& v2)
{
  return v1 == v2;
}

template <typename T>
bool equal_value(const std::vector<T>& v1, const std::vector<T>& v2)
{
  return equal_container(v1, v2);
}

template <typename T>
void assert_equal(const T& current, const T& expected)
{
  if (!equal_value(expected, current))
  {
    std::cerr << "Test failed:\n";
    std::cerr << "Current: " << current << std::endl;
    std::cerr << "Expected: " << expected << std::endl;
    abort();
  }
}
