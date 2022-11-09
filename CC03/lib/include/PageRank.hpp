#pragma once

#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>

class PageRank
{
public:
  PageRank(const std::unordered_map<std::string, std::unordered_set<std::string>>& _corpus, std::random_device::result_type seed) noexcept;

  /**
   * @brief Return a probability distribution over which page to visit next, given a current page.
   * 
   * With probability `damping_factor`, choose a link at random linked to by `page`. With probability
   * `1 - damping_factor`, choose a link at random chosen from all pages in the corpus.
   * 
   * @param page The current page to compute the probability distribution.
   * @param damping_factor
   * @return The probability distribution
   */
  std::unordered_map<std::string, float> transition_model(const std::string& page, float damping_factor) const noexcept;

  /**
   * @brief Return PageRank values for each page by sampling `n` pages according to transition model, starting with a page at random.
   * 
   * @param damping_factor 
   * @param n 
   * @return Map that relates a page with its stimated PageRank value (a value between 0 and 1).
   */
  std::unordered_map<std::string, float> sample_pagerank(float damping_factor, size_t n) const noexcept;

  /**
   * @brief Return PageRank values for each page by iteratively updating PageRank values until convergence. 
   * @param damping_factor 
   * @return Map that relates a page with its stimated PageRank value (a value between 0 and 1).
   */
  std::unordered_map<std::string, float> iterate_pagerank(float damping_factor) const noexcept;

private:
  /**
   * @brief Return a random selection of an element based in its probability of being chosen.
   * 
   * @param table The probability distribution.
   * 
   * @return The random-selected page.
   */
  std::string weighted_choice(const std::unordered_map<std::string, float>& table) const;

  /**
   * @brief Select a random page from the corpus.
   * 
   * @return The selected random page.
   */
  const std::string& get_random_page() const noexcept;
  
  const std::unordered_map<std::string, std::unordered_set<std::string>>& corpus;
  mutable std::mt19937 random_number_generator;
};
