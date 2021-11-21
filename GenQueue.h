#ifndef GENQUEUE_H //header guard
#define GENQUEUE_H
#include <iostream>
#include <exception> //packages
#include "LinkedList.h"
#include "MyList.h"

using namespace std;

template <class T> //template class
class GenQueue : public MyList<T>{ //inherit list class
public:
  GenQueue(); //constructor
  GenQueue(int maxSize);//overloaded constructor
  ~GenQueue(); //destructor

  //corefucntions
  void insert(T* data);
  T* remove();
  //aux functions
  T* peek();
  int getSize();
  bool isFull();
  bool isEmpty();
  DoublyLinkedList<T*> *link = new DoublyLinkedList<T*>();

private: //private variables
  int mSize;
  int rear;
  int front;
  int numElements;
};

#endif

template <class T>
GenQueue<T>::GenQueue(){ //constructor
  mSize = 128; //default mSize
  front = 0;
  rear = 0;
  numElements = 0;
}

template <class T>
GenQueue<T>::GenQueue(int maxSize){ //overloaded
  mSize = maxSize; //default mSize
  front = 0;
  rear = 0;
  numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue(){ //destructor
  delete link;
}

template <class T>
void GenQueue<T>::insert(T* data){ //create all the necessary methods for a queue
  if(isFull()){
    throw runtime_error("Queue is full");
  }
  link->insertBack(data);
  rear++;
  ++numElements;
}

template <class T>
T* GenQueue<T>::remove(){
  if(isEmpty()){
    throw runtime_error("Queue is empty");
  }
  T* c = link->removeFront();
  front++;
  --numElements;
  return c;
}

template <class T>
T* GenQueue<T>::peek(){
  if(isEmpty()){
    throw runtime_error("Queue is empty");
  }
  T* front = link->getFront();
  return front;
}

template <class T>
bool GenQueue<T>::isFull(){
  return (numElements == mSize);
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
int GenQueue<T>::getSize(){
  return numElements;
}
