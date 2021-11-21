#ifndef MYLIST_H //header guards
#define MYLIST_H

#include <iostream>  //import packages

using namespace std;

template <class T>
class MyList{ //creating a list
public:
  //core functions
  virtual void insert(T* data) = 0;
  virtual T* remove() = 0;
  virtual T* peek() = 0;
  //aux functions
  virtual bool isFull() = 0;
  virtual bool isEmpty() = 0;
  virtual int getSize() = 0;

};

#endif
