#include "Student.h" //import packages

Student::Student(){ //constructor
  m_timeNeed = 0;
  m_timeArrived = 0;
  m_waitTime = 0;
  m_exitTime = -1;
}

Student::Student(int timeNeed,int timeArrived){ //overloaded
  m_timeNeed = timeNeed;
  m_timeArrived = timeArrived;
  m_waitTime = 0;
  m_exitTime = -1;
}

Student::~Student(){ // destructor

}

int Student::getArrival(){  //methods for getting and setting 
  return m_timeArrived;
}

int Student::getTimeNeed(){
  return m_timeNeed;
}

void Student::setTimeNeed(int time){
  m_timeNeed = time;
}

void Student::incrementWaitTime(){
  m_waitTime++;
}

int Student::getWaitTime(){
  return m_waitTime;
}

int Student::getExitTime(){
  return m_exitTime;
}

void Student::setTimes(int currTime){
  m_exitTime = (currTime + m_timeNeed);
  m_waitTime = (currTime - m_timeArrived);
}
