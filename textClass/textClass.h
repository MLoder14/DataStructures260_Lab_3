#ifndef TEXTCLASS_H
#define TEXTCLASS_H
#include <string>

class Link
{
    private:
        char linkVal;
        Link * next;
        Link * prev;
    public:
        Link(char v, Link *n = nullptr, Link *p = nullptr) : linkVal(v), next(n), prev(p) {}

        void setNext(Link *n) {next = n;}
        Link * getNext() {return next;}
        void setPrev(Link *p) {prev = p;}
        Link * getPrev() {return prev;}
        char getValue() {return linkVal;}
};

class textClass
{
    public:
        textClass();
        virtual ~textClass();
        void addHead(char val);     //insert a link contatining val at the head of the list

        void addTail(char val);     //insert a link containing val at the tail tof the list

        char deleteHead();          //Delete first link and return its value. throw exception on an empty list. (if it is pointed to by iter, set to nullptr)

        char deleteTail();          //Delete last link and return its value. Throw exp on an empty list. (if it is pointed to by iter, set to nullptr)

        bool isEmpty();             //return true is list is empty, otherwise false.

        bool findKey(char key);     //return true if a link exists containing key. if you find a link containing the key, set a class variable iter pointing to it for future use. if the key is not found in the list, return false.

        bool insertKey(char value); //using the iter var. create a link containing the value and insert in the list just before the link pointed to by iter. return true if inset succeeds. if iter has not been set it should have a value of nullptr and you should return false.
                                    //if iter has been previously set, but does not point to the value being searched for, set it to nullptr and start as if this is a new search.

        bool deleteIter();          //if the variable iter set by findkey is not nullptr, delete the link it points to and set iter to nullptr. return true on success, false if iter was nullptr.

        bool deleteKey(char key);           //Delete first link you find containing key. return true on success, false on fail. (if that link happened to be pointed to by itr, set iter to nullptr.)

        std::string displayList();       // return a string containing the values in the list starting at the head ending with the tail.

        void appendList(textClass * list2);
            Link * getHead() { return head; }
    protected:

    private:
        Link * head; // pointer to the start of the list
        Link * tail; // pointer to the end of the list
        Link * iter; // pointer to a recently found item
};

#endif // TEXTCLASS_H
