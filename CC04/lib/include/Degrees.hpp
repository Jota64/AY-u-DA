#pragma once

#include <CSVStream.hpp>

class Degrees
{
public:
  using ConnectionType = std::pair<std::string, std::string>;
  using ArcContents = std::pair<ConnectionType, std::string>;

  Degrees(ICSVIStream* people, ICSVIStream* movies, ICSVIStream* stars) noexcept;

  std::vector<std::string> get_nodes_contents() const noexcept;

  std::vector<ArcContents> get_arcs_contents() const noexcept;

  std::vector<std::pair<std::string, std::string>> get_degree_path(const std::string& source_name, const std::string& target_name) const noexcept;

private:
  static ArcContents make_arc_contents(const std::string& source_person, const std::string& target_person, const std::string& movie) noexcept;
};

