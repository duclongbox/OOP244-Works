#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char* postalcode);
   bool read(int& number);
 
}
#endif // !SDDS_FILE_H_
