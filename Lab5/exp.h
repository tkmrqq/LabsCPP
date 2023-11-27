#ifndef LABSCPP_EXP_H
#define LABSCPP_EXP_H

#include "cstring"
#include "iostream"

class Exp {
    int code;
    char msg[80]{};

public:
    Exp();
    Exp(int code_t, char msg_t[80]);
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
    ExpInput(int a, char *b){};
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

#endif//LABSCPP_EXP_H
