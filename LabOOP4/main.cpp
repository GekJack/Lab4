#include <iostream>
#include "class.h"

int main(){
    int arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = 5;

    }
//    int counter = sizeof(arr);
    for (int i = 0; i < 5; i++) {
       // cout << arr[i] << endl;
    }
    String<int> a(arr);
    cout << a.GetLen() << endl;
    a.OutPut();
    return 0;
}