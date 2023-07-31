#include <iostream>
#include <fstream>
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
		ifstream infile(m_filename);
		Publication* p[1000]{};
		char type{};
		int i;
		for (i = 0; infile; i++) {
			infile >> type;
			infile.ignore();
			if (infile) {
				// dynamically instantiating the corresponding object into the next available PPA element
				if (type == 'P')
					p[i] = new Publication;
				else if (type == 'B')
					p[i] = new Book;
				if (p[i]) {
					infile >> *m_publication[i]; //extract the remain object to 
					NOLP++;
					LLRN = m_publication[i]->getRef(); // set the reference number
				}
			}
		}
		infile.close();
	}
	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream ofile(m_filename);
		for (int i = 0; i < NOLP; i++) {
			if (!(m_publication[i]->getRef() == '0')) {
				ofile << m_publication[i];
			}
		}
		ofile.close();
	}
	int LibApp::search(int searchmode) {
		cout << "Searching for publication" << endl;
		PublicationSelector search("Select one of the following found matches:", 15);
		unsigned int selectype = publicationType.run(); // get the type from user
		char type;
		while (selectype == 0) {
			cout << "Aborted!";
			selectype = publicationType.run();
		}
		if (selectype == 1) {
			type = 'P';
		}
		else if (selectype == 2) {
			type = 'B';
		}
		//get the title up to 256 characters
		char title[256];
		cout << "Publication Title: ";
		cin.get(title, 256);
		// search all items
		if (searchmode == 1) {
			for (int i = 0; i < NOLP; i++) {
				if (m_publication[i]->getRef() != 0 && m_publication[i]->type() == type && m_publication[i]->operator==(title)) {
					search << m_publication[i];
				}
			}
		}
		// search items are on loan 
		else if (searchmode == 2) {
			for (int i = 0; i < NOLP; i++) {
				if (m_publication[i]->onLoan() && m_publication[i]->getRef() != 0 && m_publication[i]->type() == type && m_publication[i]->operator==(title)) {
					search << m_publication[i];
				}
			}
		}
		// items are not onloan
		else if (searchmode == 3) {
			for (int i = 0; i < NOLP; i++) {
				if (!m_publication[i]->onLoan() && m_publication[i]->getRef() != 0 && m_publication[i]->type() == type && m_publication[i]->operator==(title)) {
					search << m_publication[i];
				}
			}
		}
		// after found match, sort the result 
		if (search) {
			search.sort();
			if (search.run() == 0) {
				cout << "Aborted!" << endl;;
			}
		}
		else {
			cout << "No matches found!" << endl;;
		}
		return search.run();
	}
	
	Publication* LibApp::getPub(int libRef) {
		Publication* reference{};
		for (int i = 0; i < NOLP; i++) {
			// search object have the match referecnce
			if (m_publication[i]->getRef() == libRef) {
				reference= m_publication[i];
			}
		}
		return reference;
	}
	void LibApp::returnPub() {
		search(2);
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}
	void LibApp::newPublication() {
		Publication* ptr;
		if (NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!"<<endl;
		}
		else {
			cout << "Adding new publication to the library"<<endl;
			unsigned int selectype = publicationType.run(); // get the type from user
			char type;
			while (selectype == 0) {
				cout << "Aborted!";
				selectype = publicationType.run();
			}
			if (selectype == 1) {
				type = 'P';
				ptr = new Publication; // instantiate dynamically object 
			}
			else if (selectype == 2) {
				type = 'B';
				ptr = new Book; // instantiate dynamically object 
			}
			ptr->read(cin); // Read the instantiated object 
			if (cin.fail()) {
				while(cin.get()!='\n'){}// flush the keyboard
				cin.clear();
				cout << "Aborted!" << endl;
			}
			if(!cin.fail()) {
				// confirm user 
				if (confirm("Add this publication to the library?")) {
					LLRN++; // add one to new publication
					ptr->setRef(LLRN); //set the library reference number to the value
					m_publication[NOLP] = ptr; //Add the publication object's address to PPA
					NOLP++; 
					m_changed = true;
					cout << "Publication added" << endl;
				}
				else {
					cout << "Aborted!"<< endl;
				}
				
			}
		}
	}
	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search(int searchmode);
		if (confirm("Remove this publication from the library?")) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}
	void LibApp::checkOutPub() {
		search(int searchmode);
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
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		load();
	}
	//run method
	void LibApp::run() {
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