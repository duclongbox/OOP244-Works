#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"

using namespace std;
namespace sdds {
	// constructor Allocates and sets the content of the MenuItem
	MenuItem::MenuItem(const char* content) {
		m_content = nullptr;
		if (content != nullptr) {
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
	}
	//destructor
	MenuItem::~MenuItem() {
		delete[] m_content;
		m_content = nullptr;
	}
	// bool cast operator
	MenuItem::operator bool() const {
		return m_content != nullptr;
	}
	// return the address held on m_content
	MenuItem::operator const char* () const {
		return (const char*)m_content;
	 }
	// display the content if it not empty
	void MenuItem::display(std::ostream& ostr) const {
		if (m_content != nullptr) {
			ostr << m_content;
		}
	}
}