#include <filesystem>
#include <string>
#include <vector>

#include <Degrees.hpp>
#include <TestUtils.hpp>

using namespace std;

namespace fs = filesystem;

struct Data
{
  static const fs::path path;
  static const string source_name;
  static const string target_name;
  static const vector<string> expected_nodes_contents;
  static const vector<Degrees::ArcContents> expected_arcs_contents;
  static const vector<pair<string, string>> expected_path;
};

const fs::path Data::path{"small"};
const string Data::source_name{"Tom Hanks"};
const string Data::target_name{"Chris Sarandon"};

const vector<string> Data::expected_nodes_contents
{
  "Kevin Bacon", 
  "Tom Cruise", 
  "Cary Elwes", 
  "Tom Hanks", 
  "Mandy Patinkin", 
  "Dustin Hoffman", 
  "Chris Sarandon", 
  "Demi Moore", 
  "Jack Nicholson", 
  "Bill Paxton", 
  "Sally Field", 
  "Valeria Golino", 
  "Gerald R. Molen", 
  "Gary Sinise", 
  "Robin Wright", 
  "Emma Watson"
};

const vector<Degrees::ArcContents> Data::expected_arcs_contents
{
  make_pair(make_pair("Tom Cruise", "Dustin Hoffman"), "Rain Man"),
  make_pair(make_pair("Tom Cruise", "Valeria Golino"), "Rain Man"),
  make_pair(make_pair("Tom Cruise", "Gerald R. Molen"), "Rain Man"),
  make_pair(make_pair("Dustin Hoffman", "Valeria Golino"), "Rain Man"),
  make_pair(make_pair("Dustin Hoffman", "Gerald R. Molen"), "Rain Man"),
  make_pair(make_pair("Valeria Golino", "Gerald R. Molen"), "Rain Man"),
  make_pair(make_pair("Cary Elwes", "Mandy Patinkin"), "The Princess Bride"),
  make_pair(make_pair("Cary Elwes", "Chris Sarandon"), "The Princess Bride"),
  make_pair(make_pair("Cary Elwes", "Robin Wright"), "The Princess Bride"),
  make_pair(make_pair("Mandy Patinkin", "Chris Sarandon"), "The Princess Bride"),
  make_pair(make_pair("Mandy Patinkin", "Robin Wright"), "The Princess Bride"),
  make_pair(make_pair("Chris Sarandon", "Robin Wright"), "The Princess Bride"),
  make_pair(make_pair("Kevin Bacon", "Tom Hanks"), "Apollo 13"),
  make_pair(make_pair("Kevin Bacon", "Bill Paxton"), "Apollo 13"),
  make_pair(make_pair("Kevin Bacon", "Gary Sinise"), "Apollo 13"),
  make_pair(make_pair("Tom Hanks", "Bill Paxton"), "Apollo 13"),
  make_pair(make_pair("Tom Hanks", "Gary Sinise"), "Apollo 13"),
  make_pair(make_pair("Bill Paxton", "Gary Sinise"), "Apollo 13"),
  make_pair(make_pair("Tom Hanks", "Sally Field"), "Forrest Gump"),
  make_pair(make_pair("Tom Hanks", "Robin Wright"), "Forrest Gump"),
  make_pair(make_pair("Sally Field", "Gary Sinise"), "Forrest Gump"),
  make_pair(make_pair("Sally Field", "Robin Wright"), "Forrest Gump"),
  make_pair(make_pair("Gary Sinise", "Robin Wright"), "Forrest Gump"),
  make_pair(make_pair("Kevin Bacon", "Tom Cruise"), "A Few Good Men"),
  make_pair(make_pair("Kevin Bacon", "Demi Moore"), "A Few Good Men"),
  make_pair(make_pair("Kevin Bacon", "Jack Nicholson"), "A Few Good Men"),
  make_pair(make_pair("Tom Cruise", "Demi Moore"), "A Few Good Men"),
  make_pair(make_pair("Tom Cruise", "Jack Nicholson"), "A Few Good Men"),
  make_pair(make_pair("Demi Moore", "Jack Nicholson"), "A Few Good Men")
};

const vector<pair<string, string>> Data::expected_path
{
  make_pair("Forrest Gump", "Robin Wright"),
  make_pair("The Princess Bride", "Chris Sarandon")
};

void test_small_set()
{
  cout << "Given the small set, the source name " << Data::source_name << ", and the target name " << Data::target_name << endl;
  cout << "When the method get_nodes_contents is called, then it should return " << Data::expected_nodes_contents << endl;
  cout << "When the method get_arcs_contents is called, then it should return " << Data::expected_arcs_contents << endl;
  cout << "When the method get_degree_path is called, then it should return " << Data::expected_path << endl;
  CSVIStream in_people{Data::path / "people.csv"};
  CSVIStream in_movies{Data::path / "movies.csv"};
  CSVIStream in_stars{Data::path / "stars.csv"};

  Degrees degrees{&in_people, &in_movies, &in_stars};

  in_people.close();
  in_movies.close();
  in_stars.close();

  auto current_nodes_contents = degrees.get_nodes_contents();
  auto current_arcs_contents = degrees.get_arcs_contents();
  auto current_path = degrees.get_degree_path(Data::source_name, Data::target_name);
  assert_equal(current_nodes_contents, Data::expected_nodes_contents);
  assert_equal(current_arcs_contents, Data::expected_arcs_contents);
  assert_equal(current_path, Data::expected_path);
}

int main()
{
  cout << "Testing Degrees\n";
  fs::current_path("./resources");

  test_small_set();

  cout << "Everything ok!\n";
  return EXIT_SUCCESS;
}
