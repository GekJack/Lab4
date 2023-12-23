#include <iostream>
#include "class.h"

int main(){
    String<int> a(10, 5);
    a.OutPut();
    String<int> b(102, 5);
    b.OutPut();
    String<char> c(b);
    c.OutPut();
    return 0;
}