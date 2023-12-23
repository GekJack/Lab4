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
    String(const String&& other);
    ~String();
    
};
#include "class.cpp"
#endif //class_h