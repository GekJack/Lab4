#include <iostream>
#include "class.h"

int main(){
    String<int> a(10, 5);
    a.OutPut();
    String<int> b(102, 5);
    b.OutPut();
    String<int> c(5, 12);
    c.OutPut();

    c.Clear_String();
    c.OutPut();


    
    
    return 0;
}