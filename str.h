#ifndef STR_H
#define STR_H
#include <iostream>
#include <memory>

class Str {
 public:
  Str();
  // This is a copy constructor. It is necessary to pass Str objects to and from functions
  // We will discuss more next class meeting
  Str(const Str& other);
  Str(const char* s);
  ~Str();
 // This should return length of string without the null character.
  size_t size() const;
  // Add functions to overload operators so strtest.cpp works!
  const char& operator[](const int i) const;
  char& operator[](const int i);
  friend std::ostream & operator<<(std::ostream& lhs, const Str& rhs);

  private:
  std::unique_ptr<char []> buffer;
  // This should be the size of the string. An additional null character is necessary in buffer
  size_t len;
};




#endif
