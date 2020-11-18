#pragma once
#include <iostream>

void strCopy(char* const dest, char const* const source);
int strLength(char const* const arr);
int strComp(char const* const str1, char const* const str2);
void strCat(char* const str1, char const* const str2);
int findAndReplace(char* const mainString, char const* const oldSubstr, char const* const newSubstr, int const countRemove=INT_MAX);
void intToCharArr(int const num, char *const dest);
void longToCharArr(long long const num, char *const dest);
void reverseCharArr(char *const arr);
void doubleToCharArr(double const num, char*const arr, short const decimalPlaces=2, bool const roundOff=true);
