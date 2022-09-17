#include <filesystem>
#include <iostream>

#include <CSVStream.hpp>
#include <Degrees.hpp>

using namespace std;

namespace fs = filesystem;

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    cout << "Usage: " << argv[0] << " directory\n";
    return EXIT_FAILURE;
  }

  fs::current_path("./resources");
  fs::path p{argv[1]};

  CSVIStream in_people{p / "people.csv"};
  CSVIStream in_movies{p / "movies.csv"};
  CSVIStream in_stars{p / "stars.csv"};

  Degrees degrees{&in_people, &in_movies, &in_stars};

  in_people.close();
  in_movies.close();
  in_stars.close();

  string n1;
  string n2;

  cout << "Source name: ";
  getline(cin, n1);
  cout << "Target name: ";
  getline(cin, n2);

  auto result = degrees.get_degree_path(n1, n2);

  cout << result.size() << " degrees of separation\n";
  for (const auto& p: result)
  {
    cout << n1 << " and " << p.second << " starred in " << p.first << endl;
    n1 = p.second;
  }

  return EXIT_SUCCESS;
}
