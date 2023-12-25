#ifndef LAB3_HEADER_H
#define LAB3_HEADER_H

#include "exp.h"
#include <cstring>
#include <iostream>
#include "sstream"
#define LEN 25

int check_int();

enum class Language { Ru,
                      En,
                      Jp,
                      Ch,
                      Kr };

class Title {
    char title[LEN]{};
    Language lng;

public:
    Title(const char *t, Language l) {
        strncpy(title, t, LEN);
        lng = l;
    }

    const char *getTitle() const {
        return this->title;
    }
    void setTitle(char title_t[LEN]);
    void setLanguage(Language lng);
    const char *getLanguage();

    virtual void displayInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Language: " << getLanguage() << std::endl;
    }

    //    friend std::ostream& operator<<(std::ostream& os, Title& show) {
    //        os << "Title: " << show.getTitle() << std::endl;
    //        os << "Language: " << show.getLanguage() << std::endl;
    //        return os;
    //    }
};

class Movie : public Title {
    int duration{};
    int rate{};

public:
    Movie() : Title("", Language::Ru) {}
    Movie(const char *t, Language l) : Title(t, l) {}
    int getDuration();
    void setDuration(int duration_t);
    int getRate();
    void setRate(int rate_t);

    void displayInfo() override {
        Title::displayInfo();
        std::cout << "Duration: " << duration << std::endl;
        std::cout << "Rate: " << rate << std::endl;
    }

    //    friend std::ostream& operator<<(std::ostream& os, Movie show) {
    //        os << "Title: " << show.getTitle() << std::endl;
    //        os << "Language: " << show.getLanguage() << std::endl;
    //        os << "Duration: " << show.getDuration() << std::endl;
    //        os << "Rate: " << show.getRate() << std::endl;
    //        return os;
    //    }
};

class Comic : public Title {
    int releaseCount{};
    int pagesCount{};

public:
    Comic() : Title("", Language::Ru) {}
    Comic(const char *t, Language l) : Title(t, l) {}
    int getReleaseCount() const;
    void setReleaseCount(int releaseCount_t);
    int getPagesCount() const;
    void setPagesCount(int pagesCount_t);

    void displayInfo() override {
        Title::displayInfo();
        std::cout << "Release count: " << releaseCount << std::endl;
        std::cout << "Pages count: " << pagesCount << std::endl;
    }
};

class Show : public Movie {
    int episodeCount{};

public:
    Show() : Movie("", Language::Ru) {}
    Show(const char *t, Language l) : Movie(t, l) {}
    int getEpisodeCount();
    void setEpisodeCount(int episodeCount_t);

    void displayInfo() override {
        Movie::displayInfo();
        std::cout << "Episodes count: " << episodeCount << std::endl;
    }
};

class MultiSeasonShow : public Show {
    int seasonsCount{};

public:
    MultiSeasonShow() : Show("", Language::Ru) {}
    MultiSeasonShow(const char *t, Language l) : Show(t, l) {}
    int getSeasonsCount();
    void setSeasonsCount(int seasonsCount_t);

    void displayInfo() override {
        Show::displayInfo();
        std::cout << "Seasons count: " << seasonsCount << std::endl;
    }
    //to file
    friend std::fstream &operator<<(std::fstream &os, MultiSeasonShow show);
    friend std::fstream &operator>>(std::fstream &is, MultiSeasonShow &show);
    void serialize(std::ofstream& file);
    void deserialize(std::ifstream& file);
};

void MultiSeasonShow::serialize(std::ofstream& file) {
    file.write(reinterpret_cast<const char*>(&seasonsCount), sizeof(seasonsCount));
    char buffer[100];
    std::strcpy(buffer, getTitle());
    file.write(buffer, sizeof(buffer));
}

void MultiSeasonShow::deserialize(std::ifstream& file) {
    file.read(reinterpret_cast<char*>(&seasonsCount), sizeof(seasonsCount));
    char buffer[100];
    file.read(buffer, sizeof(buffer));
    setTitle(buffer);
}

Language convertLanguage(const std::string& languageStr) {
    if (languageStr == "English") {
        return Language::En;
    } else if (languageStr == "Russian") {
        return Language::Ru;
    } else if (languageStr == "Japanese") {
        return Language::Jp;
    } else if (languageStr == "Chinese"){
        return Language::Ch;
    } else if (languageStr == "Korean"){
        return Language::Kr;
    }
}

std::fstream &operator<<(std::fstream &os, MultiSeasonShow show) {
    os << show.getTitle() << ' ';
    os << show.getLanguage() << ' ';
    os << show.getDuration() << ' ';
    os << show.getRate() << ' ';
    os << show.getEpisodeCount() << ' ';
    os << show.getSeasonsCount() << '\n';
    return os;
}

std::fstream &operator>>(std::fstream &is, MultiSeasonShow &show) {
    std::string line;
    if (std::getline(is, line)) {
        std::istringstream iss(line);
        std::string title;
        std::string languageInt;
        int rate, duration, episodeCount, seasonsCount;
        if (iss >> title >> languageInt >> rate >> duration >> episodeCount >> seasonsCount) {
            auto language = convertLanguage(languageInt);
            show.setTitle(const_cast<char *>(title.c_str()));
            show.setLanguage(language);
            show.setRate(rate);
            show.setDuration(duration);
            show.setEpisodeCount(episodeCount);
            show.setSeasonsCount(seasonsCount);
        }
    }
    return is;
}

#endif//LAB3_HEADER_H
