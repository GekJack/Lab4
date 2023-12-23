#ifndef class_cpp
#define class_cpp
#include "class.h"

template <typename T>
String<T> :: ~String() {
	//std::cout << "destructor" << endl;
	printf("destructor/n");
}

#endif //class_cpp