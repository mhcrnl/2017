#include <istream>
#include <ostream>

#include "person.hpp"

using std::endl;

class line_word {
 public:
  line_word(std::string s) : s(s) {}
  friend std::istream& operator>>(std::istream& is, std::string& s);

 private
  std::string s;
};

std::istream& operator>>(std::istream& is, std::string& s) {
  char buf[1000];
  is.getline(buf, 1000);
}

class skip_char {
 public:
  skip_char(char c) : c(c) {}
  friend std::istream& operator>>(std::istream& is, skip_char sc);

 private:
  char c;
};

std::istream& operator>>(std::istream& is, skip_char sc) {
  char c;
  is >> c;
  if (c != sc.c) is.setstate(std::ios::failbit);
  return is;
}

std::istream& operator>>(std::istream& is, Person& p) {
  std::string b;

  is >> skip_char('{');

  // TODO - handle when one of the fields spans multiple words
  is >> line_word(p.first) >> p.last >> p.address >> p.phone;

  is >> skip_char('}');

  return is;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
  os << "{" << endl;
  os << "  " << p.first << endl;
  os << "  " << p.last << endl;
  os << "  " << p.address << endl;
  os << "  " << p.phone << endl;
  os << "}";

  return os;
}
