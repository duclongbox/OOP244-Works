#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "Publication.h"

using namespace std;
namespace sdds {
	class Book : public Publication {
		char* m_authorName;
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
