#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "C:/OOP244/OOP244-Works/workshop2/cstring.h"
using namespace std;
namespace sdds {
    // return the address held on m_value
    Line::operator const char* () const {
        return (const char*)m_value; 
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        delete[] m_value;
    }
   // delete allocated memory for m_filname
    void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }
    // copy the file name received to new source, with the default bool is false
    void TextFile::setFilename(const char* fname, bool isCopy) {
        if (!isCopy) {
            m_filename = new char[strlen(fname) + 1];
            strcpy(m_filename, fname);
        }
        else {
            m_filename = new char[strlen(fname) + 3];
            strcpy(m_filename, "C_");
            strcat(m_filename, fname);
        }
    }
    // set the number of line
    void TextFile::setNoOfLines() {
        m_noOfLines = 0;
        std::ifstream f(m_filename);
        char ch;
        if (f.is_open()) {
            // read te file, character by character
            while (f.get(ch)) {
                if (ch == '\n') {
                    m_noOfLines++;
                }
            }
            m_noOfLines++; // incase the lastline dont have newline character

            if (m_noOfLines == 0) {
                delete m_filename;
                m_filename = nullptr;
            }
        }

    }
    // read all the lines from text file using getline function to read input stream.
    void TextFile::loadText() {
        if (m_filename != nullptr) {
            if (m_textLines != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }
            m_textLines = new Line[m_noOfLines + 1];
            std::ifstream f(m_filename);
            std::string line;
            unsigned count = 0;
            if (f.is_open()) {
                while (std::getline(f, line)) {                   
                    m_textLines[count] = line.c_str();
                    count++;
                }
            }
            //update the number of line
            m_noOfLines = count;
        }
    }
    // save the content of the current file under new name
    void TextFile::saveAs(const char* fileName)const {
        std::ofstream out(fileName);
        unsigned i;
        for (i = 0; i < m_noOfLines; i++) {
            out << m_textLines[i] << endl;
        }

    }
    // constructor
    TextFile::TextFile(unsigned pageSize) {
        //setEmpty();
	m_filename = nullptr;
        m_noOfLines = 0;
        m_textLines = nullptr;
        m_pageSize = pageSize;

    }
    TextFile::TextFile(const char* filename, unsigned pageSize){
        //setEmpty();
	 m_filename = nullptr;
        m_noOfLines = 0;
        m_textLines = nullptr;
        m_pageSize = pageSize;
        if (filename != nullptr) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }
    // constructor coppy
    TextFile::TextFile(const TextFile& other) {
        m_filename = nullptr;
        m_noOfLines = 0;
        m_textLines = nullptr;
        m_pageSize = other.m_pageSize;
        if (other.m_filename != nullptr) {
            setFilename(other.m_filename, true);
            other.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }
    // copy assignment 
    TextFile& TextFile::operator=(const TextFile& other) {
        if (this != &other) {
            if (this->m_filename != nullptr && other.m_filename != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
                other.saveAs(m_filename);
                setNoOfLines();
                loadText();
            }
        }
        return *this;
    }
    TextFile:: ~TextFile() {
        delete[] m_textLines;
        delete m_filename;
    }
    unsigned TextFile::lines()const {
        return m_noOfLines;
    }
    // output the content of file according to pageSize
    std::ostream& TextFile::view(std::ostream& ostr)const {
        char c;
        if (m_filename != nullptr && m_textLines != nullptr && m_noOfLines != 0) {
            ostr << m_filename << endl;
            for (int i = 0; i < strlen(m_filename); i++) {
                ostr << "=";
            }
            ostr << endl;
            unsigned i = 0;
            while (i < m_noOfLines) {
                for (unsigned j = 0; j < m_pageSize && i < m_noOfLines; j++) {
                    ostr << m_textLines[i] << std::endl;
                    i++;
                }
                if (i < m_noOfLines) {
                    char ch;
                    ostr << "Hit ENTER to continue...";

                    cin.get(ch);
                    /*if (ch == '\n') {
                        while ((c = getchar()) != '\n') {};
                   }*/

                }
            }           
        }
        return ostr;
    }
    std::istream& TextFile::getFile(std::istream& istr) {
        
        std::string filename;
        istr >> filename; 
        setFilename(filename.c_str()); // convert string object to const string 
        setNoOfLines();
        loadText();
        istr.ignore();// ignore the next input 
        return istr;
        
    }
    //print the line according to the index
    const char* TextFile::operator[](unsigned index)const {
        if (m_textLines!=nullptr) {
            if (index >= m_noOfLines) {
                index = index % m_noOfLines;
            }
        }
        return m_textLines[index];
    }
    const char* TextFile::name()const {
        return m_filename;
    }
    //bool cast
    TextFile::operator bool()const{
        bool result=false;
        if (m_textLines != nullptr) {
            result = true;
        }
        return result;
    }
    ostream& operator<<(ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }
    istream& operator>>(istream& istr, TextFile& text) {
        text.getFile(istr);
        return istr;
    }

}