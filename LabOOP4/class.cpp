#ifndef class_cpp
#define class_cpp
#include "class.h"

template <typename T>
String<T> :: ~String() {
	//std::cout << "destructor" << endl;
	printf("destructor/n");
}
template <typename T>
String<T>::String(T value, int len) {
	this->mass_char = new T[len];
	for (int i = 0; i < len; i++) {
		this->mass_char[i] = value;
	}
}

#endif //class_cpp