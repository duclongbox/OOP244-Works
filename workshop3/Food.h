/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca..ca
Section    : ZAA
Date	   : 6/1/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_foodName[31];
        int m_calorie;
        int m_timeConsumption;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calorie, int time);
        void display()const;
        bool isValid()const;
        int calorie()const;
        /*double tax()const;*/
    };
}

#endif // !SDDS_SUBJECT_H