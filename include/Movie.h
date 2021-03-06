#pragma once

#include <iostream>

/**
 * @brief Movie object to represent the video store's movie 
 * 
 */
class Movie
{
    std::string director;
    std::string starring;
    std::string duration;
    std::string genre;
    std::string classification;
    std::string release_year;

public:
    std::string title;
    int borrowed;
    int copies;
    void PrintMovie();
    Movie(std::string title, std::string director, std::string starring, std::string duration, std::string genre, std::string classification, std::string release_year, int copies);
    Movie(std::string title, std::string director, std::string starring, std::string duration, std::string genre, std::string classification, std::string release_year, int copies, int borrowed);
    std::string TitleStripPrefix();
};