#include <iostream>
#include "phonebook.hpp"
#include "interactive.hpp"

using std::cout;
using std::cin;
using std::endl;

void print_menu() {
  cout << "l) List all" << endl;
  cout << "a) Add" << endl;
  cout << "d) Delete" << endl;
  cout << "s) Save" << endl;
  cout << "n) Find by name" << endl;
  cout << "p) Find by phone" << endl;
  cout << "q) Quit" << endl;
  cout << "****************" << endl;
}

void invalid_command() {
  cout << "Neplatny prikaz";
}

void Cli::start_interactive() {
  print_menu();

  while (true) {
    char c;
    cin >> c;

    if (cin.eof()) return;

    switch (c) {
      case 'l': list_all(); break;
      case 'a': add_person(); break;
      case 'd': break;
      case 's': save(); break;
      case 'n': break;
      case 'p': break;
      case 'q': return;
      default: invalid_command();
    }

    cout << endl << endl;
    print_menu();
  }
}

void Cli::list_all() {
  cout << endl << endl << "Listing all:" << endl;

  int i = 1;

  for (auto& person : book.data) {
    cout << "  " << i++ << ". " << person << endl;
  }
}

void Cli::add_person() {
  cout << endl << endl << "Enter a new person:" << endl;
  Person p;
  cin >> p;
  book.add(p);
  cout << "OK" << endl;
}

void Cli::save() {
  book.save(filename);
}
