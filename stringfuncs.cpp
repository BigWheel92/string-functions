#pragma once
#include "stringfuncs.h"

void strCopy(char * const dest, char const*const source)
{
	//alternative 1.
	int i = 0;
	for (; source[i] != '\0'; i++)
	{
		dest[i] = source[i];
	}
	dest[i]='\0';

	////alternative 2
	//int length = strLength(source);
	//for (int i = 0; i <= length; i++)
	//{
	//	dest[i] = source[i];
	//}
}

int strLength(char const* const arr)
{
	
	int length = 0;

	while (arr[length] != '\0')
	{
		length++;
	}

	return length;
}



int strComp(char const* const str1, char const* const str2)
{
	//putting the length of larger string in length variable.
	int length = strLength(str1);

	if (length < strLength(str2))
	{
		length = strLength(str2);
	}

	for (int i = 0; i < length; i++)
	{
		int diff = str1[i] - str2[i];
		if (diff == 0)
			continue;

		else if (diff < 0)
		{
			return -1;
		}

		else return 1;
	}
	return 0;
}




int findAndReplace(char * const mainString, char const * const oldSubstr, char const *const newSubstr, int const countRemove)
{
	int oldSubStrLength = strLength(oldSubstr);
	int newSubStrLength = strLength(newSubstr);
	int mainStringLength = strLength(mainString);
	int occurrancesRemoved = 0;

	for (int i = 0; mainString[i] != '\0' && occurrancesRemoved < countRemove; )
	{
		bool flag = true;
		for (int j = 0; j < oldSubStrLength && flag; j++)
		{
			if (mainString[i + j] != oldSubstr[j])
				flag = false;
		}

		if (flag == true) //replace with new string
		{
			occurrancesRemoved++;
			if (oldSubStrLength == newSubStrLength) //if the string to be replaced is equal to the new string in terms of length
			{
				for (int j = 0; j < oldSubStrLength; j++)
				{
					mainString[i + j] = newSubstr[j];
				}

			}

			//if the length of replaced substring is greater than new substring.
			else if (oldSubStrLength > newSubStrLength)
			{
				for (int j = 0; j < newSubStrLength; j++)
				{
					mainString[i + j] = newSubstr[j];
				}

				//shifting the remaining characters of main string  (oldSubStrLength-newSubStrLength)times left.
				int diff = oldSubStrLength - newSubStrLength;
				int length = strLength(mainString);
				for (int j = i + newSubStrLength; j + diff <= length; j++)
				{
					mainString[j] = mainString[j + diff];
				}
			}


			else //the length of replaced substring is less than new substring.
			{
				//copying those characters of main string first that can replace oldSubStr's characters.
				for (int j = 0; j < oldSubStrLength; j++)
				{
					mainString[i + j] = newSubstr[j];
				}

				int diff = newSubStrLength - oldSubStrLength;
				int length = strLength(mainString);

				//shifting characters of main string present after currently replaced oldSubStr to right to make room for remaining characters of newSubStr
				for (int j = strLength(mainString)+diff; j>=i+oldSubStrLength; j--)
				{
					mainString[j] = mainString[j-diff];
				}

				//copying the remaining elements of newSubStr
				for (int j = i + oldSubStrLength, k=oldSubStrLength; k<newSubStrLength; j++, k++)
				{
					mainString[j] = newSubstr[k];

				}
			
			}

			i += newSubStrLength;
		}

		else i++;
	}

	return occurrancesRemoved;
}

void strCat(char* const str1, char const* const str2)
{
	int i = strLength(str1);

	for (int j = 0; str2[j] != '\0'; i++, j++)
	{
		str1[i] = str2[j];
	}

	str1[i] = '\0';
}

void reverseCharArr(char* arr)
{
	for (int i = 0, j = strLength(arr)-1; i < j; i++, j--)
	{
		char temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}


void longToCharArr(long long const num, char* dest)
{
	long long temp = abs(num);
	int i = 0;
	do
	{
		short digit = temp % 10;
		temp = temp / 10;
		dest[i] = digit + '0';
		i++;

	} while (temp != 0);

	if (num < 0)
	{
		dest[i] = '-';
		i++;
	}
	dest[i] = '\0';
	reverseCharArr(dest);
}

void intToCharArr(int const num, char* dest)
{
	int temp = abs(num);
	int i = 0;
	do
	{ 
		short digit = temp % 10;
		temp = temp / 10;
		dest[i] = digit + '0';
		i++;

	} while (temp != 0);

	if (num < 0)
	{
		dest[i] = '-';
		i++;
	}
	dest[i] = '\0';
	reverseCharArr(dest);
}