#include <filesystem>

#include <Crawler.hpp>
#include <IOUtils.hpp>

const std::regex Crawler::html_filename_pattern{"[a-zA-Z0-9]+.html"};
const std::regex Crawler::link_pattern{"<a\\s+(?:[^>]*?\\s+)?href=([\"'])(.*?)\\1"};

Crawler::Crawler(const std::string& _dirname) noexcept
  : dirname(_dirname)
{
  
}

std::unordered_map<std::string, std::unordered_set<std::string>> Crawler::exec() const
{
  std::unordered_map<std::string, std::unordered_set<std::string>> result{};

  for (const auto& entry: std::filesystem::directory_iterator(dirname))
  {
    auto filepath = entry.path();

    if (!std::regex_match(filepath.filename().string(), html_filename_pattern))
    {
      continue;
    }

    std::string contents = read_file(filepath);

    auto ins = result.emplace(filepath.filename(), std::unordered_set<std::string>{});

    std::smatch link_match{};
    while (std::regex_search(contents, link_match, link_pattern))
    {
      std::smatch filename_match{};
      
      if (link_match.size() >= 3 && link_match[2].str() != filepath.filename())
      {
        ins.first->second.insert(link_match[2].str());
      }
      
      contents = link_match.suffix();
    }
  }

  // Filter the result to have links to other pages in the corpus.
  for (auto& p: result)
  {
    std::unordered_set<std::string> filtered_pages;

    for (const auto& s: p.second)
    {
      if (result.find(s) != result.end())
      {
        filtered_pages.insert(s);
      }
    }

    p.second = std::move(filtered_pages);
  }

  return result;
}
