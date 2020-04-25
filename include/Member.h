#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Movie.h"

class Member
{
    std::string first_name;
    std::string last_name;
    std::string address;
    int password;
public:
    std::string username;
    std::string phone_number;
    std::vector<Movie*> current_movies;
    Member(std::string first_name, std::string last_name, std::string address, std::string phone_number, int password);
    bool CheckDetails(std::string, int);
    void PrintCurrentMovies();
    void RemoveMovieFromCurrentMovies(Movie * movie);
    bool IsMovieBorrowedByMember(Movie * movie);
};