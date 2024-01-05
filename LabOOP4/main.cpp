#include <iostream>
#include "class.h"
int main() {
	double array[6] = { 1.1,2.3,3.6,4.12,5.23, 0};
	String<int> str1(112, 3);
	String<char> str2(array);
	String<int> str3(str1);
	int array1[4] = {1,2,3, 0};
	String<int> str5(array1);
	try
	{
		str2 = str1 * 3;
		str2.addChar();
		str2.Clear_String();
		str1.OutPut();
		str2.OutPut();
		
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		str3.OutPut();
		try
		{
			String<int> str4 = CreateString<int, double>(&array[2], &array[4]);
			str4.OutPut();
			str4 += str3;
			str3 += str5;
			str4.OutPut();
			str3.OutPut();
			if (str4 < str3) {
				cout << "True" << endl;
			}
			else {
				cout << "False";
			}
		}
		catch (const char* msg2)
		{
			cout << msg2 << endl;
		}
	}
    return 0;
}