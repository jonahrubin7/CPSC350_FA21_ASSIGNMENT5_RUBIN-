#include <iostream>
#include <fstream>
#include "Registrar.h"
#include "GenQueue.h" //import packages 

using namespace std;

class FileProcessor{
  public: //public
    FileProcessor(); //constructor
    ~FileProcessor();  //destructor
    GenQueue<Student>* processFile(string inputFile); //define method that processes the file
    Student* getStudents();
    int getNumWindows();

  private: //private variables
    ifstream inFS; //read in the file
    GenQueue<Student>* students;
    int numWindows;
};
