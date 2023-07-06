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
#include <iostream>
#include "LabelMaker.h"
#include "C:\Users\Admin\source\repos\workshop2\cstring.h"
using namespace std;

namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		//creates a dynamic array of Labels to the size of noOfLabels
		labels = new Label[noOfLabels];
		count = noOfLabels;
	}
	void LabelMaker::readLabels() {
		if (count > 0) {
			cout << "Enter " << count << " labels:" << endl;
		}
		//Gets the contents of the Labels 
		for (int i = 0; i < count; i++) {
			cout << "Enter label number " << i + 1 << endl;
			labels[i].readLabel();
		}
	}
	void LabelMaker::printLabels(){
		//Prints the Labels 
		for (int i = 0; i < count; i++) {
			labels[i].printLabel();
			cout << endl;
		}
	}
	LabelMaker::~LabelMaker() {
		//Deallocates the memory 
		delete[] labels;
		labels = nullptr;
	}
}