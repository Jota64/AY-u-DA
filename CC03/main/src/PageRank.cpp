#include <iomanip>
#include <iostream>

#include <Crawler.hpp>
#include <PageRank.hpp>

using namespace std;

struct Constants
{
  static constexpr float damping{0.85f};
  static constexpr size_t samples{10000};
};

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    cout << "Usage: " << argv[0] << " corpus [seed]\n";
    return EXIT_FAILURE;
  }

  random_device::result_type seed{};

  if (argc == 3)
  {
    seed = stoul(argv[2]);
  }
  else
  {
    random_device rd{};
    seed = rd();
  }

  auto corpus = Crawler{argv[1]}.exec();
  
  PageRank page_rank{corpus, seed};

  auto sample_ranks = page_rank.sample_pagerank(Constants::damping, Constants::samples);

  cout << "PageRank results from sampling (n = " << Constants::samples << ")\n";

  for (const auto& p: sample_ranks)
  {
    cout << "  " << p.first << ": " << setprecision(4) << fixed << p.second << endl;
  }

  auto iterate_ranks = page_rank.iterate_pagerank(Constants::damping);

  cout << "PageRank results from iteration\n";

  for (const auto& p: iterate_ranks)
  {
    cout << "  " << p.first << ": " << setprecision(4) << fixed << p.second << endl;
  }
  
  return EXIT_SUCCESS;
}