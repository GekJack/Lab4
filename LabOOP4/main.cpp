#include <iostream>
#include "class.h"

int main() {
    String<int> a(1, 4);
    String<int> b(2, 5);
    a += b;
    a.OutPut();
    return 0;
}