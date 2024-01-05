#ifndef class_cpp
#define class_cpp
#include "class.h"

template <typename T>
String<T>& String<T> :: operator=(const String& other) {
	if (other.isEmpty()) {
		return *this;
	}
	if (this->mass_char) {
		delete[] mass_char;
	}
	if (this != &other) {
		this->len = other.len;
		mass_char = new T[len];
		for (int i = 0; i < len; i++) {
			mass_char[i] = other.mass_char[i];
		}
	}
	return *this;
}

template<typename T>
String<T>& String<T>::operator=(String&& other)
{
	if (other.isEmpty()) {
		return *this;
	}
	if (this->mass_char) {
		delete[] mass_char;
	}
	if (this != &other) {
		this->len = other.len;
		this->mass_char = other.mass_char;
		other.mass_char = nullptr;
		other.len = 0;
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
template<typename T>
template<typename U>
String<T>::String(U* arr)
{
	int counter = 0;
	while (arr[counter] != T()) {
		counter++;
	}
	this->len = counter + 1;
	this->mass_char = new T[len];
	for (int i = 0; i < this->len; i++) {
		this->mass_char[i] = static_cast<T>(arr[i]);
	}
}
template <typename T>
String<T> :: String(T* arr, int len) {
	this->len = len + 1;
	this->mass_char = new T[this->len];
	for (int i = 0; i < len; i++) {
		this->mass_char[i] = arr[i];
	}
	this->mass_char[this->len - 1] = T();
}

template <typename T>
String<T> ::String(T* first, T* second) {
	if (first > second) {
		cout << "error: first > second, volunteered default constructor" << endl;
		this->len = 11;
		this->mass_char = new T[len];
		for (int i = 0; i < this->len - 1; i++) {
			mass_char[i] = 'a';
		}
		this->mass_char[this->len - 1] = T();
	} else if(first == second){
		this->len = 1;
		this->mass_char = new T[this->len];
		this->mass_char[0] = T();
	} else {
		int counter = 1;
		T* i = first;
		while (i != second){
			counter++;
			i++;
		}
		this->len = counter+1;
		this->mass_char = new T[this->len];
		for (int i = 0; i < this->len-1; i++) {
			this->mass_char[i] = first[i];
		}
		this->mass_char[this->len - 1] = T();
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
	if (pos >= this->len || pos < 0 ) {
		cout << "Error: incorrect length" << endl;
		return T();
	}
	else {
		return this->mass_char[pos];
	}
}
template<typename T>
String<T> String<T>::GetSubstring(int index, int len)
{
	if (index + len < this->len && len > 0) {
		if (this->isEmpty()) {
			return String<T>();
		}
		String<T> Substring(1, len);
		
		for (int i = 0; i < len; i++) {
			Substring[i] = this->mass_char[index + i];
		}
		return Substring;	
	}
	else {
		cout << "error: index or len is not correct" << endl;
	}
	
	return String<T>();
}
template <typename T>
int String<T> :: GetLen() const { // Отримання довжини строки
	return this->len - 1;
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
		int while_choose = 1, side;
		while (while_choose != 0) {
			cout << "Which side we should add the string?(Left(1) or Right(2)?)" << endl;
			cout << "Write the nubmer" << endl;
			cin >> side;
			system("cls");
			if (side != 1 && side != 2) {
				cout << "Write correct side-code please" << endl;
			}
			else {
				while_choose = 0;
			}
		}
		if (side == 2) {
			int new_len = this->len + other.GetLen();
			int old_len = this->len - 1;
			this->RowLengthIncrease(new_len, 0);
			for (int i = 0; i < other.GetLen() + 1; i++) {
				this->mass_char[i + old_len] = static_cast<T>(other.GetCurrentSymbol(i));
			}
			this->mass_char[this->GetLen()] = T();
		}
		if (side == 1) {
			int new_len = this->len + other.GetLen();
			int old_len = other.GetLen();
			this->RowLengthIncrease(new_len, old_len);
			for (int i = 0; i < other.GetLen(); i++) {
				this->mass_char[i] = static_cast<T>(other.GetCurrentSymbol(i));
			}
			this->mass_char[this->len - 1] = T();
		}
	}
	return *this;
}


template <typename T>
void String<T> ::RowLengthIncrease(int new_len, int old_len) {
	T* temp_array = new T[this->len];
	for (int i = 0; i < this->len; i++) {
		temp_array[i] = this->mass_char[i];
	}
	delete[] this->mass_char;
	this->mass_char = new T[new_len];
	for (int i = 0; i < this->len; i++) {
		this->mass_char[i + old_len] = temp_array[i];
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
	int new_len = this->GetLen() * value;
	String<T> dop(T(), new_len);
	int j = 0;
	for (int i = 0; i < new_len; i++) {
		if(this->mass_char[j] != T() && j != this->len - 1){
			dop[i] = this->mass_char[j];
		}
		else {
			i--;
		}
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
template <typename T, typename U>
auto CreateString(U* first, U* second) -> String<decltype(declval<T>() + declval<U>())> {
	if (first && second) {
		if (first < second) {
			int len = (second - first) + 1;
			String<decltype(declval<T>() + declval<U>())> newString(1, len);
			for (int i = 0; i < len; i++) {
				newString[i] = first[i];
			}	 
			//newString.OutPut();
			return newString;
		} 
		else {
			if (first > second) {
				cout << "error: first > second" << endl;
				return String<T>();
			}
			else {
				int len = 1;
				String<decltype(declval<T>() + declval<U>())> newString(1, len);

				for (int i = 0; i < len; i++) {
					newString[i] = first[i];
				}
				return newString;
			}
		}
	}
	cout << "error: mas is nullptr" << endl;
	return String<T>();
}
template <typename T>
String<T>& String<T>::addChar() {
	if (is_same_v<T, char>) {
		char temp;
		cout << endl << "Write string" << endl;
		cout << "if you want to stop press ESC" << endl;
		while (true) {
				temp = _getch();
				if (temp == 27) {
					cout << endl << "---------------------- End ----------------------" << endl;
					break;
				}
				else {
					this->mass_char[this->len - 1] = temp;
					this->RowLengthIncrease(this->len + 1, 0);
					cout << temp;
				}
			}
		this->mass_char[this->len - 1] = '\0';
		
	}
	else {
		cout << "Doesn't work for not char" << endl;
	}
	return *this;
}
#endif //class_cpp
