#include "variant8.cpp"

int main(){
    try {
        MultiSeasonShow ms1;
        ms1 = createMultiShow();
        ms1.displayInfo();
    }
    catch (Exp exp){
        exp.show();
    }
    return 0;
}
