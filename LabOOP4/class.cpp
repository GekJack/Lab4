#ifndef class_cpp
#define class_cpp
#include "class.h"


template <typename T>
String<T> :: String(const String&& other) : //����������� ����������
	mass_char(other.mass_char), len(other.len)
{
	other.len = 0;
	other.mass_char = nullptr;
}
template <typename T>
String<T> :: ~String() { // ����������
	if (this->mass_char) {
		delete[] this->mass_char;
	}
	this->len = 0;
}

template <typename T>
String<T> :: String(T value, int len) { // ����������� ������ ��������
	this->mass_char = new T[len];
	for (int i = 0; i < len; i++) {
		this->mass_char[i] = value;
	}
}

template <typename T>
String<T> :: String() { // ����������� �� �����������
	this->len = 10;
	this->mass_char = new T[len];
	for (int i = 0; i < this->len; i++) {
		mass_char[i] = 'a';
	}
}




#endif //class_cpp
