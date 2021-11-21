
#include <iostream>
#include "Simulation.h" //needed packages

using namespace std;

int main(int argc, char **argv){ //main method
  string fileName = "";

  Simulation* simulation; //simulation instance
  FileProcessor* fp = new FileProcessor(); //file processor instance
  GenQueue<Student>* students; // queue of students
  if(argc > 1){ //command line arguments
    fileName = argv[1];
    students = fp->processFile(fileName); //call file processer on correct file
    int numWindows = fp->getNumWindows();

    simulation = new Simulation(numWindows, students); //create new simulation
    simulation->Run(); //call run method
    simulation->GenerateStatistics(); //print stats

  }else{
   cout << "INVALID USAGE: please enter name of a text file" << endl; //error handling
   cout << "USAGE: ./a.out [file name]" << endl;
  }


  return 0;
}
