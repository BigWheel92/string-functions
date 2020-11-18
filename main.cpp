#include <iostream>
using namespace std;
#include "stringfuncs.h"

int main()
{
	char myString[100] = "My work is related to Comp Science. I like Comp Science.";
	char substr[10] = "Comp";
	cout << myString << endl;
	findAndReplace(myString, substr, "Computer");
	cout << myString << endl;


	char num[20];

	longToCharArr(-23, num);
	cout << num << endl;

	doubleToCharArr(-29.999, num, 2, true);
	cout << num << endl;

	doubleToCharArr(-29.999, num, 2, false);
	cout << num << endl;

	doubleToCharArr(-9.99, num, 1, true);
	cout << num << endl;

	doubleToCharArr(-0.999, num, 2, true);
	cout << num << endl;

	doubleToCharArr(-0.999, num, 0, true);
	cout << num << endl;

	doubleToCharArr(-0.999, num, 0, false);
	cout << num << endl;

	doubleToCharArr(-0.099, num, 1, false);
	cout << num << endl;

	return 0;
}