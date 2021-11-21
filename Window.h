#include <iostream>
#include "Student.h" //import packages

using namespace std;

class Window{
public:
  Window(); //constructor
  Window(int idleTime); // overloaded
  ~Window(); //destructor
  void updateStatus(bool status);

  void setStudent(Student* s); //getters and setters
  void removeStudent();
  Student getStudent();
  Student* getStudentPointer();
  bool checkOpen();

  void updateIdleTime(); //for calculations
  bool isWindowIdle();
  int getIdleTime();

private: //member variables 
  int m_idleTime;
  bool isOpen;
  Student* currStudent;

};
