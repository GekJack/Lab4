#ifndef class_cpp
#define class_cpp
#include "class.h"

template <typename T>
String<T>& String<T> :: operator=(const String& other) {
	if (this != &other) {
		delete[] mass_char;
		this->len = other.len;
		mass_char = new T[len];
		for (int i = 0; i < len; i++) {
			mass_char[i] = other.mass_char[i];
		}
	}
	return *this;
}

template <typename T>
String<T> :: String(T* arr) {
	int counter = 0;
	while (arr[counter] != T()) {
		counter++;
	}
	this->len = counter + 1;
	this->mass_char = new T[len];
	for (int i = 0; i < this->len; i++) {
		this->mass_char[i] = arr[i];
	}
}

template <typename T>
String<T> :: String() { // Конструктор за замовченням
	this->len = 11;
	this->mass_char = new T[len];
	for (int i = 0; i < this->len - 1; i++) {
		mass_char[i] = 'a';
	}
	this->mass_char[this->len - 1] = T();
}
template <typename T>
String<T> :: String(T value, int len) { // Конструктор одного значення
	this->len = len + 1;
	this->mass_char = new T[this->len];
	for (int i = 0; i < len; i++) {
		this->mass_char[i] = value;
	}
	this->mass_char[this->len - 1] = T();
}
template <typename T>
template <typename U>
String<T> :: String(const String<U>& other){ // Конструктор копирования
	this->mass_char = new T[other.GetLen()];
	this->len = other.GetLen();
	for (int i = 0; i < this->len; i++) {
		this->mass_char[i] = static_cast<T>(other.GetCurrentSymbol(i));
	}
}

template <typename T>
String<T> :: String(const String<T>& other) { // Конструктор копирования
	this->mass_char = new T[other.GetLen()];
	this->len = other.GetLen();
	for (int i = 0; i < this->len; i++) {
		this->mass_char[i] = other.GetCurrentSymbol(i);
	}
}

template <typename T>
String<T> :: String(String<T>&& other) : //Конструктор переміщення
	mass_char(other.mass_char), len(other.len)
{
	other.len = 0;
	other.mass_char = nullptr;
}

//template <typename T>
//template <typename U>
//String<T> ::String(const String<U>&& other) : //Конструктор переміщення
//	mass_char(other.mass_char), len(other.len)
//{
//	other.len = 0;
//	other.mass_char = nullptr;
//}

template <typename T>
String<T> :: ~String() { // Деструктор
	if (this->mass_char) {
		delete[] this->mass_char;
		this->mass_char = nullptr;
	}
	this->len = 0;
}
template <typename T>
void String<T> :: OutPut() const{ // Вивід
	if (this->isEmpty()) {
		cout << "The string is empty" << endl;
	}
	else {
		for (int i = 0; i < this->len - 1; i++) {
			cout << mass_char[i];
		}
		cout << endl;
	}
}
template <typename T> 
T String<T> :: GetCurrentSymbol(int pos) const { // Отримання символа за його позицією в строці
	return this->mass_char[pos];
}
template <typename T>
int String<T> :: GetLen() const { // Отримання довжини строки
	return this->len;
}
template <typename T>
bool String<T> :: isEmpty() const{
	bool status = true;
	if (this->mass_char) {
		for (int i = 0; i < this->len; i++) {
			if (this->mass_char[i] != T()) {
				status = false;
				break;
			}
		}
	}
	return status;
}
template <typename T>
template <typename U>
String<T>& String<T> :: operator+=(const String<U>& other) {
	if (!other.isEmpty()) {
		int new_len = this->len + other.GetLen();
		int old_len = this->len;
		this->resize(new_len);
		for (int i = 0; i < other.GetLen(); i++) {
			this->mass_char[i + old_len] = static_cast<T>(other.GetCurrentSymbol(i));
		}
	}
	return *this;
}

template <typename T>
void String<T> :: resize(int new_len) {
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
template<typename T>
void String<T> :: Clear_String() {
	if (this->mass_char) {
		delete[] this->mass_char;
		this->mass_char = nullptr;
		this->len = 0;
	}
}

template<typename T>
T String<T> :: operator[](const int index) const{
	return this->mass_char[index];
}

template<typename T>
T& String<T> :: operator[](const int index) {
	return this->mass_char[index];
}

template <typename T>
String<T> String<T> :: operator*(const int value) const{
	if (value <= 0) {
		return String(T(), this->len);
	}
	String<T> dop;
	int j = 0;
	dop.resize(this->len * value);
	for (int i = 0; i < this->len * value; i++) {
		dop[i] = this->mass_char[j];
		j++;
		if (j == this->len) {
			j = 0;
		}
	}
	return dop;
}


template <typename T>

bool String<T> :: operator==(const String& other) {
	if (this->len != other.len) {
		return false;
	}
	for (int i = 0; i < this->len; i++) {
		if (this->mass_char[i] != other[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool String<T> :: operator!=(const String& other) {
	for (int i = 0; i < this->len; i++) {
		if (this->mass_char[i] != other[i]) {
			return true;
		}
	}
		return false;
}

template <typename T>
bool String<T> :: operator<(const String& other) {
	if (*(this) == other) {
		return false;
	}
	for (int i = 0; i < this->len; i++) {
		if (this->mass_char[i] < other[i]) {
			return true;
		}
	}
	if (this->len < other.len) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
bool String<T> :: operator>(const String& other) {
	if (*(this) == other) {
		return false;
	}
	for (int i = 0; i < this->len; i++) {
		if (this->mass_char[i] > other[i]) {
			return true;
		}
	}
	if (this->len > other.len) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
bool String<T> :: operator>=(const String& other) {
	if ((*(this) == other) || (*(this) > other)){
		return true;
	} else {
		return false;
	}
}

template <typename T>
bool String<T> :: operator<=(const String& other) {
	if ((*(this) == other) || (*(this) < other)){
		return true;
	} else {
		return false;
	}
}

#endif //class_cpp
