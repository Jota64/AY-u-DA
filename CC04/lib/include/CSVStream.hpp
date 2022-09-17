#pragma once

#include <fstream>
#include <regex>
#include <string>
#include <vector>

// Interface for ICSVIstream
class ICSVIStream: public std::ifstream
{
public:
  using std::ifstream::ifstream;
  virtual bool read_row(std::vector<std::string>& row) = 0;
};

class CSVIStream: public ICSVIStream
{
public:
  CSVIStream(const std::string& filename, bool headers = true);

  const std::vector<std::string>& get_headers() const;

  bool read_row(std::vector<std::string>& row) override;

private:
  std::vector<std::string> headers;
  std::regex csv_pattern{"(([^,^\"])*(\".*\")*([^,^\"])*)(,|$)"};
};
