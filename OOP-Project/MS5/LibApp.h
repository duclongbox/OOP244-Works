#include <iostream>
#include "Lib.h"
#include "Publication.h"
#include "Book.h"
#include "Streamable.h"
#include "Menu.h"
#include "PublicationSelector.h"
#include "Utils.h"
namespace sdds {
	class LibApp {
		char m_filename[256];
		Publication* m_publication[SDDS_LIBRARY_CAPACITY]; // store all records of publication 
        int NOLP{0}; // number of publication loaded
		int LLRN; // library reference number
        Menu publicationType; //selection of publication type
        Menu m_mainMenu;  // main menu application
        Menu m_exitMenu;// exit the program if any change
        bool confirm(const char* message); 
        bool m_changed{ false };
        void load();  // prints: "Loading Data"<NEWLINE>
        void save();  // prints: "Saving Data"<NEWLINE>
        int search(int searchmode);  // prints: "Searching for publication"<NEWLINE>
        Publication* getPub(int libRef); // return the address of a object in PPA matching with the argument
        
        void returnPub();  /*  Calls the search() method.
                               prints "Returning publication"<NEWLINE>
                               prints "Publication returned"<NEWLINE>
                               sets m_changed to true;
                           */
        void newPublication();
        void removePublication();
        void checkOutPub();
    public:
        LibApp(const char* filename);
        ~LibApp();
        void run();
	};
 }