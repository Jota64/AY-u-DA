#include <filesystem>
#include <fstream>

#include <Crawler.hpp>
#include <TestUtils.hpp>

using namespace std;

namespace fs = filesystem;

struct Data
{
  static const fs::path dirpath;
  static const vector<std::string> filenames;
  static const unordered_map<std::string, unordered_set<string>> current_links;
  static const unordered_map<std::string, unordered_set<string>> expected_result;
};

const fs::path Data::dirpath{"test_crawler"};

const vector<std::string> Data::filenames{"test1.html", "test2.html", "test3.html", "test4.html", "test5.htmo", "test6.png, test7.txt"};

const unordered_map<std::string, unordered_set<string>> Data::current_links
{
  make_pair("test1.html", unordered_set<string>{"test2.html"}),
  make_pair("test2.html", unordered_set<string>{"test1.html", "test3.html", "https://www.google.com/"}),
  make_pair("test3.html", unordered_set<string>{"test2.html", "test4.html", "test6.png"}),
  make_pair("test4.html", unordered_set<string>{"test2.html", "test4.html"})
};

const unordered_map<std::string, unordered_set<string>> Data::expected_result
{
  make_pair("test1.html", unordered_set<string>{"test2.html"}),
  make_pair("test2.html", unordered_set<string>{"test1.html", "test3.html"}),
  make_pair("test3.html", unordered_set<string>{"test2.html", "test4.html"}),
  make_pair("test4.html", unordered_set<string>{"test2.html"})
};

std::string html_template(const string& title, const unordered_set<string>& links)
{
  string result = R"(<!DOCTYPE html>
<html lang=\"en\">
     <head>
        <title>)"; result += title; result += R"(</title>
    </head>
    <body>
        <h1>)"; result += title; result += R"(</h1>
        <div>Links:</div>
        <ul>
)";
  for (const string& l: links)
  {
    result += "            <li><a href=\"" + l + "\">" + l + "</a></li>\n";
  }

  result += R"(
        </ul>
    </body>
</html>)";
  
  return result;
}

void test_crawler()
{
  cout << "Given the directory " << Data::dirpath << " containing the following files: ";
  cout << Data::filenames << endl;
  cout << "When the method exec is called, it should return: ";
  cout << Data::expected_result << endl;

  fs::current_path("./resources");
  fs::create_directory(Data::dirpath);
  
  for (const string& filename: Data::filenames)
  {
    auto filepath = Data::dirpath / filename;
    ofstream f{filepath};

    auto found = Data::current_links.find(filepath.filename());

    if (found != Data::current_links.end())
    {
      f << html_template(filename, found->second);
    }

    f.close();
  }

  Crawler crawler{Data::dirpath};
  auto result = crawler.exec();

  fs::remove_all(Data::dirpath);

  assert_equal(result, Data::expected_result);

  cout << "Test passed!\n";
}

int main()
{
  cout << "Testing Crawler\n";

  test_crawler();

  cout << "Everything ok!\n";
  return EXIT_SUCCESS;
}
