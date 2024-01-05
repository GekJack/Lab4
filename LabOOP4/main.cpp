#include <iostream>
#include "class.h"
int main() {
    String<int> a(112, 5);
    String<char> b('w', 6);
    a.OutPut();
    b.OutPut();
    int arr[5] = { 1, 2, 3, 4, 5 };
    a = CreateString<int, int>(&arr[0], &arr[4]);
    a.OutPut();
    return 0;
}