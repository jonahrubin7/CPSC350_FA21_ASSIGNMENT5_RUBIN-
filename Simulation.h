#include <iostream>
#include "FileProcessor.h" //import necessary packages

using namespace std;

class Simulation{
public:
  Simulation(); //constructor
  Simulation(int numWindows, GenQueue<Student>* students); //overloaded 1
  Simulation(GenQueue<Student>* line, GenQueue<Student>* students, DoublyLinkedList<Student>* helped, Registrar* registrar);//overloaded 2
  void Run(); // run method
  void GenerateStatistics(); //method for posting stats

private: //create member variables 
  MyList<Student>* m_line;
  MyList<Student>* m_students;
  DoublyLinkedList<Student>* helped;
  Registrar* m_registrar;
};
