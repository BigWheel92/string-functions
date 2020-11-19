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




int findAndReplace(char* const mainString, char const* const oldSubstr, char const* const newSubstr, int const countRemove )
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

void reverseCharArr(char*const arr)
{
	for (int i = 0, j = strLength(arr)-1; i < j; i++, j--)
	{
		char temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}


void longToCharArr(long long const num, char *const dest)
{
	long long temp = abs(num);
	short i = 0;
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

void intToCharArr(int const num, char *const dest)
{
	int temp = abs(num);
	short i = 0;
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


void doubleToCharArr(double const num, char *const dest, short const decimalPlaces, bool const roundOff)
{
	//converting the digits before the decimal point into string.
	long long temp = abs(num);
	short i = 0;
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
	
	//reversing the digits.
	for (short j = i - 1, k = 0; j > k; j--, k++)
	{
	
		char temp = dest[j];
		dest[j] = dest[k];
		dest[k] = temp;
	}
	
	//now converting the decimal part into string and appending to the end of character array
	temp = abs(num);
	double decimalPart = abs(num) - temp;
	short count = 0;
		
	if (decimalPlaces > 0)
	{
		dest[i] = '.';
		i++;
	
		while (count < decimalPlaces)
		{
			decimalPart = decimalPart * 10;
			short digit = decimalPart;
			dest[i] = digit + '0';
			i++;
			count++;
			decimalPart = decimalPart - digit;
			
		}
	}
	//finished converting the required number of digits after decimal point into string.

	/*now going to round off the converted number if the first digit of
	decimal part which is now not part of the converted decimal is greater than 4.*/
	
	short firstDigitOfDroppedDecimalPart = decimalPart * 10;

	if (firstDigitOfDroppedDecimalPart >=5 && roundOff==true)
	{
		for (short j = i - 1; j >= 0; j--) //round off will begin from the end 
		{								//and continue till the beginning (right to left)
			if (dest[j] == '.')
				continue;

			if (dest[j] == '-')
				break;

			if (dest[j] < '9')
			{
				dest[j]++;
				break;
			}

			
			if (j == 0 || (j == 1 && dest[0] == '-'))
			{ 
				//this part converts number like 9.9 into 10.0 during rounding off.
				
				dest[j] = '0'; //we had a 9 at index j.

				//shifting digits one step right so that there is a space for putting 1 (if the first digit of decimal number is 9 then it will be converted to 10 during round off)
				for (short k = i - 1; k >= j; k--)
				{
					dest[k + 1] = dest[k];
				}
				dest[j] = '1';
				i++;
			}

			else
			{
				dest[j] = '0';  //if this 9 is not the first digit, then no need to insert 1.
			}

		}

	}
	dest[i] = '\0';

	/*it is possible to get -0 in the string if the number was -0.9, and
	  and we passed decimalPlaces=0 with roundOff=false. similarly we 
	  can get -0.00 if the number was -0.009 with decimalPlaces=2 and roundOff=0
	  In such cases, we will remove - sign.*/
	bool flag = false;
	if (dest[0] == '-')
	{
		for (short j = 1; j < i && flag == false; j++)
		{
			if (dest[j]>='1' && dest[j]<='9')
			{
				flag = true;
			}
		}
	}
	
	if (flag==false)
	findAndReplace(dest, "-", "", 1);  
		
}
