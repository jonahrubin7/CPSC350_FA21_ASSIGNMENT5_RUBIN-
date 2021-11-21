#include "Window.h" //import packages

Window::Window(){ //constructor
  m_idleTime = 0;
  isOpen = true;
  currStudent = NULL;
}

Window::Window(int idleTime){ //overloaded
  m_idleTime = idleTime;
  isOpen = true;
  currStudent = NULL;
}

Window::~Window(){ //default
  delete currStudent;
}

void Window::updateStatus(bool status){ //method for changing status
  isOpen = status;
}

void Window::setStudent(Student* s){ //getters and setters
  currStudent = s;
}

void Window::removeStudent(){
  currStudent = NULL;
}

Student Window::getStudent(){
  return *currStudent;
}

Student* Window::getStudentPointer(){ //cause shit wasnt working
  return currStudent;
}

bool Window::checkOpen(){
  return isOpen;
}

void Window::updateIdleTime(){ //for calculations
  m_idleTime++;
}

bool Window::isWindowIdle(){
  return (!isOpen);
}

int Window::getIdleTime(){
  return m_idleTime;
}
