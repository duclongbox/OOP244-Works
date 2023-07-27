/*/////////////////////////////////////////////////////////////////////////
						  Milestone-4
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 7/25/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "Publication.h"

using namespace std;
namespace sdds {
	class Book : public Publication {
		char* m_authorName{nullptr};
	public:
		Book();
		Book(const Book& other);
		Book& operator=(const Book& other);
		~Book();
		void set(int member_id);
		char type()const;
		operator bool()const;
		ostream& write(ostream& os) const;
		istream& read(istream& istr);
	};
}


#endif // !BOOK_H
