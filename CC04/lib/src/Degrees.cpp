#include <Degrees.hpp>

Degrees::Degrees(ICSVIStream* people, ICSVIStream* movies, ICSVIStream* stars) noexcept
{
  // TODO
}

std::vector<std::string> Degrees::get_nodes_contents() const noexcept
{
  // TODO
  return std::vector<std::string>{};
}

std::vector<Degrees::ArcContents> Degrees::get_arcs_contents() const noexcept
{
  // TODO
  return std::vector<ArcContents>{};
}

std::vector<std::pair<std::string, std::string>> Degrees::get_degree_path(const std::string& source_name, const std::string& target_name) const noexcept
{
  // TODO
  return std::vector<std::pair<std::string, std::string>>{std::make_pair("", "")};
}

Degrees::ArcContents Degrees::make_arc_contents(const std::string& source_person, const std::string& target_person, const std::string& movie) noexcept
{
  return std::make_pair(std::make_pair(source_person, target_person), movie);
}
