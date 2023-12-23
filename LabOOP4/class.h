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
    int GetLen();
    T GetCurrentSymbol(int pos);
    String();
    String(T value, int len);
    String(const String&& other);
    template <typename U>
    String( String<U>& other);
    ~String();
    void OutPut();
};
#include "class.cpp"
#endif //class_h