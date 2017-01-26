#include <fstream>
#include <unordered_map>
#include "phonebook.hpp"
#include "person.hpp"

void Phonebook::add(Person p) {
  data.push_back(p);

  lastname_index.insert(std::make_pair(p.last, &p));
  phone_index.insert(std::make_pair(p.phone, &p));
}

Person* Phonebook::find_by_name(std::string name) {
  return lastname_index[name];
}

Person* Phonebook::find_by_phone(int phone) {
  return phone_index[phone];
}

void Phonebook::save(const std::string filename) {
  std::ofstream fs(filename);

  for (auto& person : data) {
    fs << person << std::endl;
  }
}
