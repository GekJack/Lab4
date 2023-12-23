#ifndef class_h
#define class_h
#include <iostream>
using namespace std;
template <typename T>
class String {
private:
    T* mass_char;
    int len;
public:
    String();
    String(T value, int len);
    template <typename U>
    String(const String<U>& other);
    String(const String<T>&& other);
    ~String();
    void OutPut() const;

    int GetLen() const;
    T GetCurrentSymbol(int pos) const;

    //template <typename U>
    //U ConvertStringType(int new_len);
    bool isEmpty() const;

};
#include "class.cpp"
#endif //class_h