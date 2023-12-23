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
    template <typename U>
    String(const String<U>& other);
    String(const String<T>&& other);
    ~String();
    void OutPut() const;

    int GetLen() const;
    T GetCurrentSymbol(int pos) const;
    
    bool isEmpty() const;
    //template <typename U>
    //U ConvertStringType(int new_len);

    void Clear_String();
    

    void OutPut() const;
    bool isEmpty() const ;
    int GetLen() const;
    T GetCurrentSymbol(int pos) const;

    template <typename U>
    String<T>& operator+=(const String<U>& other);
};
#include "class.cpp"
#endif //class_h