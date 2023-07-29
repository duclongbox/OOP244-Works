/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #9
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 7/29/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include <iostream>
#include "Text.h"
namespace sdds {
    class HtmlText : public Text {
        char* m_title{};
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(const HtmlText& other = nullptr);
        HtmlText& operator=(const HtmlText& other);
        ~HtmlText();
        void write(std::ostream& os)const;
    };
}
#endif // !SDDS_HTMLTEXT_H__