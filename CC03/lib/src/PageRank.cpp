#include <exception>

#include <PageRank.hpp>

PageRank::PageRank(const std::unordered_map<std::string, std::unordered_set<std::string>>& _corpus, std::random_device::result_type seed) noexcept
  : corpus{_corpus}, random_number_generator{seed}
{
  
}

std::unordered_map<std::string, float> PageRank::transition_model(const std::string& page, float damping_factor) const noexcept
{
  // TODO
  return std::unordered_map<std::string, float>{};
}

std::unordered_map<std::string, float> PageRank::sample_pagerank(float damping_factor, size_t n) const noexcept
{
  // TODO
  return std::unordered_map<std::string, float>{};
}

std::unordered_map<std::string, float> PageRank::iterate_pagerank(float damping_factor) const noexcept
{
  // TODO
  return std::unordered_map<std::string, float>{};
}

std::string PageRank::weighted_choice(const std::unordered_map<std::string, float>& table) const
{
  auto r = std::generate_canonical<float, 32>(random_number_generator);

  for (const auto& p: table)
  {
    if (r < p.second)
    {
      return p.first;
    }

    r -= p.second;
  }

  throw std::logic_error{"Incomplete table"};
}

const std::string& PageRank::get_random_page() const noexcept
{
  std::uniform_int_distribution<size_t> unif{0, corpus.size() - 1};
  size_t i = unif(random_number_generator);

  auto it = corpus.begin();

  while (i-- > 0)
  {
    ++it;
  }

  return it->first;
}
