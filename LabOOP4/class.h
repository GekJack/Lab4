#ifndef class_h
#define class_h
#include <iostream>
template <typename T>
class String {
private:
    T* mass_char;
    int len;
public:
    String();

    String(const String&& other);
    ~String();

};
#include "class.cpp"
#endif //class_h