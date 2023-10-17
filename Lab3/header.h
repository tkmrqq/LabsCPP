#ifndef LAB3_HEADER_H
#define LAB3_HEADER_H

#include <cstring>
#include <iostream>
#define LEN 25

int check_int();

enum class Language {Russian, English, Japanese, Chinese, Korean};

class Title{
    char title[LEN];
    Language lng;
public:
    const char *getTitle() const {
        return title;
    }
    void setTitle(char title_t[LEN]);
    void setLanguage(Language lng);
    const char* getLanguage();

    virtual void displayInfo(){
        std::cout << "Title: " << title << std::endl;
        std::cout << "Language: " << getLanguage() << std::endl;
    }

};

class Movie : public Title{
    int duration{};
    int rate{};
public:
    int getDuration();
    void setDuration();
    int getRate();
    void setRate();

    void displayInfo() override{
        Title::displayInfo();
        std::cout << "Duration: " << duration << std::endl;
        std::cout << "Rate: " << rate << std::endl;
    }

};

class Comic : public Title{
    int releaseCount{};
    int pagesCount{};
public:
    int getReleaseCount() const;
    void setReleaseCount();
    int getPagesCount() const;
    void setPagesCount();

    void displayInfo() override{
        Title::displayInfo();
        std::cout << "Release count: " << releaseCount << std::endl;
        std::cout << "Pages count: " << pagesCount << std::endl;
    }

};

class Show : public Movie{
    int episodeCount{};
public:
    int getEpisodeCount();
    void setEpisodeCount();

    void displayInfo() override{
        Movie::displayInfo();
        std::cout << "Episodes count: " << episodeCount << std::endl;
    }

};

class MultiSeasonShow : public Show{
    int seasonsCount{};
public:
    int getSeasonsCount();
    void setSeasonsCount();

    void displayInfo() override {
        Show::displayInfo();
        std::cout << "Seasons count: " << seasonsCount << std::endl;
    }
};

#endif//LAB3_HEADER_H
