#include <algorithm>

#include <CSVStream.hpp>

CSVIStream::CSVIStream(const std::string& filename, bool header)
  : ICSVIStream(filename)
{
  if (header)
  {
    read_row(headers);
  }
}

const std::vector<std::string>& CSVIStream::get_headers() const
{
  return headers;
}

bool CSVIStream::read_row(std::vector<std::string>& row)
{
  row.clear();
  std::string line{};
  std::getline(*this, line);

  if (!line.empty())
  {
    for (auto it = std::sregex_iterator(line.begin(), line.end(), csv_pattern); it != std::sregex_iterator(); ++it)
    {
      auto sm = *it;
      std::string s = sm[1].str();
      
      // Remove quotes
      s.erase(std::remove(s.begin(), s.end(), '"'), s.end());

      // ltrim
      s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); }));

      // rtrim
      s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
      
      row.push_back(s);

      if (sm[5].length() == 0)
      {
        break;
      }    
    }
  }

  return bool(*this);
}