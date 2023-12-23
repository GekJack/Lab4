#ifndef class_cpp
#define class_cpp
#include "class.h"

template <typename T>
String<T> ::String() { // ����������� �� �����������
	this->len = 10;
	this->mass_char = new T[len];
	for (int i = 0; i < this->len; i++) {
		mass_char[i] = 'a';
	}
}
template <typename T>
String<T> :: String(T value, int len) { // ����������� ������ ��������
	this->len = len;
	this->mass_char = new T[len];
	for (int i = 0; i < len; i++) {
		this->mass_char[i] = value;
	}
}
template <typename T>
template <typename U>
String<T> :: String(const String<U>& other){ // ����������� �����������
	this->mass_char = new T[other.GetLen()];
	this->len = other.GetLen();
	for (int i = 0; i < this->len; i++) {
		this->mass_char[i] = static_cast<T>(other.GetCurrentSymbol(i));
	}
}
template <typename T>
String<T> ::String(const String<T>&& other) : //����������� ����������
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
void String<T> :: OutPut() const{ // ����
	if (this->isEmpty()) {
		cout << "The string is empty";
	}
	else {
		for (int i = 0; i < this->len; i++) {
			cout << mass_char[i];
		}
		cout << endl;
	}
}
template <typename T> 
T String<T> :: GetCurrentSymbol(int pos) const { // ��������� ������� �� ���� �������� � ������
	return this->mass_char[pos];
}
template <typename T>
int String<T> :: GetLen() const { // ��������� ������� ������
	return this->len;
}
template <typename T>
bool String<T> :: isEmpty() const{
	bool status = true;
	for (int i = 0; i < this->len; i++) {
		if (this->mass_char[i] != T()) {
			status = false;
			break;
		}
	}
	return status;
}
template <typename T>
template <typename U>
String<T>& String<T> :: operator+=(const String<U>& other) {
	int new_len = this->len + other.GetLen();
	int old_len = this->len;
	this->resize(new_len);
	for (int i = 0; i < other.GetLen(); i++) {
		this->mass_char[i+old_len] = static_cast<T>(other.GetCurrentSymbol(i));
	}
	return *this;
}

template <typename T>
void String<T> ::resize(int new_len) {
	T* temp_array = new T[new_len];
	for (int i = 0; i < this->len; i++) {
		temp_array[i] = this->mass_char[i];
	}
	delete[] this->mass_char;
	this->mass_char = new T[new_len];
	for (int i = 0; i < this->len; i++) {
		this->mass_char[i] = temp_array[i];
	}
	this->len = new_len;
}

/*template<typename T>
template<typename U>
U String<T> :: ConvertStringType(int new_len)
{
	if (this->len == new_len) {
		String<U> New_String('1', new_len);
		for (int i = 0; i < this->len; i++) {
			New_String.mass_char[i] = static_cast<U>(this->mass_char[i]);
		}
		return New_String;
	}
	else {
		cout << "error new_len != other_len" << endl;
	}
}*/


#endif //class_cpp
