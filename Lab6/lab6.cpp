#include "fileProc.h"
#include <fstream>
#include <iostream>

template<typename T>
void objToFile(T &obj, const char *filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << obj;
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void createObj(MultiSeasonShow &sh1, MultiSeasonShow &sh2, MultiSeasonShow &sh3) {
    sh1.setTitle("KNY");
    sh1.setLanguage(Language::Jp);
    sh1.setRate(9);
    sh1.setSeasonsCount(3);
    sh1.setEpisodeCount(12);
    sh1.setDuration(24);

    sh2.setTitle("RickAndMorty");
    sh2.setLanguage(Language::Ru);
    sh2.setRate(8);
    sh2.setSeasonsCount(7);
    sh2.setEpisodeCount(12);
    sh2.setDuration(20);

    sh3.setTitle("BlindyPeakers");
    sh3.setLanguage(Language::En);
    sh3.setRate(7);
    sh3.setSeasonsCount(6);
    sh3.setEpisodeCount(10);
    sh3.setDuration(120);
}

void writeTxt() {
    std::string outFlName = "C:/GitHub/LabsCPP/allStack.txt";
    Stack<MultiSeasonShow> showStack;
    MultiSeasonShow sh1, sh2, sh3;

    try {
        File fl(outFlName.c_str());
        createObj(sh1, sh2, sh3);
        fl.open();
        showStack.push(sh1);
        showStack.push(sh2);
        showStack.push(sh3);
        std::cout << "Stack size: " << showStack.size() << std::endl;
        fl.writeStack(showStack);
    } catch (Exp &exp) {
        exp.show();
    }
}

void writeBin() {
    std::string outFlName = "C:/GitHub/LabsCPP/allStack.bin";
    Stack<MultiSeasonShow> showStack;
    MultiSeasonShow sh1, sh2, sh3;

    try {
        File fl(outFlName.c_str());
        createObj(sh1, sh2, sh3);
        fl.open();
        showStack.push(sh1);
        showStack.push(sh2);
        showStack.push(sh3);
        std::cout << "Stack size: " << showStack.size() << std::endl;
        fl.writeStackBin(showStack);
    } catch (Exp &exp) {
        exp.show();
    }
}

void readTxt() {
    try {
        char outFlName[80] = "C:/GitHub/LabsCPP/allStack.txt";
        File fl(outFlName);
        fl.openForRead();
        Stack<MultiSeasonShow> showStack;
        fl.readStack(showStack);
        //print stack
        showStack.peek().displayInfo();
        showStack.pop();
        showStack.peek().displayInfo();
        showStack.pop();
        showStack.peek().displayInfo();
    } catch (Exp &exp) {
        exp.show();
    }
}

void readBin() {
    try {
        char outFlName[80] = "C:/GitHub/LabsCPP/allStack.bin";
        File fl(outFlName);
        fl.openForRead();
        Stack<MultiSeasonShow> showStack;
        showStack = fl.readStackBin<MultiSeasonShow>();
        //print stack
        showStack.peek().displayInfo();
        showStack.pop();
        showStack.peek().displayInfo();
        showStack.pop();
        showStack.peek().displayInfo();
    } catch (Exp &exp) {
        exp.show();
    }
}


int main() {
    //writeTxt();
    //writeBin();
    //readTxt();
    readBin();
    return 0;
}
