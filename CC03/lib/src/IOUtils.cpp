#include <fstream>
#include <sstream>

#include <IOUtils.hpp>

std::string read_file(const std::string& filename)
{
  std::ifstream f{filename};
  std::stringstream s;

  if (!f)
  {
    s << filename << " does not exist.";
    throw std::logic_error(s.str());
  }

  char byte;
  while (f.get(byte))
  {
    s << byte;
  }

  f.close();
  return s.str();
}
