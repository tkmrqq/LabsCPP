#include "inheritance.h"

int check_int() {
    int value;
    while (true) {
        std::cin >> value;
        if (!std::cin.good() || value <= 0) {
            std::cin.clear();
            fflush(stdin);
            throw Exp(105, "Invalid input."); //mb should change to cout
        } else
            return value;
    }
}

void Title::setTitle(char title_t[LEN]) {
    strcpy(title, title_t);
}

void Title::setLanguage(Language language) {
    this->lng = language;
}

const char *Title::getLanguage() {
    switch (lng) {
        case Language::Ru:
            return "Russian";
        case Language::En:
            return "English";
        case Language::Jp:
            return "Japanese";
        case Language::Ch:
            return "Chinese";
        case Language::Kr:
            return "Korean";
    }
}

int Movie::getDuration() {
    return this->duration;
}

void Movie::setDuration() {
    int duration_t;
    std::cout << "Input a duration: ";
    duration_t = check_int();
    this->duration = duration_t;
}

int Movie::getRate() {
    return this->rate;
}

void Movie::setRate() {
    int rate_t;
    std::cout << "Input rate of movie: ";
    rate_t = check_int();
    this->rate = rate_t;
}

int Comic::getReleaseCount() const {
    return this->releaseCount;
}
void Comic::setReleaseCount() {
    int releaseCount_t;
    std::cout << "Input count of releases: ";
    releaseCount_t = check_int();
    this->releaseCount = releaseCount_t;
}
int Comic::getPagesCount() const {
    return this->pagesCount;
}
void Comic::setPagesCount() {
    int pagesCount_t;
    std::cout << "Input count of pages: ";
    pagesCount_t = check_int();
    this->pagesCount = pagesCount_t;
}

int Show::getEpisodeCount() {
    return this->episodeCount;
}

void Show::setEpisodeCount() {
    int episodeCount_t;
    std::cout << "Input count of episodes: ";
    episodeCount_t = check_int();
    this->episodeCount = episodeCount_t;
}

void MultiSeasonShow::setSeasonsCount() {
    int seasonsCount_t;
    std::cout << "Input count of seasons: ";
    seasonsCount_t = check_int();
    this->seasonsCount = seasonsCount_t;
}

int MultiSeasonShow::getSeasonsCount() {
    return this->seasonsCount;
}

Language askLanguage() {
    std::cout << "Pick a language: 1)Russian 2)English 3)Japanese 4)Chinese 5)Korean" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            return Language::Ru;
        case 2:
            return Language::En;
        case 3:
            return Language::Jp;
        case 4:
            return Language::Ch;
        case 5:
            return Language::Kr;
        default:
            std::cout << "The language is not supported! Setting En!" << std::endl;
    }
    return Language::En;
}

Movie createMovie(Movie movie) {
    char title[LEN];
    Language lng;

    std::cout << "Input title: ";
    std::cin.getline(title, LEN) >> title;
    movie.setTitle(title);
    lng = askLanguage();
    movie.setLanguage(lng);
    movie.setDuration();
    movie.setRate();
    fflush(stdin);
    return movie;
}

Comic createComic(Comic comic) {
    char title[LEN];
    Language lng;

    std::cout << "Input title: ";
    std::cin.getline(title, LEN) >> title;
    comic.setTitle(title);
    lng = askLanguage();
    comic.setLanguage(lng);
    comic.setPagesCount();
    comic.setReleaseCount();
    fflush(stdin);
    return comic;
}

Show createShow(Show show) {
    char title[LEN];
    Language lng;

    std::cout << "Input title: ";
    std::cin.getline(title, LEN) >> title;
    show.setTitle(title);
    lng = askLanguage();
    show.setLanguage(lng);
    show.setDuration();
    show.setRate();
    show.setEpisodeCount();
    fflush(stdin);
    return show;
}

MultiSeasonShow createMultiShow() {
    char title[LEN];
    Language lng;
    std::cout << "Input title: ";
    std::cin.getline(title, LEN) >> title;
    lng = askLanguage();
    MultiSeasonShow mShow{title, lng};
    mShow.setDuration();
    mShow.setRate();
    mShow.setEpisodeCount();
    mShow.setSeasonsCount();
    fflush(stdin);
    return mShow;
}

void inputObj(Movie &movie, Comic &comic, Show &show, MultiSeasonShow &mShow) {

    std::cout << "1. Movie\n2. Comic\n3. Show\n4. Multi season show" << std::endl;
    int choice;
    choice = check_int();
    switch (choice) {
        case 1:
            std::cout << "Create a movie object" << std::endl;
            movie = createMovie(movie);
            break;
        case 2:
            std::cout << "Create a comic object" << std::endl;
            comic = createComic(comic);
            break;
        case 3:
            std::cout << "Create a show object" << std::endl;
            show = createShow(show);
            break;
        case 4:
            std::cout << "Create a multi season show object" << std::endl;
            mShow = createMultiShow();
            break;
        default:
            throw Exp(105, "Invalid input");
            break;
    }
}

void printObj(Movie movie, Comic comic, Show show, MultiSeasonShow mShow) {
    int choice;
    std::cout << "What object you want to print?" << std::endl;
    std::cout << "1. Movie\n2. Comic\n3. Show\n4. Multi season show" << std::endl;

    choice = check_int();
    switch (choice) {
        case 1:
            std::cout << "[=Movie=]" << std::endl;
            movie.displayInfo();
            break;
        case 2:
            std::cout << "[=Comic=]" << std::endl;
            comic.displayInfo();
            break;
        case 3:
            std::cout << "[=Show=]" << std::endl;
            show.displayInfo();
            break;
        case 4:
            std::cout << "[=Multi Season Show=]" << std::endl;
            mShow.displayInfo();
            break;
        default:
            std::cout << "Invalid input (in print obj)" << std::endl;
            break;
    }
}

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