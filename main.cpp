#include <iostream>
using namespace std;
#include "stringfuncs.h"

int main()
{
	char myString[100] = "My work is related to Comp Science. I like Comp Science.";
	char subString[10] = "Comp";
	cout << myString << endl;
	findAndReplace(myString, subString, "Computer");
	cout << myString << endl;
	
	doubleToCharArr(-29.999, subString, 2, true);
	cout << subString << endl;

	doubleToCharArr(-29.999, subString, 2, false);
	cout << subString << endl;

	doubleToCharArr(-9.99, subString, 1, true);
	cout << subString << endl;

	doubleToCharArr(-0.999, subString, 2, true);
	cout << subString << endl;

	doubleToCharArr(-0.999, subString, 0, true);
	cout << subString << endl;

	doubleToCharArr(-0.999, subString, 0, false);
	cout << subString << endl;

	doubleToCharArr(-0.099, subString, 1, false);
	cout << subString << endl;

	return 0;
}
