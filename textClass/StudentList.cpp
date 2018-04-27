#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "StudentList.h"

using namespace std;

StudentList::StudentList()
{
  head = tail = nullptr;
}

StudentList::~StudentList()
{
    StudentLink * ptr = head;

        while (ptr != nullptr)
        {
            StudentLink * temp = ptr;
            ptr = ptr->getNext();
            delete temp;
        }
}

void StudentList::addHead(Student * s)
{
  if ( head == nullptr )
    head = tail = new StudentLink(s);
  else
    head = new StudentLink(s, head);
}

void StudentList::addTail(Student * s)
{
  if (tail == nullptr)
    head = tail = new StudentLink(s);
  else {
    StudentLink * temp = new StudentLink(s);
    tail->setNext(temp);
    tail = temp;
  }
}

Student * StudentList::deleteHead()
{
  if (head == nullptr)
    throw std::underflow_error("Empty List");

  StudentLink * temp = head;
  Student * value = temp->getValue();
  head = head->getNext();
  delete temp;

  if (head == nullptr)
    tail = nullptr;

  return value;
}

bool StudentList::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

bool StudentList::findKey(string name)
{
    for (StudentLink * ptr = head; ptr != nullptr; ptr = ptr->getNext())
        if (ptr->getValue()->getName() == name)
        {
            return true;
        }
    return false;
}

bool StudentList::deleteKey(string name)
{
  if (head == nullptr)
    return false;
  if (head->getValue()->getName() == name)
    {
        deleteHead();
        return true;
    }
  StudentLink * prevPtr = head;
  while (prevPtr->getNext() != nullptr)
  {
    StudentLink * next = prevPtr->getNext();
    if (next->getValue()->getName() == name)
        {
            prevPtr->setNext(next->getNext());

            if (tail == next)
            tail = prevPtr;

            delete next;
            return true;
        }
        prevPtr = prevPtr->getNext();
  }
  return false;
}
