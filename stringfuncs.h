#pragma once
#include <iostream>

void strCopy(char* const dest, char const* const source);
int strLength(char const* const str);
int strComp(char const* const str1, char const* const str2);
void strCat(char* const str1, char const* const str2);
int findAndReplace(char* const mainString, char const* const oldSubstr, char const* const newSubstr, int const countRemove=INT_MAX);
void intToStr(int const num, char *const dest);
void longToStr(long long const num, char *const dest);
void reverseStr(char *const str);
void doubleToStr(double const num, char*const dest, short const decimalPlaces=2, bool const roundOff=true);
int strToInt(char const * const src); 
