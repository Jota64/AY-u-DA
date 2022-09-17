#pragma once

#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__); printf("\n");
#else
#define LOG(...)
#endif

#include <iostream>
#include <vector>

template <typename First, typename Second>
std::ostream& operator << (std::ostream& out, const std::pair<First, Second>& p);

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& p);

template <typename First, typename Second>
std::ostream& operator << (std::ostream& out, const std::pair<First, Second>& p)
{
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v)
{
  out << "[";
  auto it = v.begin();

  if (it != v.end())
  {
    out << *it;
    ++it;
  }

  for ( ; it != v.end(); ++it)
  {
    out << ", " << *it;
  }

  out << "]";

  return out;
}
