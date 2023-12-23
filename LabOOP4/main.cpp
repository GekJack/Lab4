#include <iostream>
#include "class.h"

int main(){
    String<int> a(56, 5);
    a.OutPut();
    String<char> b('f', 5);
    b.OutPut();
    String<int> c(int(), 12);
    b += a;
    b.OutPut();


    
    
    return 0;
}