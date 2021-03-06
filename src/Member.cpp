#include <iostream>
#include <algorithm>
#include "Member.h"

/**
 * @brief Construct a new Member:: Member object
 * 
 * @param first_name 
 * @param last_name 
 * @param address 
 * @param phone_number 
 * @param password 
 */
Member::Member(std::string first_name, std::string last_name, std::string address, std::string phone_number, int password)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->username = last_name + first_name;
    this->phone_number = phone_number;
    this->address = address;
    this->password = password;
    this->current_movie_count = 0;
}

/**
 * @brief Checks if a member's username and password match
 * 
 * @param username of the member to check
 * @param password of the member to check
 * @return true 
 * @return false 
 */
bool Member::CheckDetails(std::string username, int password)
{
    return this->username == username && this->password == password;
}

/**
 * @brief Prints the member's currently rented movies to the screen
 * 
 */
void Member::PrintCurrentMovies()
{
    std::cout << "==========Current Movies========" << std::endl;

    if (this->current_movie_count == 0)
    {
        std::cout << "You have not borrowed any movies." << std::endl
                  << std::endl;
        return;
    }

    for (int i = 0; i < this->current_movie_count; i++)
    {
        this->current_movies[i]->PrintMovie();
    }

    std::cout << std::endl;
}

/**
 * @brief Returns a movie to the library if the member is borrowing it
 * 
 * @param movie the movie to remove
 */
void Member::ReturnMovie(Movie *movie)
{
    if (!this->IsBorrowingMovie(movie))
    {
        std::cout << "You are not currently renting " + movie->title << std::endl
                  << std::endl;
        return;
    }

    this->RemoveFromCurrentMovieArray(movie);

    std::cout << "You returned " + movie->title << std::endl
              << std::endl;
}

/**
 * @brief Checks if a movie is currently borrowed by a member
 * 
 * @param movie The movie to check
 * @return true if the movie is currently borrowed by the member
 * @return false if the movie is not currently borrowed by the member
 */
bool Member::IsBorrowingMovie(Movie *movie)
{
    for (int i = 0; i < this->current_movie_count; i++)
    {
        if (this->current_movies[i] == movie)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Borrows a movie to a member's account
 * 
 * @param movie the movie to borrow
 */
void Member::BorrowMovie(Movie *movie)
{
    if (movie->copies <= 0)
    {
        std::cout << "There are currently no copies of this movie in the library. You cannot borrow it." << std::endl
                  << std::endl;
        return;
    }

    if (this->current_movie_count == 10)
    {
        std::cout << "You have already borrowed your maximum of 10 movies. You must return one before you can borrow another." << std::endl
                  << std::endl;
        return;
    }

    if (this->IsBorrowingMovie(movie))
    {
        std::cout << "You have already borrowed this movie. You cannot borrow it again." << std::endl
                  << std::endl;
        return;
    }

    this->current_movies[this->current_movie_count] = movie;
    movie->copies--;
    movie->borrowed++;
    this->current_movie_count++;

    std::cout << "You borrowed " + movie->title << std::endl
              << std::endl;
}

/**
 * @brief Borrows a movie to a member's account without printing any status updates, used to construct dummy data
 * 
 * @param movie movie to borrow
 */
void Member::AddMovieToCollection(Movie *movie)
{
    if (movie->copies <= 0 || this->current_movie_count == 10 || this->IsBorrowingMovie(movie))
    {
        return;
    }

    this->current_movies[this->current_movie_count] = movie;
    movie->copies--;
    movie->borrowed++;
    this->current_movie_count++;
}

/**
 * @brief Removes a movie from the member's current movies array
 * 
 * @param movie the movie to remove
 */
void Member::RemoveFromCurrentMovieArray(Movie *movie)
{

    // Find the index of the movie in the array
    int index;
    for (int i = 0; i < this->current_movie_count; i++)
    {
        if (this->current_movies[i] == movie)
        {
            index = i;
        }
    }

    // Push all the elements back one from the index
    for (int c = index; c < current_movie_count - 1; c++)
    {
        current_movies[c] = current_movies[c + 1];
    }

    this->current_movie_count--;
    movie->copies++;
}