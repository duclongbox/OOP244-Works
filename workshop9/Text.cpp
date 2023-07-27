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
    // return content according to index
    const char& Text::operator[](int index)const {
        if (index >= 0 && index < strlen(m_content)) {
            return m_content[index];
        }
    }
    // copy constructor
    Text::Text(const Text& other) {
        operator=(other);
    }
    //copy assignment
    Text& Text::operator=(const Text& other) {
        if (this != &other) {
            if (other.m_content && other.m_filename) {
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
        ifstream fin(m_filename);
        if (fin.is_open()) {
            int length = getFileLength();
            char ch; int i;
            // allocate memory for size
            m_content = new char[length + 1];
            for (i = 0; fin.get(ch); i++) {
                m_content[i] += ch;
            }
            // set the last with null byte
            m_content[i] = '\0';
        }
        else {
            m_content = nullptr;
        }
    }
    // insert content into ostream
    void Text::write(std::ostream& os)const {
        if (m_content != nullptr) {
            os << m_content;
        }
    }
    // overload for text object
    std::ostream& operator<<( std::ostream& os, const Text& text) {
        text.write(os);
        return os;
    }

}