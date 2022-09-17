#include <iomanip>

#include <PageRank.hpp>
#include <TestUtils.hpp>

using namespace std;

struct Data
{
  static constexpr random_device::result_type seed{0};
  static constexpr size_t samples{10000};
  static constexpr float damping{0.85f};
  static const unordered_map<string, unordered_set<string>> corpus;

  static const unordered_map<string, float> expected_sample_ranks;
  static const unordered_map<string, float> expected_iterate_ranks;

  static void set_up()
  {
    cout << setprecision(4) << fixed;
    cerr << setprecision(4) << fixed;  
  }
};


const unordered_map<string, unordered_set<string>> Data::corpus
{
  make_pair("test1.html", unordered_set<string>{"test2.html"}),
  make_pair("test2.html", unordered_set<string>{"test1.html", "test3.html"}),
  make_pair("test3.html", unordered_set<string>{"test2.html", "test4.html"}),
  make_pair("test4.html", unordered_set<string>{"test2.html"})
};

const unordered_map<string, float> Data::expected_sample_ranks
{
  make_pair("test1.html", 0.2208f),
  make_pair("test2.html", 0.4296f),
  make_pair("test3.html", 0.2211f),
  make_pair("test4.html", 0.1285f)
};

const unordered_map<string, float> Data::expected_iterate_ranks
{
  make_pair("test1.html", 0.2189f),
  make_pair("test2.html", 0.4267f),
  make_pair("test3.html", 0.2185f),
  make_pair("test4.html", 0.1302f)
};

void test_sample_ranks()
{
  cout << "Given seed = " << Data::seed << ", damping = " << Data::damping << ", samples = " << Data::samples << ", and the corpus ";
  cout << Data::corpus << endl;
  cout << "When the method sample_pagerank is called, it should return ";
  cout << Data::expected_sample_ranks << endl;

  auto result = PageRank{Data::corpus, Data::seed}.sample_pagerank(Data::damping, Data::samples);

  assert_equal(result, Data::expected_sample_ranks);
  cout << "Test passed!\n";
}

void test_iterate_ranks()
{
  cout << "Given seed = " << Data::seed << ", damping = " << Data::damping << ", and the corpus ";
  cout << Data::corpus << endl;
  cout << "When the method iterate_pagerank is called, it should return ";
  cout << Data::expected_iterate_ranks << endl;

  auto result = PageRank{Data::corpus, Data::seed}.iterate_pagerank(Data::damping);

  assert_equal(result, Data::expected_iterate_ranks);
  cout << "Test passed!\n";
}

int main()
{
  cout << "Testing PageRank\n";
  Data::set_up();

  test_sample_ranks();
  test_iterate_ranks();

  cout << "Everything ok!\n";
  return EXIT_SUCCESS;
}