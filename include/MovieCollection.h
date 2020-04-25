#pragma once
#include "Movie.h"
#include "Node.h"

class MovieCollection
{
    Node *root;

public:
    MovieCollection();

    ~MovieCollection();

    void InsertMovie(Movie *movie);

    void RemoveMovie(std::string movie_title);

    void DisplayMoviesInOrder();

    void Search(Movie *movie);

    bool DoesMovieExist(std::string movie_title);

    Movie *GetMovie(std::string movie_title);
};