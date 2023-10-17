#include "header.h"

int check_int() {
    int value;
    while (true) {
        std::cin >> value;
        if (!std::cin.good() || value <= 0) {
            std::cout << "Invalid value, try again!" << std::endl;
            std::cin.clear();
            fflush(stdin);
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

const char* Title::getLanguage() {
    switch (lng) {
        case Language::Russian:
            return "Russian";
        case Language::English:
            return "English";
        case Language::Japanese:
            return "Japanese";
        case Language::Chinese:
            return "Chinese";
        case Language::Korean:
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
            return Language::Russian;
        case 2:
            return Language::English;
        case 3:
            return Language::Japanese;
        case 4:
            return Language::Chinese;
        case 5:
            return Language::Korean;
        default:
            std::cout << "The language is not supported! Setting English!" << std::endl;
    }
    return Language::English;
}

Movie createMovie(Movie movie){
    char title[LEN];
    Language lng;

    std::cout << "Input title: ";
    std::cin.getline(title, LEN);
    movie.setTitle(title);
    lng = askLanguage();
    movie.setLanguage(lng);
    movie.setDuration();
    movie.setRate();
    fflush(stdin);
    return movie;
}

Comic createComic(Comic comic){
    char title[LEN];
    Language lng;

    std::cout << "Input title: ";
    std::cin.getline(title, LEN);
    comic.setTitle(title);
    lng = askLanguage();
    comic.setLanguage(lng);
    comic.setPagesCount();
    comic.setReleaseCount();
    fflush(stdin);
    return comic;
}

Show createShow(Show show){
    char title[LEN];
    Language lng;

    std::cout << "Input title: ";
    std::cin.getline(title, LEN);
    show.setTitle(title);
    lng = askLanguage();
    show.setLanguage(lng);
    show.setDuration();
    show.setRate();
    show.setEpisodeCount();
    fflush(stdin);
    return show;
}

MultiSeasonShow createMultiShow(MultiSeasonShow mShow){
    char title[LEN];
    Language lng;
    std::cout << "Input title: ";
    std::cin.getline(title, LEN);
    mShow.setTitle(title);
    lng = askLanguage();
    mShow.setLanguage(lng);
    mShow.setDuration();
    mShow.setRate();
    mShow.setEpisodeCount();
    mShow.setSeasonsCount();
    fflush(stdin);
    return mShow;
}

int main() {
    Movie movie{};
    Comic comic{};
    Show show{};
    MultiSeasonShow mShow{};

    std::cout << "Create a movie object" << std::endl;
    movie = createMovie(movie);

    std::cout << "Create a comic object" << std::endl;
    comic = createComic(comic);

    std::cout << "Create a show object" << std::endl;
    show = createShow(show);

    std::cout << "Create a multi season show object" << std::endl;
    mShow = createMultiShow(mShow);

    std::cout << "[=Movie=]" << std::endl;
    movie.displayInfo();
    std::cout << "[=Comic=]" << std::endl;
    comic.displayInfo();
    std::cout << "[=Show=]" << std::endl;
    show.displayInfo();
    std::cout << "[=Multi Season Show=]" << std::endl;
    mShow.displayInfo();
    return 0;
}