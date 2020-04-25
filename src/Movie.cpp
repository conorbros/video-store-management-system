#include <iostream>
#include "Movie.h"

Movie::Movie(std::string title, std::string director, std::string starring, std::string duration, std::string genre, std::string classification, std::string release_year, int copies)
{
    this->title = title;
    this->director = director;
    this->starring = starring;
    this->duration = duration;
    this->genre = genre;
    this->classification = classification;
    this->release_year = release_year;
    this->copies = copies;
    this->borrowed = 0;
}

Movie::Movie(std::string title, std::string director, std::string starring, std::string duration, std::string genre, std::string classification, std::string release_year, int copies, int borrowed)
{
    this->title = title;
    this->director = director;
    this->starring = starring;
    this->duration = duration;
    this->genre = genre;
    this->classification = classification;
    this->release_year = release_year;
    this->copies = copies;
    this->borrowed = borrowed;
}

void Movie::PrintMovie(){
    std:: cout << "Title: " + this->title << std::endl;
    std:: cout << "Starring: " + this->starring << std::endl;
    std:: cout << "Duration: " + this->duration + " minutes" << std::endl;
    std:: cout << "Genre: " + this->genre << std::endl;
    std:: cout << "Release Date: " + this->release_year << std::endl;
    std:: cout << "Copies Avaiable: " + std::to_string(this->copies) << std::endl;
    std:: cout << "Times Rented: " + std::to_string(this->borrowed) << std::endl;
    std:: cout << std::endl;
}