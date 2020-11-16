#include <iostream>
using namespace std;
#include "stringfuncs.h"

int main()
{
	char myString[100] = "My work is related to Comp Science. I like Comp Science.";
	char subString[10] = "Comp";
	cout << myString << endl;
	findAndReplace(myString, subString, "Computer");
	cout << myString;
	return 0;
}