#include <iostream>

#include <CSVStream.hpp>

using namespace std;

int main()
{
  CSVIStream in{"resources/small/people.csv"};

  const vector<string> headers = in.get_headers();
  cout << headers[0] << ", " << headers[1] << ", " << headers[2] << endl;
  
  std::vector<string> fields;
  while (in.read_row(fields))
  {
    cout << fields[0] << ", " << fields[1] << ", " << fields[2] << endl;
  }

  in.close();

  return EXIT_SUCCESS;
}