#include "Window.h" //import packages
using namespace std;

 class Registrar{
 public:
   Registrar(); //constructor
   Registrar(int numWindows); //overloaded
   ~Registrar(); //destructor

   int getNumWindows();
   Window* getWindows();

   bool isOpen();

 private: //create member variables 
   Window* m_office;
   int m_numWindows;
 };
