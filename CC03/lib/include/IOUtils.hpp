#pragma once

#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__); printf("\n");
#else
#define LOG(...)
#endif

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename First, typename Second>
std::ostream& operator << (std::ostream& out, const std::pair<First, Second>& p);

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& p);

template <typename T>
std::ostream& operator << (std::ostream& out, const std::unordered_set<T>& p);

template <typename K, typename V>
std::ostream& operator << (std::ostream& out, const std::unordered_map<K, V>& p);

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

template <typename T>
std::ostream& operator << (std::ostream& out, const std::unordered_set<T>& s)
{
  out << "{";
  auto it = s.begin();

  if (it != s.end())
  {
    out << *it;
    ++it;
  }

  for ( ; it != s.end(); ++it)
  {
    out << ", " << *it;
  }

  out << "}";

  return out;
}

template <typename K, typename V>
std::ostream& operator << (std::ostream& out, const std::unordered_map<K, V>& m)
{
  if (m.empty())
  {
    out << "{}";
    return out;
  }

  out << "{";
  auto it = m.begin();

  if (it != m.end())
  {
    out << "\n  " << it->first << ": " << it->second;
    ++it;
  }

  for ( ; it != m.end(); ++it)
  {
    out << ",\n  " << it->first << ": " << it->second;
  }

  out << "\n}";

  return out;
}

std::string read_file(const std::string& filename);
