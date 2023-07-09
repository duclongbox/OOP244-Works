#ifndef MENU_H
#define MENU_H
class MenuItem {
	char* m_content;
	friend class Menu;
	//MenuItem();
	MenuItem(const char* content = nullptr);
	MenuItem(const MenuItem& other) = delete;
	MenuItem& operator=(const MenuItem& other) = delete;
	~MenuItem();
};


#endif