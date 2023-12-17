#include "variant8.cpp"
#include "inheritance.h"

int main() {
    Movie movie{"movie", Language::En};
    Comic comic{"comic", Language::Ch};
    Show show{"show", Language::Jp};
    MultiSeasonShow mShow{"mShow", Language::Kr};
    while (true) {
        try {
            int choice;

            std::cout << "1. Input object\n2. Print object\n3. Exit" << std::endl;
            choice = check_int();

            std::cout << "Choice: " << choice << std::endl;
            switch (choice) {
                case 1:
                    inputObj(movie, comic, show, mShow);
                    break;
                case 2:
                    printObj(movie, comic, show, mShow);
                    break;
                case 3:
                    return EXIT_SUCCESS;
                default:
                    std::cout << "Invalid input!" << std::endl;
                    break;
            }
        } catch (Exp error) {
            error.show();
        }
    }
}
