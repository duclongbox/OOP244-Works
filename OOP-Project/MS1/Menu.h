#ifndef MENU_H
#define MENU_H
#include <iostream>

const unsigned  MAX_MENU_ITEMS = 20;
namespace sdds {
	class MenuItem {
		char* m_content;
		friend class Menu;
		MenuItem() {};
		MenuItem(const char* content = nullptr);
		MenuItem(const MenuItem& other) = delete;
		MenuItem& operator=(const MenuItem& other) = delete;
		~MenuItem();
		operator bool() const;
		operator const char* () const;
		void display(std::ostream& ostr ) const;
		friend class Menu;
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
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		friend std::ostream& operator<<(std::ostream& os, const Menu& menu);

		const char* operator[](unsigned index) const;
	};
}

#endif