#ifndef INTERACTIVE_HPP
#define INTERACTIVE_HPP

#include <string>
#include "phonebook.hpp"

class Cli {
  public:
    Cli(Phonebook& book, std::string filename)
      : book(book), filename(filename) {}
    void start_interactive();

  private:
    void list_all();
    void add_person();
    void save();

    Phonebook& book;
    std::string filename;
};


#endif
