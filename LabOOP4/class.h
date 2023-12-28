#ifndef class_h
#define class_h
#include <iostream>
using namespace std;
template <typename T>
class String {
private:
    T* mass_char;
    int len;
    void resize(int new_len);
public:
    String();
    String(T value, int len);
    String(const String<T>& other);
    template <typename U>
    String(const String<U>& other);
    String(String<T>&& other);
    String(T* arr);
    String(T* arr, int len);
    String(T* first, T* second);
    //template <typename U>
    //String(const String<U>&& other);
    ~String();

    //template <typename U>
    //U ConvertStringType(int new_len);

    void Clear_String();
    
    void OutPut() const;
    bool isEmpty() const ;
    int GetLen() const;
    T GetCurrentSymbol(int pos) const;

    template <typename U>
    String<T>& operator+=(const String<U>& other);
    T operator[](const int index) const;
    T& operator[](const int index);
    String<T>& operator=(const String& other);
    String<T> operator*(const int value) const;
    /*friend String<T> operator*(int value, const String<T>& right);*/
    bool operator==(const String& other);
    bool operator!=(const String& other);
    bool operator<(const String& other);
    bool operator>(const String& other);
    bool operator<=(const String& other);
    bool operator>=(const String& other);
};
#include "class.cpp"
#endif //class_h