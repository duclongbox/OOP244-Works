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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <C:\Users\Admin\source\repos\workshop2\cstring.h>
#include "Label.h"
#include <cstring>
using namespace std;
namespace sdds {
	Label::Label() {
		strCpy(frame, "+-+|+-+|"); //defaults the frame to "+-+|+-+|"
		labelContent = nullptr; //Creates an empty label
	}
	Label::Label(const char* frameArg) {
		labelContent = nullptr; //Creates an empty label
		strCpy(frame,frameArg); 
	}
	Label::Label(const char* frameArg, const char* content) {
		strCpy(frame, frameArg); // set to frameArg
		// dynamically allocate a memory for labelContent
		labelContent = new char[strLen(content) + 1-2];  
		strnCpy(labelContent, content,70+2);
	}
	Label::~Label() {
		// deallocate the memeroy for labelContent
		delete[] labelContent;
		labelContent = nullptr;
	}
	void Label::readLabel() {
		char input[71];
		cin.ignore(2); // ignore two first characters
		cin.getline(input, 71);
		// ignore two first character '> '
		labelContent = new char[strlen(input) + 1-2];
		// copy from the input[2]
		strCpy(labelContent, input+2);
	}
	std::ostream& Label::printLabel()const {
		if (labelContent != nullptr) {
			int length = (labelContent != nullptr) ? strLen(labelContent) : 0;

			// print top line
			cout << frame[0];
			for (int i = 0; i < length + 2; i++) {
				cout << frame[1];
			}
			cout << frame[2] << std::endl;
			
			
			// print the space
			cout << frame[3]; 
			for (int i = 0; i < length + 2; i++) {
				cout << " ";
			}
			cout << frame[3] << std::endl;

			// print the content
			if (labelContent != nullptr) {
				cout << frame[7] << ' ' << labelContent << ' ' << frame[3] << std::endl;
			}

			// print the space
			cout << frame[3]; 
			for (int i = 0; i < length + 2; i++) {
				cout << " ";
			}
			cout << frame[3] << std::endl;
			
			// print the last line 
			cout << frame[6];
			for (int i = 0; i < length + 2; i++) {
				cout << frame[5];
			}
			cout << frame[4];
		}
		return cout;
	}

}