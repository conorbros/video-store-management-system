#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Movie.h"

/**
 * @brief Member object to represent a user's member object
 * 
 */
class Member
{
    std::string first_name;
    std::string last_name;
    std::string address;
    int password;
    int current_movie_count;
    Movie *current_movies[10];

public:
    std::string username;
    std::string phone_number;
    Member(std::string first_name, std::string last_name, std::string address, std::string phone_number, int password);
    bool CheckDetails(std::string, int);
    void PrintCurrentMovies();
    void ReturnMovie(Movie *movie);
    void BorrowMovie(Movie *movie);
    void AddMovieToCollection(Movie * movie);
    bool IsBorrowingMovie(Movie *movie);
    void RemoveFromCurrentMovieArray(Movie *movie);
};