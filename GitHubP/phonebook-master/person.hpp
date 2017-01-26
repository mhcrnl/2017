#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
  public:
    std::string first, last, address;
    int phone;
};

std::istream& operator>>(std::istream& is, Person& p);
std::ostream& operator<<(std::ostream& os, const Person& p);

#endif
