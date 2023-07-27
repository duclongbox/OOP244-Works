#pragma once
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
namespace sdds {
    class Text {
        char* m_filename{nullptr};
        char* m_content{nullptr};
        int getFileLength()const;
    protected:
        const char& operator[](int index)const;
    public:
        Text(const char* filename = nullptr);
        Text(const Text& other);
        Text& operator=(const Text& other);
        ~Text();

        void read();
        virtual void write(std::ostream& os)const;
    };
    std::ostream& operator<<(const std::ostream& os, const Text& text);
}
#endif // !SDDS_PERSON_H__
