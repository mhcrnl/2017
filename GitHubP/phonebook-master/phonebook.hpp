#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <vector>
#include <unordered_map>
#include <list>

#include "person.hpp"

class Phonebook {
  public:
    void add(Person p);

    Person* find_by_name(std::string name);
    Person* find_by_phone(int phone);

    std::vector<Person> data;

    void save(const std::string filename);

  private:
    std::unordered_map<std::string, Person*> lastname_index;
    std::unordered_map<int, Person*> phone_index;


};

#endif
