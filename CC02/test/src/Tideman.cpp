#include <NoWinnerException.hpp>
#include <TestUtils.hpp>
#include <Tideman.hpp>


using namespace std;

struct Data
{
  static const vector<string> candidates;
  static const vector<vector<string>> votes;
  static const vector<int> ranks;
  static const vector<pair<int, int>> pairs;
  static const vector<vector<bool>> locked;
  static const vector<vector<bool>> circular_locked;

  static const vector<int> expected_ranks_voter0;
  static const vector<vector<int>> expected_preferences;
  static const vector<pair<int, int>> expected_pairs;
  static const vector<vector<bool>> expected_locked;

  static const string expected_winner;
};

const vector<string> Data::candidates{"Harry", "Hermione", "Ronald"};

const vector<vector<string>> Data::votes
{
  vector<string>{"Hermione", "Harry", "Ronald"},
  vector<string>{"Hermione", "Harry", "Ronald"},
  vector<string>{"Ronald", "Hermione", "Harry"},
  vector<string>{"Ronald", "Hermione", "Harry"},
  vector<string>{"Ronald", "Hermione", "Harry"},
  vector<string>{"Harry", "Hermione", "Ronald"},
  vector<string>{"Harry", "Hermione", "Ronald"},
  vector<string>{"Harry", "Hermione", "Ronald"},
  vector<string>{"Harry", "Ronald", "Hermione"}
};

const vector<int> Data::ranks{1, 0, 2};

const vector<pair<int, int>> Data::pairs{make_pair(1, 0), make_pair(0, 2), make_pair(1, 2)};

const vector<vector<bool>> Data::locked{
  {false, false, true},
  {true, false, true},
  {false, false, false}
};

const vector<vector<bool>> Data::circular_locked{
  {false, false, true},
  {true, false, true},
  {false, true, false}
};

const vector<int> Data::expected_ranks_voter0{1, 0, 2};

const vector<vector<int>> Data::expected_preferences
{
  {0, 0, 1},
  {1, 0, 1},
  {0, 0, 0},
};

const vector<pair<int, int>> Data::expected_pairs{make_pair(1, 0), make_pair(0, 2), make_pair(1, 2)};

const vector<vector<bool>> Data::expected_locked{
  {false, false, true},
  {true, false, true},
  {false, false, false}
};

const string Data::expected_winner{"Hermione"};

void test_vote()
{
  cout << "Given the candidates: ";
  print_vector(Data::candidates, cout);
  cout << "And the list of votes: ";
  print_vector(Data::votes[0], cout);
  cout << "When the method vote is called, then it should return: ";
  print_vector(Data::expected_ranks_voter0, cout);

  Tideman tideman{Data::candidates};
  vector<int> ranks(Data::candidates.size());

  for (size_t i = 0; i < Data::votes[0].size(); ++i)
  {
    bool result = tideman.vote(i, Data::votes[0][i], ranks);
    assert_equal(result, true);
  }

  assert_equal_vector(Data::expected_ranks_voter0, ranks);
  cout << "Test Ok!\n";
}


void test_record_preferences()
{
  cout << "Given the candidates: ";
  print_vector(Data::candidates, cout);
  cout << "And the list of ranks: ";
  print_vector(Data::ranks, cout);
  cout << "When the method record_preferences is called, the preferences should be: ";
  print_matrix(Data::expected_preferences, cout);
  
  Tideman tideman{Data::candidates};
  tideman.record_preferences(Data::ranks);

  assert_equal_matrix(tideman.get_preferences(), Data::expected_preferences);
  cout << "Test Ok!\n";
}

void test_create_pairs()
{
  cout << "Given the candidates: ";
  print_vector(Data::candidates, cout);
  cout << "And the votes: ";
  print_matrix(Data::votes, cout);
  cout << "When the method create_pair is called, then the result should be: ";
  print_vector(Data::expected_pairs, cout);
  
  Tideman tideman{Data::candidates};
  
  for (size_t i = 0; i < Data::votes[0].size(); ++i)
  {
    vector<int> ranks(Data::candidates.size());
    bool result = tideman.vote(i, Data::votes[0][i], ranks);
    assert_equal(result, true);
  }

  tideman.record_preferences(Data::ranks);

  auto pairs = tideman.create_pairs();

  assert_equal_vector(pairs, Data::expected_pairs);

  cout << "Test Ok!\n";
}

void test_lock_pairs()
{
  cout << "Given the candidates: ";
  print_vector(Data::candidates, cout);
  cout << "And the pairs: ";
  print_vector(Data::pairs, cout);
  cout << "When the method lock_pairs is called, then the result should be: ";
  cout << boolalpha;
  print_matrix(Data::expected_locked, cout);
  
  auto result = Tideman::lock_pairs(Data::pairs, Data::candidates.size());

  assert_equal_matrix(result, Data::expected_locked);

  cout << "Test Ok!\n";
}

void test_get_winner()
{
  cout << "Given the candidates: ";
  print_vector(Data::candidates, cout);
  cout << "And the locked: ";
  print_matrix(Data::locked, cout);
  cout << "When the method get_winner is called, then the result should be: " << Data::expected_winner << endl;
  
  Tideman tideman{Data::candidates};
  string result = tideman.get_winner(Data::locked);

  assert_equal(result, Data::expected_winner);

  cout << "Test Ok!\n";
}

void test_no_winner_exception()
{
  cout << "Given the candidates: ";
  print_vector(Data::candidates, cout);
  cout << "And the locked: ";
  print_matrix(Data::circular_locked, cout);
  cout << "When the method get_winner is called, then NoWinnerException should be thrown\n";
  
  Tideman tideman{Data::candidates};
  auto call_get_winner = [&] { return tideman.get_winner(Data::circular_locked); };

  assert_throw_exception<NoWinnerException>(call_get_winner);

  cout << "Test Ok!\n";
}

int main()
{
  test_vote();
  test_record_preferences();
  test_create_pairs();
  test_lock_pairs();
  test_get_winner();
  test_no_winner_exception();
  cout << "Everything ok!\n";
  return EXIT_SUCCESS;
}
