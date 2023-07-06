/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P2)
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 6/1/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include<iostream>
#include "cstring.h"

namespace sdds {
	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
		

	}
	void strnCpy(char* des, const char* src, int len) {
		/*int i;
		for (i = 0; src[i] != '\0' && i<len; i++) {
			des[i] = src[i];
		}
		if (i != len) {
			des[i] == '\0';
		}*/
		int i = 0;

		if (strLen(src) >= len) {
			while (i < len) {
				des[i] = src[i];
				i++;
			}
		}
		else
		{
			while (i < strLen(src)) {
				des[i] = src[i];
				i++;
			}
		}
		// Set the last index to be NULL value
		des[i] = '\0';
	
	}
	int strCmp(const char* s1, const char* s2) {
		int i;
		for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
			if (s1[i] > s2[i])
				return 1;
			
			if (s1[i]<s2[i])
				return -1;
		}
		if (s1[i] == '\0' && s2[i] == '\0')
			return 0; 
		else if (s1[i] == '\0' && s2[i] != '\0')
			return -1;
		else
			return 1;
		
	}
	int strnCmp(const char* s1, const char* s2, int len) {
		int i;
		for (i = 0; i < len && s1[i] != '\0' && s2[i] != '\0' ; i++) {
			if (s1[i] > s2[i])
				return 1;

			if (s1[i] < s2[i])
				return -1;
		}
		if (i==len)
			return 0;
		else if (s1[i] == '\0' && s2[i] != '\0')
			return -1;
		else
			return 1;
	}
	int strLen(const char* s) {
		/*int i,count=0;
		for (i = 0; s[i] != '\0'; i++) {
			count++;
		}
		return count;*/
		int length = 0;

		while (s[length])
		{
			length++;
		}
		return length;
	}
	const char* strStr(const char* str1, const char* str2) {
		int i, j, k;

		for (i = 0; str1[i] != '\0'; i++) {
			j = 0;
			k = i;

			while (str1[k] == str2[j] && str2[j] != '\0') {
				k++;
				j++;
			}

			if (str2[j] == '\0') {
				return &str1[i];
			}
		}
		return nullptr;
		
	}
	void strCat(char* des, const char* src) {
		int i=0, j;
		while (des[i] != '\0') {
			i++;
		}
		for (j = 0; src[j] != '\0'; j++) {
			des[i] = src[j];
			i++;

		}
		des[i] = '\0';


	}
}


