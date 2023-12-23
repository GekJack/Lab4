#ifndef class_cpp
#define class_cpp
#include "class.h"

template <typename T>
String<T> :: ~String() {
	//std::cout << "destructor" << endl;
	printf("destructor/n");
}

template <typename T>
String<T> :: String() {
	this->len = 10;
	this->mass_char = new T[len];
	for (int i = 0; i < this->len; i++) {
		mass_char[i] = 'a';
	}
}
#endif //class_cpp