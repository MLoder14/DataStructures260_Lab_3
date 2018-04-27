#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>

class Student
{
  private:
    std::string name;
    int age;
  public:
    Student(){name = ""; age = 0;}
    Student(std::string n, int a) {name = n;age = a;}
    void setName(std::string n) {name = n;}
    std::string getName() {return name;}
    void setAge(int a) {age = a;}
    int getAge() {return age;}
};

class StudentLink
{
    public:
        StudentLink(Student * v, StudentLink * n = nullptr, StudentLink * p = nullptr) : value(v), next(n), prev(p) {}
        void setNext(StudentLink *n) {next = n;}
        StudentLink * getNext() {return next;}
        void setPrev(StudentLink *p) {prev = p;}
        StudentLink * getPrev() {return prev;}
        Student * getValue() {return value;}
    private:
        Student * value;
        StudentLink * next;
        StudentLink * prev;
};

class StudentList
{
    public:
        StudentList();
        virtual ~StudentList();
        void addHead(Student * s);
        void addTail(Student * S);
        Student * deleteHead();
        bool isEmpty();
        bool findKey(std::string name);
        bool deleteKey(std::string name);

    protected:

    private:
        StudentLink * head;
        StudentLink * tail;
};




#endif // STUDENTLIST_H
