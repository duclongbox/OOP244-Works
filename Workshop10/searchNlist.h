/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #10
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 8/6/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SEARCHNLIST_LIST
#define SEARCHNLIST_LIST
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "Student.h"
using namespace std;
namespace sdds {
	/// <summary>
	/// 
	/// T must support the "==" operator
	/// T1 should not be a pointer,should be compatible with T so that the comparision can provide a valid result
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="T1"></typeparam>
	/// <param name="collection">Templated object to store the searched value</param>
	/// <param name="arrayObject"></param>
	/// <param name="noOfElement"></param>
	/// <param name="keyValue"> A value to search for </param>
	/// <returns></returns>
	template <typename T, typename T1>
	bool search(Collection<T>& collection,   T* arrayObject, int noOfElement, T1 keyValue) {
		// search function return true if one match is found
		bool result = false;
		for (int i = 0; i < noOfElement; i++) {
			if (arrayObject[i] == keyValue) {
				collection.add(arrayObject[i]);
				result = true;
			}
		}
		return result;
	}
	/// <summary>
	/// T3 should provide the overload operator <<
	/// </summary>
	/// <typeparam name="T3"></typeparam>
	/// <param name="title"></param>
	/// <param name="objects"></param>
	/// <param name="noOfElement"></param>
	template <typename T3>
	void listArrayElements(const char* title, const T3* objects, int noOfElement) {
		// print the title
		cout << title << endl;
		//print all the element
		for (int i = 0; i < noOfElement; i++) {
			cout << i+1 << ": " << objects[i] << endl;
		}
	}

	
}
#endif // !SEARCHNLIST_LIST
