#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& empl) {
      bool ok = false;
      char name[128];
      // if reading of employee number, salay and name are successful
      if (read(empl.m_empNo) && read(empl.m_salary) && read(name)) {
          // allocate memory to the size of the name + 1

          empl.m_name = new char[strLen(name) + 1];

          // and keep its address in the name of the Employee Reference

           //copy the name into the newly allocated memroy
          strCpy(empl.m_name, name);
          // make sure the "ok" flag is set to true
          ok = true;

          //end if
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
         
         /* Set the noOfEmployees to the number of recoreds in the file.
          dyanamically allocated an array of employees into the global
          Employee pointer; "employees" to the size of the noOfEmployees.
          */
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];

          /*In a loop load the employee records from the file into
          the dynamic array.
          */
          
          for (int j = 0; j < noOfEmployees; j++) {
                i += load(employees[j]);

          }
          /*If the number of the records does not match the number of reads
                 print the message
                "Error: incorrect number of records read; the data is possibly corrupted"
              Otherwise
                 set the ok flag to true
              End if
              */
          if (i != noOfEmployees) {
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
          }
          else {
              ok = true;
          }
          //close the file
          closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& empl) {
       cout << empl.m_empNo << ": " << empl.m_name << ", " << empl.m_salary << endl;

   }
   void display() {
       
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();
       
       for (int i = 0; i < noOfEmployees; i++) {
           cout << i + 1 << "- ";
           display(employees[i]);

       }

   }
   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       int i ;
       for (i = 0; i < noOfEmployees; i++) {
           delete[] employees[i].m_name;
       }
       delete[] employees;
       employees = nullptr;
   }
}