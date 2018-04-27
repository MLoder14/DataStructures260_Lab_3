#include "textClass.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>

textClass::textClass()
{
    //ctor
    head = tail = iter = nullptr;
}

textClass::~textClass()
{
    //dtor
    Link * ptr = head;

    while (ptr != nullptr)
    {
        Link * temp = ptr;

        ptr = ptr->getNext();

        delete temp;
    }
}

void textClass::addHead(char val)     //insert a link contatining val at the head of the list
{
    if (head == nullptr)
        head = tail = new Link(val);

        //add a new link at the head
    else
    {
        Link * temp = new Link(val, head, nullptr);
        head->setPrev(temp);
        head = temp;
    }
}
void textClass::addTail(char val)     //insert a link containing val at the tail tof the list
{
    if (tail == nullptr)
        head = tail = new Link(val);

    else
    {
        Link * temp = new Link(val, nullptr, tail);
        tail->setNext(temp);
        tail = temp;
    }

}
char textClass::deleteHead()          //Delete first link and return its value. throw exception on an empty list. (if it is pointed to by iter, set to nullptr)
{
    if (head == nullptr)
        throw std::out_of_range("Empty List");

    Link * temp = head;
    char aLinkVal = temp->getValue();

    head = head->getNext();

        if (temp == iter)           //(if it is pointed to by iter, set to nullptr)
            temp = nullptr;         //

    if (head == nullptr)
        tail = nullptr;
    else
        head->setPrev(nullptr);

    delete temp;
    return aLinkVal;
}
char textClass::deleteTail()          //Delete last link and return its value. Throw exp on an empty list. (if it is pointed to by iter, set to nullptr)
{
    if (tail == nullptr)
        throw std::out_of_range("Empty List");

    Link * temp = tail;
    int aLinkVal = temp->getValue();

    tail = tail->getPrev();

        if (temp == iter)           //(if it is pointed to by iter, set to nullptr)
            temp = nullptr;         //

    if (tail == nullptr)
        head = nullptr;

    else
        tail->setNext(nullptr);

    delete temp;
    return aLinkVal;
}
bool textClass::isEmpty()             //return true is list is empty, otherwise false.
{
    if (head == tail)
        return true;
    else false;
}
bool textClass::findKey(char key)     //return true if a link exists containing key. if you find a link containing the key, set a class variable iter pointing to it for future use. if the key is not found in the list, return false.
{
        // walk down the list from head until reach terminator
    for(Link * ptr = head; ptr != nullptr; ptr = ptr->getNext())
    {
        if (iter == ptr)
        {
            iter = nullptr;
            continue;
        }
         //check each link for the desired value
        if ( ptr->getValue() == key )
        {     iter = ptr;
            // and return true if it is found and set a iter pointing to it.
            return true;
        }
    }
    return false;
}
bool textClass::insertKey(char value) //using the iter var. create a link containing the value and insert in the list just before the link pointed to by iter. return true if inset succeeds. if iter has not been set it should have a value of nullptr and you should return false.
                                      //if iter has been previously set, but does not point to the value being searched for, set it to nullptr and start as if this is a new search.
{
    // if iter not set, fail
    if ( iter == nullptr )
        return true;

        // special case head
    if ( iter == head )
    {
        head = new Link(value, head, nullptr);
        iter->setPrev(head);
        return true;
    }

        // otherwise do it
    Link * temp = new Link(value, iter, iter->getPrev());
    iter->getPrev()->setNext(temp);
    iter->setPrev(temp);

        // and return
    return true;
}
bool textClass::deleteIter()          //if the variable iter set by findkey is not nullptr, delete the link it points to and set iter to nullptr. return true on success, false if iter was nullptr.
{
    if (iter == nullptr)
    {
        return false;
    }
    if (iter == head)
        deleteHead();
    else if (iter == tail)
        deleteTail();
    else
    {
        iter->getNext()->setPrev(iter->getPrev());
        iter->getPrev()->setNext(iter->getNext());
        delete iter;
    }
    iter = nullptr;
    return true;
}
bool textClass::deleteKey(char key)   //Delete first link you find containing key. return true on success, false on fail. (if that link happened to be pointed to by itr, set iter to nullptr.)
{
    if(head == nullptr)
        return false;

    for(Link * ptr = head; ptr != nullptr; ptr = ptr->getNext())
    {
        if (ptr->getValue() == key)// && ptr == head)
        {
            if(ptr == head)
            {
                deleteHead();
                return true;
            }
            if (ptr == tail)
            {
                deleteTail();
                return true;
            }
        ptr->getNext()->setPrev(ptr->getPrev());
        ptr->getPrev()->setNext(ptr->getNext());
        delete ptr;
        return true;
        }
    }
    return false;
}

std::string textClass::displayList()       // return a string containing the values in the list starting at the head ending with the tail
{
    std::stringstream ss;
    for (Link * ptr = head; ptr; ptr = ptr->getNext())
    {
        ss << ptr->getValue() << " ";
    }
    ss << std::endl;
    return ss.str();
}

void textClass::appendList(textClass * list2)
{
  for (Link * ptr = list2->getHead(); ptr != nullptr; ptr = ptr->getNext())
    {
        addTail(ptr->getValue());
    }
}
