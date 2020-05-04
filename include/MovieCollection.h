#pragma once
#include "Movie.h"
#include "Node.h"

/**
 * @brief Object to store movie's of the video store
 * 
 */
class MovieCollection
{
    Node *root;
    int movie_count;

public:
    MovieCollection();

    ~MovieCollection();

    void InsertMovie(Movie *movie);

    void RemoveMovie(std::string movie_title);

    void DisplayMoviesInOrder();

    void DisplayTopTenBorrowedMovies();

    void Search(Movie *movie);

    bool DoesMovieExist(std::string movie_title);

    Movie *GetMovie(std::string movie_title);

};