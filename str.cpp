#include <iostream>
#include <cstring>
#include <stdexcept>
#include <memory>
#include "str.h"

Str::Str()
{ // This empty constructor should store the empty string
    len = 0;
    buffer = std::make_unique<char[]>(len);
}

Str::Str(const char* s)
{ // This constructor should store the string passed as argument
    len = strlen(s);
    buffer = std::make_unique<char[]>(len+1);
    strcpy(this->buffer.get(), s);
}

// This is a copy constructor. It is necessary to pass Str objects too and from functions
// We will discuss more next class meeting

Str::Str(const Str& other){
    buffer = std::make_unique<char[]>(other.size()+1);
    len = other.size();
    strcpy(this->buffer.get(), other.buffer.get());
}

Str::~Str()
{

}

size_t Str::size() const
{
    return len;
}

const char& Str::operator[](const int i) const {
    if (i < len) {
        return buffer[i];
    }

    return '\0';
}

char& Str::operator[](const int i) {
    //if (i < len) {
        return &buffer[i]; // not completed
    //}

    //return NULL;
}

std::ostream & operator<<(std::ostream& lhs, const Str& rhs) {
    lhs << rhs.buffer.get();
}