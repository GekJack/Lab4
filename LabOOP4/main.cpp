#include <iostream>
#include "class.h"
int main() {
    String<int> a(112, 5);
    String<char> b('w', 6);
    a.OutPut();
    b.OutPut();
    b += a;
    b.OutPut();

    return 0;
}