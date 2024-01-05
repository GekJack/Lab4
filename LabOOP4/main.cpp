#include <iostream>
#include "class.h"
int main() {
	String<char> a(112,1);
	try
	{
		a.GetSubstring(0,2);
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}
    return 0;
}