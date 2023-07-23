#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <iostream>
#include "Lib.h"
#include "Date.h"
#include "Streamable.h"
using namespace std;
namespace sdds {
	class Publication: public Streamable {
		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN+1];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		Publication();
		// method
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		//Queries
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;
		//pure virtual function implementation
		bool conIO(ios& io)const;
		ostream& write(ostream& os) const;
		istream& read(istream& istr);
		operator bool() const;
		// rule of three
		Publication(const Publication& other);
		Publication& operator=(const Publication& other);
		~Publication();
	};
}
#endif // !PUBLICATION_H
