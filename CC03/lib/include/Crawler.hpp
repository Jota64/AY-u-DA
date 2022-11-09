#pragma once

#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Crawler
{
public:
  Crawler(const std::string& _dirname) noexcept;

  std::unordered_map<std::string, std::unordered_set<std::string>> exec() const;

private:
  std::string dirname;

  static const std::regex html_filename_pattern;
  static const std::regex link_pattern;
};
