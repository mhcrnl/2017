#include <fstream>
#include <iostream>
#include <string>
#include <list>

#include "person.hpp"
#include "phonebook.hpp"
#include "interactive.hpp"

using std::cout;
using std::endl;
using std::cin;

int main() {
  std::ifstream is("input.txt");

  Person p;
  is >> p;

  Phonebook book;
  book.add(p);

  Cli cli(book, "input.txt");
  cli.start_interactive();

  // cout << *book.find_by_name("Vomacka") << endl;
  // cout << book.find_by_name("NEVOMACKA") << endl;

  return 0;
}
