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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HtmlText.h"
using namespace std;
namespace sdds {
    // constructor 
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
        if (title) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }
    // copy constructor
    HtmlText::HtmlText(const HtmlText& other) :Text(other) {
        if (other.m_title!=nullptr) {
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        }
        else {
            m_title = nullptr;
        }
    }
    // copy assignment
    HtmlText& HtmlText::operator=(const HtmlText& other) {
        if (this != &other) {
            (Text&)*this = other; // call base class assignment
            delete[] m_title;
            if (other.m_title != nullptr) {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
            else {
                m_title = nullptr;
            }
        }
        return *this;
    }
    // destructor
    HtmlText::~HtmlText() {
        delete[] m_title;
    }
    // override function
    void HtmlText::write(std::ostream& os)const {
        bool MS = false;
        os << "<html><head><title>";
        if (m_title != nullptr) {
            os << m_title;
        }
        else {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";
        if (m_title != nullptr) {
            os << "<h1>" << m_title << "</h1>\n";

            for (int i = 0; this->operator[](i) != '\0'; i++) {
                if (this->operator[](i) == ' ') {
                    if (MS) {
                        os << "&nbsp;";
                    }
                    else {
                        MS = true;
                        os << ' ';
                    }
                }
                else if (this->operator[](i) == '<') {
                    os << "&lt;";
                    MS = false;
                }
                else if (this->operator[](i) == '>') {
                    os << "&gt;";
                    MS = false;
                }
                else if (this->operator[](i) == '\n') {
                    os << "<br />\n";
                    MS = false;
                }
                else {
                    MS = false;
                    os << this->operator[](i);
                }
            }
        }
        os << "</body>\n</html>";
         
    }

}
