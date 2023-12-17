#include "fileProc.h"
#include <fstream>
#include <iostream>

template <typename T>
void objToFile(T& obj, const char* filename){
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << obj;
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void createObj(MultiSeasonShow& sh1, MultiSeasonShow& sh2, MultiSeasonShow& sh3){
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

int main() {
    std::string outFlName = "C:/GitHub/LabsCPP/allStack.bin";
    Stack<MultiSeasonShow> showStack;
    MultiSeasonShow sh1, sh2, sh3;
    createObj(sh1, sh2, sh3);
//    try {
//        showStack.push(sh1);
//        showStack.push(sh2);
//        showStack.push(sh3);
//    } catch (Exp &exp) {
//        exp.show();
//    }
//    std::cout << "Stack size: " << showStack.size() << std::endl;
    File fl(outFlName.c_str());
    fl.open();
//    fl.writeStack(showStack);
    fl.writeStackBin(showStack);

    try {
        showStack = fl.readStackBin<MultiSeasonShow>();
        
        showStack.peek().displayInfo();
        showStack.pop();
        showStack.peek().displayInfo();
        showStack.pop();
        showStack.peek().displayInfo();
    }
    catch (Exp exp){
        exp.show();
    }
    return 0;
}


