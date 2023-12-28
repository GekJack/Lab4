#include <iostream>
#include "class.h"

int main() {
    char mass[5] = {'5','4','3','2','1'};
    String<char> a(&mass[2], &mass[4]);
    String<int> b(56, 5);
    a += b;
    a.OutPut();
    return 0;
}