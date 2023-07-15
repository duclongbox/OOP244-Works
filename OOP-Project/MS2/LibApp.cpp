/*/////////////////////////////////////////////////////////////////////////
Milestone - #2
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 7/15/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include "LibApp.h"
using namespace std;
namespace sdds {
	// instantiate menu and add yes to item , return true if run success
	bool LibApp::confirm(const char* message) {
		Menu newMenu(message);
		newMenu << "Yes";
		return newMenu.run();
	}
	// simple private functions
	void LibApp::load() {
		cout << "Loading Data" << endl;
	}
	void LibApp::save() {
		cout << "Saving Data" << endl;
	}
	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}
	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}
	void LibApp::newPublication()  {
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?")) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}
	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?")) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}
	void LibApp::checkOutPub() {
		search();
		if (confirm("Check out publication?")) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}
	//constructor
	LibApp::LibApp() :m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
		m_mainMenu << "Add New Publication"
			<< "Remove Publication"
			<< "Checkout publication from library"
			<< "Return publication to library";
		m_exitMenu  << "Save changes and exit"	<< "Cancel and go back to the main menu";
		load();
	}
	//run method
	void LibApp::run()  {
		bool exit = false;
		while (!exit) {
			/*m_mainMenu.viewMenu(std::cout);*/
			unsigned int choice = m_mainMenu.run();
			switch (choice)
			{
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			case 0:
				if (m_changed) {
					unsigned int quitChoice = m_exitMenu.run();
					if (quitChoice == 1) {
						save();
						
						exit = true;
						
					}
					else if (quitChoice == 0) {
						if (confirm("This will discard all the changes are you sure?")) {
							exit = true;
						}
					}
					else if (quitChoice == 2) {
					}
				}
				else {
					
					exit = true;
				
				}
			}
			cout << endl;
		}
		cout << "-------------------------------------------" << endl << "Thanks for using Seneca Library Application" << endl;

	}

}

