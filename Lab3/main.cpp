#include "main.h"


double check_double() {
    double value;
    while (true) {
        std::cin >> value;
        if (!std::cin.good() || value <= 0) {
            std::cout << "Invalid value, try again!" << std::endl;
            std::cin.clear();
            fflush(stdin);
        } else return value;
    }
}

int check_int(){
    int value;
    while (true){
        std::cin >> value;
        if(!std::cin.good() || value <= 0){
            std::cout << "Invalid value, try again!" << std::endl;
            std::cin.clear();
            fflush(stdin);
        } else return value;
    }
}

//Human
void Human::setName(char name_t[LEN]) {
    strcpy(name, name_t);
}

char *Human::getName() {
    return this->name;
}

char *Human::getSurname() {
    return this->surname;
}

void Human::setSurname(char surname_t[LEN]) {
    strcpy(surname, surname_t);
}

//Student
void Student::setMark(int mark) {
    if(currentIndex < maxSize){
        marks[currentIndex] = mark;
        currentIndex++;
    }
    else std::cout << "No more space for marks!" << std::endl;
}

int *Student::getMarks() {
    for (int i = 0; i<maxSize; i++) {
        std::cout << marks[i] << " ";
    }
    return this->marks;
}

void Student::setScholar() {
    double scholar;
    std::cout << "Input scholarship ";
    scholar = check_double();
    scholarship = scholar;
}

double Student::getScholar() {
    return this->scholarship;
}

//Teacher
void Teacher::setRate() {
    int rate_t;
    std::cout << "Input rate ";
    rate_t = check_int();
    rate = rate_t;
}

double Teacher::getRate() {
    return this->rate;
}

void Teacher::setSalary() {
    double salary_t;
    std::cout << "Input salary ";
    salary_t = check_double();
    salary = salary_t;
}

double Teacher::getSalary() {
    return this->salary;
}

//StudentTeacher
int StudentTeacher::getArticleCount() const {
    return this->articleCount;
}
void StudentTeacher::setArticleCount() {
    int articleCount_t;
    std::cout << "Input article count ";
    std::cin >> articleCount_t;
    this->articleCount = articleCount_t;
}
double StudentTeacher::getPayroll() const {
    return this->payroll;
}

void StudentTeacher::setPayroll() {
    double payroll_t;
    std::cin >> payroll_t;
    if (std::cin.good())
        payroll = payroll_t;
}

int main() {
    StudentTeacher st;
    char name[LEN] = {"Shawty"};
    st.Teacher::setName(name);
    st.setPayroll();
    std::cout << st.Teacher::getName();
    std::cout << st.getPayroll();

    Student s1(3);
    char name2[LEN] = {"Vadik"};
    char surname[LEN] = {"Artemskiy"};

    s1.setName(name2);
    s1.setMark(1);
    s1.setMark(2);
    s1.setMark(2);
    s1.setSurname(surname);
    std::cout << "\nName: " << s1.getName() << "\nSurname: " << s1.getSurname() << "\nMarks:\n";
    s1.getMarks();
    return 0;
}
