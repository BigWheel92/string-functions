# string-functions
An implementation of a few string functions (for character arrays)

1. void strCopy(char* const dest, char const* const source): Copies source into dest.

2. int strLength(char const* const arr): Returns the length of string in arr.

3. int strComp(char const* const str1, char const* const str2):  Compares str1 and str2 and returns 0 if both are equal, -1 is str1 is smaller and 1 if str1 is greater (based on ASCII differences)

4. void strCat(char* const str1, char const* const str2): append str2 to the end of str1.

5. int findAndReplace(char* const mainString, char const* const oldSubstr, char const* const newSubstr, int const countRemove=INT_MAX):  Replaces oldSubstr in mainString with newSubstr. If the value of countRemove parameter is not passed while calling findAndReplace, all occurrences of oldSubstr are replaced with newSubstr. Otherwise it will replace as many occurrences from left to right as the value of countRemove ( provided actual occurrences>= countRemove). The function returns the actual count of total occurrences replaced.

6. void intToCharArr(int const num, char* dest): Converts the integer value passed in num variable into a string and stores in dest.

7. void longToCharArr(long long const num, char* dest): Converts the long value passed in num variable into a string and stores it in dest.

8. void reverseCharArr(char* arr):  Reverses the string.
