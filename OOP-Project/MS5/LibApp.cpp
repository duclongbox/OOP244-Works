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
		//Publication* p[1000]{};
		char type{};
		int i;
		for (i = 0; infile; i++) {
			infile >> type;
			infile.ignore();
			if (infile) {
				// dynamically instantiating the corresponding object into the next available PPA element
				if (type == 'P')
					m_publication[i] = new Publication;
				else if (type == 'B')
					m_publication[i] = new Book;
				if (m_publication[i]) {
					infile >> *m_publication[i]; //call the read operator
					NOLP++;
					LLRN = m_publication[i]->getRef(); // set the reference number
				}
			}
		}
		infile.close();
		//delete[] p;
	}
	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream ofile(m_filename);
		for (int i = 0; i < NOLP; i++) {
			if (!(m_publication[i]->getRef() == 0)) {
				ofile << *m_publication[i]<<endl;
			}
		}
		ofile.close();
	}
	int LibApp::search(int searchmode) {
		bool exit = false;
		PublicationSelector search("Select one of the following found matches:", 15);
		unsigned int selectype = publicationType.run(); // get the type from user
		char type;
		int select = 0;
		if (selectype == 0) {
			exit = true;
		}
		if (selectype == 1) {
			type = 'B';
		}
		else if (selectype == 2) {
			type = 'P';
		}
		if (!exit) {
			//get the title up to 256 characters
			cin.ignore(); // ignore characters
			char title[256];
			cout << "Publication Title: ";
			cin.get(title, 256,'\n');
			while (cin.get() != '\n') {
				// Discard characters until newline is encountered
			}
			// search all items make sure refernece is not delete, type match, contain the title
			if (searchmode == 1) {
				for (int i = 0; i < NOLP; i++) {
					if (m_publication[i]->getRef() != 0 && m_publication[i]->type() == type && m_publication[i]->operator==(title)) {
						search << *m_publication[i]; // call the operator receive pointer
					}
				}
			}
			// search items are on loan make sure refernece is not delete, type match, contain the title
			else if (searchmode == 2) {
				for (int i = 0; i < NOLP; i++) {
					if (m_publication[i]->onLoan() && m_publication[i]->getRef() != 0 && m_publication[i]->type() == type && m_publication[i]->operator==(title)) {
						search << *m_publication[i];
					}
				}
			}
			// items are not onloan make sure refernece is not delete, type match, contain the title
			else if (searchmode == 3) {
				for (int i = 0; i < NOLP; i++) {
					if (!(m_publication[i]->onLoan()) && m_publication[i]->getRef() != 0 && m_publication[i]->type() == type && m_publication[i]->operator==(title)) {
						search << *m_publication[i];
					}
				}
			}
			// after found match, sort the result 
			
			if (search) {
				search.sort();
				select = search.run();
				if (select <= 0) {
					cout << "Aborted!" << endl;
				}
				else {
					// print the selected publication note:getPub return the address
					cout << *getPub(select) << endl;
				}
			}
			else {
				cout << "No matches found!" << endl;
			}
		}
		else {
			cout << "Aborted!";
		}
		return select;
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
		cout << "Return publication to the library" << endl;
		int mode = search(2);
		int returnDate = 0;
		int daylate = 0;
		if (mode) {
			if (confirm("Return Publication?")) {
				returnDate = Date() - getPub(mode)->checkoutDate(); // calculate the loan day by call the operator -
				if (returnDate && returnDate > 15) { //if the loan over 15 days, calculate the penalty
					daylate = returnDate - SDDS_MAX_LOAN_DAYS;
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout<<daylate * 0.50 << " penalty for being " << daylate << " days late!" << endl;
				}
				getPub(mode)->set(0); // set the membership number of publication
				m_changed = true;
				cout << "Publication returned" << endl;
			}
		}
	
	}
	void LibApp::newPublication() {
		Publication* ptr =nullptr;
		bool exit = false;
		if (NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!";
		}
		else {
			cout << "Adding new publication to the library"<<endl;
			unsigned int selectype = publicationType.run(); // get the type from user
			if (selectype == 0) {
				exit = true;
			}
			else if (selectype == 2) {
				//type = 'P';
				ptr = new Publication; // instantiate dynamically object 
			}
			else if (selectype == 1) {
				//type = 'B';
				ptr = new Book; // instantiate dynamically object 
			}
			if (!exit) {
				cin >> *ptr;
				if (cin.fail()) {
					while (cin.get() != '\n') {}// flush the keyboard
					cin.clear();
					cout << "Aborted!" << endl;
				}
				if (!cin.fail()) {
					// confirm user 
					if (confirm("Add this publication to the library?")) {
						//if  the object is valid
						if (ptr != nullptr) {
							LLRN++; // add one to new publication
							ptr->setRef(LLRN); //set the library reference number to the value
							m_publication[NOLP] = ptr; //Add the publication object's address to PPA
							NOLP++;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else {
							cout << "Failed to add publication!" << endl;
						}
					}
					else {
						cout << "Aborted!" << endl;
					}
				}
			}
			else {
				cout << "Aborted!";
			}
		}
		cout << endl;
	}
	void LibApp::removePublication() {
		cout <<"Removing publication from the library" << endl;
		//mode : search all the publications
		int mode = search(1);
		if (mode) {
			if (confirm("Remove this publication from the library?")) {
				// set the reference number of selected publication 
				getPub(mode)->setRef(0); 
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
	}
	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library" << endl;
		// search available only
		int mode = search(3);
		int digit = 0;
		if (mode) {
			if (confirm("Check out publication?")) {
				cout << "Enter Membership number: ";
				do {
					cin >> digit;
					if (digit < 10000 || digit > 99999) {
						cout << "Invalid membership number, try again: ";
					}
				} while (digit < 10000 || digit > 99999);
				// set the membership of selected publication
				getPub(mode)->set(digit);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
		}
	}
	//constructor
	LibApp::LibApp(const char* filename) :m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), publicationType("Choose the type of publication:") {
		// set the filename
		if (filename != nullptr) {
			strCpy(m_filename, filename);
		}
		m_mainMenu << "Add New Publication"
			<< "Remove Publication"
			<< "Checkout publication from library"
			<< "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		publicationType << "Book" << "Publication";
		load();
	}
	//destructor
	LibApp::~LibApp() {
		for (int i = 0; i < NOLP; i++) {
			delete m_publication[i];
		}
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