#include "Registrar.h" //import packages

Registrar::Registrar(){ //constructor
  m_office = new Window[120];
  m_numWindows = 120;
}

Registrar::Registrar(int numWindows){ //overloaded
  m_office = new Window[numWindows];
  m_numWindows = numWindows;
}

Registrar::~Registrar(){ //destructor
  delete m_office;
}

int Registrar::getNumWindows(){ //get number windows method
  return m_numWindows;
}

Window* Registrar::getWindows(){ //get window from array
  return m_office;
}

bool Registrar::isOpen(){ //check if window is open method 
  for(int i = 0; i < m_numWindows; i++){
    if(!m_office[i].checkOpen()){
      return false;
    }
  }
  return true;
}
