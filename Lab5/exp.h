#ifndef LABSCPP_EXP_H
#define LABSCPP_EXP_H

#include "cstring"
#include "iostream"

class Exp {
    int code;
    char msg[80]{};
public:
    Exp();
    Exp(int , char[]);
    void show();
};

Exp::Exp() {
    code = 0;
}

Exp::Exp(int code_t, char msg_t[80]) {
    code = code_t;
    strcpy(msg, msg_t);
}
void Exp::show() {
    std::cout << "Error: " << code << " " << msg << std::endl;
}

class ExpInput : public Exp {
public:
    ExpInput(int a, char *b) : Exp(a, b){};
};

class ExpFile : public Exp {
public:
    ExpFile() : Exp(){};
    ExpFile(int code_t, char msg_t[80]) : Exp(code_t, msg_t){};
};

class ExpCout : public Exp {
    ExpCout() : Exp(){};
    ExpCout(int code_t, char msg_t[80]) : Exp(code_t, msg_t){};
};

void CheckLength(char* str, int min, int max){
    if(strlen(str) > max || strlen(str) < min ){
        throw Exp(104, "Bad size");
    }
}

void checkChar(char* str){
    for (int i = 0; i < strlen(str); ++i) {
        if(str[i] < 'A' || str[i] > 'z') throw Exp(105,"Input only english letters.");
    }
}

void checkField(int x){
    if(x < 0) throw Exp(106, "Num must be > 0");
}

#endif//LABSCPP_EXP_H
