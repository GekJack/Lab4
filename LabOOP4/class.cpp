#ifndef class_cpp
#define class_cpp
#include "class.h"


template <typename T>
String<T> :: String(const String&& other) :
	mass_char(other.mass_char), len(other.len)
{
	other.len = 0;
	other.mass_char = nullptr;
}
template <typename T>
String<T> :: ~String() {
	if (this->mass_char) {
		delete[] this->mass_char;
	}
	this->len = 0;
}
#endif //class_cpp