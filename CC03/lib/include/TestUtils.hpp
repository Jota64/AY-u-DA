#pragma once

#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include <IOUtils.hpp>

template <typename T>
bool equal_value(const T& v1, const T& v2);

bool equal_value(float f1, float f2);

template <class Container, class Less = std::less<typename Container::value_type>>
bool equal_container(const Container& c1, const Container& c2, Less cmp = Less{})
{
  if (c1.size() != c2.size())
  {
    return false;
  }

  std::vector<typename Container::value_type> v1{c1.size()};
  std::vector<typename Container::value_type> v2{c2.size()};
  
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
bool equal_value(const std::unordered_set<T>& s1, const std::unordered_set<T>& s2)
{
  return equal_container(s1, s2);
}

template <typename K, typename V>
bool equal_value(const std::unordered_map<K, V>& m1, const std::unordered_map<K, V>& m2)
{
  if (m1.size() != m2.size())
  {
    return false;
  }

  for (const auto& p: m1)
  {
    auto found = m2.find(p.first);
    if (found == m2.end())
    {
      return false;
    }

    if (!equal_value(p.second, found->second))
    {
      return false;
    }
  }

  for (const auto& p: m2)
  {
    auto found = m1.find(p.first);
    if (found == m1.end())
    {
      return false;
    }

    if (!equal_value(p.second, found->second))
    {
      return false;
    }
  }

  return true;
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
