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
#include <fstream>
#include <string>
#include "Text.h"
using namespace std;
namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }
    //constructor
    Text::Text(const char* filename) {
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read(); // call to read the content
        }
       
    }
    // return content according to index. not define if go out of bounds
    const char& Text::operator[](int index)const {
        
        if (index >= 0 || index < strlen(m_content)) {
            return m_content[index];
        }
        else {
            return m_content[strlen(m_content)];
        }
    }
    // copy constructor
    Text::Text(const Text& other) {
        operator=(other);
    }
    //copy assignment
    Text& Text::operator=(const Text& other) {
        if (this != &other) {
            if (other.m_content&&other.m_filename) {
                delete[] m_content;
                m_content = nullptr;
                delete[] m_filename;
                m_filename = nullptr;
                // copy content
                m_content = new char[strlen(other.m_content) + 1];
                strcpy(m_content, other.m_content);
                // copy filename
                m_filename = new char[strlen(other.m_filename) + 1];
                strcpy(m_filename, other.m_filename);
              
            }
            else {
                m_filename = nullptr;
                m_content = nullptr;
            }
        }
        return *this;
    }
    // destructor
    Text::~Text() {
        delete[] m_content;
        m_content = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
    }
    //read the content of the file and allocate memory to the file
    void Text::read() {
        if (m_filename) {
            ifstream fin(m_filename);
            //char name[10000] = {'\0'};
            if (fin.is_open()) {
                int length = getFileLength();
                char ch; int i;
                delete[] m_content;
                m_content = nullptr;
                // allocate memory for size
                m_content = new char[length + 1];
                for (i = 0; fin.get(ch); i++) {
                    m_content[i] = ch;
                }
                // set the last with null byte
                m_content[i] = '\0';
            }
            else {
                m_content = nullptr;
            }
        }

    }
    // insert content into ostream
    void Text::write(std::ostream& os)const {
        if (m_content != nullptr) {
            os << m_content;
        }
    }
    // overload for text object
    ostream& operator<<(ostream& os, const Text& text) {
        text.write(os);
        return os;
    }

}