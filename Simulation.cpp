#include "Simulation.h" //include header

Simulation::Simulation(){ //constructor
  m_line = new GenQueue<Student>();
  m_students = new GenQueue<Student>();
  helped = new DoublyLinkedList<Student>();
  m_registrar = new Registrar();
}

Simulation::Simulation(int numWindows, GenQueue<Student>* students){ //overloaded
  m_line = new GenQueue<Student>();
  m_students = students;
  helped = new DoublyLinkedList<Student>();
  m_registrar = new Registrar(numWindows);
}

Simulation::Simulation(GenQueue<Student>* line, GenQueue<Student>* students, DoublyLinkedList<Student>* helped, Registrar* registrar){ //overloaded (not used)
  m_line = line;
  m_students = students;
  helped = helped;
  m_registrar = registrar;
}


void Simulation::Run(){ //run function
  Window* windows = m_registrar->getWindows();
  int clock = 0;
  while(!m_registrar->isOpen() || !m_students->isEmpty() || !m_line->isEmpty()){
    for(int i = 0; i < m_students->getSize(); i++){
      Student* student = m_students->peek();
      if(student->getArrival() <= clock){ //increment like this?
        Student* s = m_students->remove();
        m_line->insert(s);
      }
    }

    for(int i = 0; i < m_registrar->getNumWindows(); i++){
      if(windows[i].checkOpen()){
        if(!m_line->isEmpty()){
          Student* currStudent = m_line->remove();
          windows[i].updateStatus(false);
          windows[i].setStudent(currStudent);
          windows[i].getStudentPointer()->setTimes(clock);
        }else{
          windows[i].updateIdleTime();
        }
      }
      if(!windows[i].checkOpen()){
        if(windows[i].getStudent().getExitTime() ==  clock){
          helped->insertBack(windows[i].getStudent());
          windows[i].updateStatus(true);
          windows[i].removeStudent();
        }
      }
    }

    ++clock;
  }
}

void Simulation::GenerateStatistics(){ //generate the statistics from the students and windows
  int numStudents = helped->getSize();
  int bigWaitTime = 0;

  int totalStudentWaitTime = 0;
  int longestWait = 0;
  int medianWait = 0;
  int waits[numStudents];

// for students
  int index = 0;
  while(!helped->isEmpty()){
    Student currStudent = helped->removeFront();
    int currStudentWait = currStudent.getWaitTime();
    if(currStudentWait > 10){
      bigWaitTime++;
    }

    waits[index++] = currStudentWait;

    totalStudentWaitTime += currStudentWait;
    if(currStudentWait >= longestWait){
      longestWait = currStudentWait;
    }
  }
  int meanWait = totalStudentWaitTime/numStudents;

  int middle = numStudents/2;
  medianWait = waits[middle];

  cout << "The student longest wait time is: " << longestWait << endl; //print all the calculations for students
  cout << "The mean student wait time was: " << meanWait << endl;
  cout << "The number of students with wait times over 10 minutes: " << bigWaitTime << endl;
  cout << "The median student wait time: " << medianWait << endl;

  // window stats
  int totalIdle = 0;
  int longestIdle = 0;
  int meanIdle = 0;
  int bigIdle = 0;

  int numWindows = m_registrar->getNumWindows();
  Window* windows = m_registrar->getWindows();

  for(int i = 0; i < numWindows; i++){
    int currIdle = (windows[i].getIdleTime()-1);
    totalIdle += currIdle;
    if(currIdle > longestIdle){
      longestIdle = currIdle;
    }

    if(currIdle > 5){
      bigIdle++;
    }
  }

  meanIdle = totalIdle/numWindows;

  cout << endl;
  cout << "The longest window idle time: " << longestIdle << endl; //print calculations for windows 
  cout << "The mean window idle time: " << meanIdle << endl;
  cout << "Number of windows with idle times over 5 minutes: " << bigIdle << endl;
}
