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
    String( String<U>& other);
    String(const String&& other);
    ~String();
    void OutPut();
    bool isEmpty();
    int GetLen();
    T GetCurrentSymbol(int pos);
};
#include "class.cpp"
#endif //class_h