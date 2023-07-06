#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"


using namespace std;
namespace sdds {
    int noOfPopulation;
    Population* people;
    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPopulation - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (people[j].population > people[j + 1].population) {
                    temp = people[j];
                    people[j] = people[j + 1];
                    people[j + 1] = temp;
                }
            }
        }
    }
    bool load(Population& popul) {
        bool ok = false;
        char postal[128];
        if (read(postal) && read(popul.population)) {

            popul.postalcode = new char[strLen(postal) + 1];

            strCpy(popul.postalcode, postal);

            ok = true;
        }
        return ok;
    }
    bool load(const char Filename[]) {
        bool ok = false;
        int i = 0;
        if (openFile(Filename)) {


            noOfPopulation = noOfRecords();
            people = new Population[noOfPopulation];

          

            for (int j = 0; j < noOfPopulation; j++) {
                i += load(people[j]);

            }
            
            if (i != noOfPopulation) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << Filename << endl;
        }
        return ok;
    }
    void display(const Population& pop)
    {
        cout << pop.postalcode << ":  " << pop.population << endl;
    }
    void display() {
        int sum = 0;
        //cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "Postal Code: population" << endl;
        cout << "------------------------- " << endl;
        sort();

        for (int i = 0; i < noOfPopulation; i++) {
            cout << i + 1 << "- ";
            display(people[i]);
            sum += people[i].population;

        }
        cout << "Population of Canada : " << sum << endl;

    }

    void deallocateMemory() {
        int i;
        for (i = 0; i < noOfPopulation; i++) {
            delete[] people[i].postalcode;
        }
        delete[] people;
        people = nullptr;
    }
    



}