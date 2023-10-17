#ifndef LAB3_MAIN_H
#define LAB3_MAIN_H

#define LEN 25
#include <cstring>
#include <iostream>

class Human{
    char gender[5]{};
    char name[LEN]{};
    char surname[LEN]{};
public:
    virtual void setName(char name_t[LEN]);
    char* getName();
    virtual void setSurname(char surname_t[LEN]);
    char* getSurname();
//    virtual void setGender();
//    char* getGender();
};

class Student : virtual public Human{
    int *marks{};
    int currentIndex = 0;
    int maxSize;
    double scholarship{};
public:
    Student(int maxMarks) : maxSize(maxMarks), currentIndex(0) {
        marks = new int[maxSize];
    }

    ~Student() {
        delete[] marks;
    }

    void setMark(int mark);
    int* getMarks();
    void setScholar();
    double getScholar();
};

class Teacher : public Human{
    double rate{}; //ставка
    double salary{}; //оклад
public:
    void setRate();
    double getRate();
    void setSalary();
    double getSalary();
};

class StudentTeacher : public Teacher, public  Student {

private:
    int articleCount{};
    double payroll{};
public:
    StudentTeacher() : Student(0) {}

    int getArticleCount() const;
    void setArticleCount();
    double getPayroll() const;
    void setPayroll();
public:

};

#endif//LAB3_MAIN_H
