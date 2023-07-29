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
#pragma once
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
    class Text {
        char* m_filename{};
        char* m_content{};
        int getFileLength()const;
    protected:
        const char& operator[](int index)const;
    public:
        Text(const char* filename = nullptr);
        Text(const Text& other);
        Text& operator=(const Text& other);
        virtual ~Text();
        void read();
        virtual void write(std::ostream& os)const;
    };
    std::ostream& operator<<( std::ostream& os, const Text& text);
}
#endif // !SDDS_PERSON_H__
