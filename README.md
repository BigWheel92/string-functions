# string-functions
An implementation of a few string functions (for character arrays)

1. void strCopy(char* const dest, char const* const source); Copies source into dest.

2. int strLength(char const* const str); Returns the length of string in str.

3. int strComp(char const* const str1, char const* const str2);  Compares str1 and str2 and returns 0 if both are equal, -1 is str1 is smaller and 1 if str1 is greater (based on ASCII differences)

4. void strCat(char* const str1, char const* const str2); append str2 to the end of str1.

5. int findAndReplace(char* const mainString, char const* const oldSubstr, char const* const newSubstr, int const countRemove=INT_MAX);  Replaces oldSubstr in mainString with newSubstr. If the value of countRemove parameter is not passed while calling findAndReplace, all occurrences of oldSubstr are replaced with newSubstr. Otherwise it will replace as many occurrences from left to right as the value of countRemove ( provided actual occurrences>= countRemove). The function returns the actual count of total occurrences replaced.

6. void intToStr(int const num, char *const dest); Converts the integer value passed in num variable into a string and stores in dest.

7. void longToStr(long long const num, char *const dest); Converts the long value passed in num variable into a string and stores it in dest.

8. void reverseStr(char *const str); Reverses the string.

9. void doubleToStr(double const num, char*const dest, short const decimalPlaces=2, bool const roundOff=true); Converts the given double number into a string. decimalPlaces is the number of digits to keep after the decimal point. If roundOff is true, then the number will be rounded off if the first digit of the ignored decimal part is greater than 4. For example: If num=12.935, decimalPlaces=2 and roundOff=true, then the number converted into string will be 12.94.
