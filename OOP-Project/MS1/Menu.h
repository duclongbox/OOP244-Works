#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <cstring>
const unsigned  MAX_MENU_ITEMS = 20;
namespace sdds {
	class MenuItem {
		char* m_content{ nullptr };
		friend class Menu;
		MenuItem(const char* content = nullptr);
		MenuItem(const MenuItem& other) = delete;
		MenuItem& operator=(const MenuItem& other) = delete;
		~MenuItem();
		operator bool() const;
		operator const char* () const;
		void display(std::ostream& ostr ) const;
		
	};
	class Menu {
		MenuItem m_title;
		MenuItem* m_menuItems[MAX_MENU_ITEMS];
		int m_numOfItems;

	public:
		Menu();
		Menu(const char* title);
		Menu(const Menu& other) = delete;
		Menu& operator=(const Menu& other) = delete;
		~Menu();
		std::ostream& viewTitle(std::ostream& ostr) const;
		std::ostream& viewMenu(std::ostream& ostr)const;
		unsigned int run() const;
		unsigned int operator~() const;
		Menu& operator<<(const char* menuitemConent);
		operator unsigned int() const;
		operator bool() const;
		const char* operator[](unsigned index) const;
	};
	std::ostream& operator<<(std::ostream& os, const Menu& menu);

}

#endif