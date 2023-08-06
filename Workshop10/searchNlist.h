#ifndef SEARCHNLIST_LIST
#define SEARCHNLIST_LIST
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "Student.h"
using namespace std;
namespace sdds {
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
