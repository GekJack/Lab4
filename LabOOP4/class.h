#ifndef class_h
#define class_h
#include <iostream>
#include <type_traits>
#include <conio.h>
using namespace std;
template <typename T>
class String {
private:
    T* mass_char;
    int len;
    void RowLengthIncrease(int new_len, int old_len);
public:
    String();
    String(T value, int len); 
    String(const String<T>& other);
    template <typename U>
    String(const String<U>& other);
    String(String<T>&& other);
    String(T* arr);
    template <typename U>
    String(U* arr);
    String(T* arr, int len);
    String(T* first, T* second);
    ~String();
    void Clear_String();
    String<T>& addChar();
    void OutPut() const;
    bool isEmpty() const ;
    int GetLen() const;
    T GetCurrentSymbol(int pos) const;
    String<T> GetSubstring(int index, int len);

    template <typename U>
    String<T>& operator+=(const String<U>& other);
    T operator[](const int index) const;
    T& operator[](const int index);
    String<T>& operator=(const String& other);
    String<T>& operator=(String&& other);
    String<T> operator*(const int value) const;
    bool operator==(const String& other);
    bool operator!=(const String& other);
    bool operator<(const String& other);
    bool operator>(const String& other);
    bool operator<=(const String& other);
    bool operator>=(const String& other);
};
    template <typename T, typename U>
    auto CreateString(U* first, U* second) -> String<decltype(declval<T>() + declval<U>())>;
#include "class.cpp"
#endif //class_h