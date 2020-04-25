#include <iostream>
#include <algorithm>
#include "Member.h"

Member::Member(std::string first_name, std::string last_name, std::string address, std::string phone_number, int password)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->username = last_name + first_name;
    this->phone_number = phone_number;
    this->address = address;
    this->password = password;
}

bool Member::CheckDetails(std::string username, int password)
{
    return this->username == username && this->password == password;
}

void Member::PrintCurrentMovies(){
    std::cout << "==========Current Movies========" << std::endl;

    for(Movie * movie : this->current_movies)
    {
        movie->PrintMovie();
    }

    std::cout << std::endl;
}

void Member::RemoveMovieFromCurrentMovies(Movie * movie)
{
     this->current_movies.erase(std::remove(this->current_movies.begin(), this->current_movies.end(), movie), this->current_movies.end());
}

bool Member::IsMovieBorrowedByMember(Movie * movie)
{
    std::vector<Movie*>::iterator it = std::find(this->current_movies.begin(), this->current_movies.end(), movie);
    return it != this->current_movies.end();
}