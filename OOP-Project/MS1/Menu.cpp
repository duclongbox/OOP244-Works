#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"
#include "Utils.h"
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
	void MenuItem::display(std::ostream& os) const {
		if (m_content != nullptr) {
			os << m_content;
		}
	}
	// constructor 
	Menu::Menu(){
		// no MenuItems
		m_numOfItems = 0;
		//A Menu is always created empty 
		m_menuItems[0] = nullptr;
	}
	Menu::Menu(const char* title) {
		m_numOfItems = 0;
		m_menuItems[0] = nullptr;

		if (title != nullptr) {
			m_title.m_content = new char[strlen(title) + 1];
			strcpy(m_title.m_content, title);
			
		}
	}
	//destructor 
	Menu::~Menu() {
		delete[] m_title.m_content;
		//loop through menu items array to delete each pointer
		for (int i = 0; i < m_numOfItems; i++) {
			delete m_menuItems[i];
			m_menuItems[i] = nullptr;
		}
	}
	// display the title of the menu
	std::ostream& Menu::viewTitle(std::ostream& ostr) const {
		if (m_title.m_content != nullptr) {
			ostr << m_title.m_content;
		}
		return ostr;
	}
	// display the entire menu
	std::ostream& Menu::viewMenu(std::ostream& ostr)const {
		viewTitle(ostr);
		ostr << endl;
		for (int i = 0; i < m_numOfItems; i++) {
			ostr.setf(ios::right);
			ostr.width(2);
			ostr.fill();
			ostr << i + 1;
			ostr << "- ";
			m_menuItems[i]->display(ostr);
			ostr << endl;
		}
		ostr << "0 - Exit" << endl;
		ostr << "> ";
		return ostr;
	}
	//display the menu and get the user selection
	unsigned int Menu::run() const {
		viewMenu(std::cout);
		unsigned int select = read(m_numOfItems);
		
		return select;
	}
	// return the selection in a different way
	unsigned int Menu::operator~() const {
		return run();
	}
	//add menu Item to the menu 
	Menu& Menu::operator<<(const char* menuitemConent) {
		if (m_numOfItems < MAX_MENU_ITEMS) {
			m_menuItems[m_numOfItems] = new MenuItem(menuitemConent);
			m_numOfItems++;
		}
		return *this;
	}
	// overload the conversion integer
	Menu::operator int() const {
		return m_numOfItems;
	}
	// bool one or more items
	Menu::operator bool() const {
		return m_numOfItems > 0;
	}
	//print the title of menu
	std::ostream& operator<<(std::ostream& os, const Menu& menu) {
		 menu.viewTitle(os);
		 return os;
	}
	// return the item with the index
	const char* Menu::operator[](unsigned index) const {
		if (m_menuItems != nullptr) {
			index = index % m_numOfItems;
		}
		return m_menuItems[index]->m_content;
	}

}