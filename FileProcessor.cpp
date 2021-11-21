#include "FileProcessor.h" //import header file


FileProcessor::FileProcessor(){ //constructor
  students = new GenQueue<Student>();
}
FileProcessor::~FileProcessor(){ //destructor
  delete students;
}

GenQueue<Student>* FileProcessor::processFile(string inputFile){ //process file method
  inFS.open(inputFile);

  string input = "";
  if(!inFS.is_open()){
    cout << "Oopsies, This file could not be opened, try again with a valid file." << endl;
    exit(1);
  }

  int lineCount = 0; //create empty variables
  int currTime;
  int numStudents;
  int timeNeeded;
  while(!inFS.eof()){  //go till end of file 
    if(lineCount == 0){
      inFS >> numWindows;
      if(!inFS.fail()){
        lineCount++;
      }
    }
    inFS >> input;
    if(!inFS.fail()){
      currTime = stoi(input);
    }
    if(inFS.eof()){
      break;
    }

    inFS >> input;
    if(!inFS.fail()){
      numStudents = stoi(input);
    }
    for(int i = 0; i < numStudents; i++){
      inFS >> input;
      if(!inFS.fail()){
        timeNeeded = stoi(input);
      }
      Student* currStudent = new Student(timeNeeded,currTime);
      students->insert(currStudent);
    }
    lineCount++;
  }
  return students; //returns student
}

int FileProcessor::getNumWindows(){ //method to get number of windows
  return numWindows;
}
