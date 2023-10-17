#include <iostream>

using namespace std;

int main(){
    char title[25];
    char title2[25];
    cin.getline(title, 25);
    cin.getline(title, 25);

    cout << "Line1 " << title << endl;
    cout << "Line2 " << title2 << endl;
}