
using namespace std;

class Student{
public:
  Student(); //constructor
  Student(int timeNeed,int timeArrived); //overloaded
  ~Student(); //destructor
  int getArrival(); //getters and setters
  int getTimeNeed();
  void setTimeNeed(int time);
  void incrementWaitTime(); //method for adding to the run time
  int getWaitTime();
  int getExitTime();
  void setTimes(int currTime);

  int m_timeNeed; //member variables
  int m_timeArrived;
  int m_waitTime;
  int m_exitTime;
};
