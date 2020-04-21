#include <iostream>

enum Genre
{
    Drama,
    Adventure,
    Family,
    SciFi,
    Comedy,
    Animated,
    Thriller,
    Other
};

enum Classification
{
    General,
    ParentalGuidance,
    Mature,
    MatureAccompanied
};

class Movie
{
    std::string title;
    std::string director;
    std::string starring;
    std::string duration;
    Genre genre;
    Classification classification;

public:
    Movie(std::string, std::string, std::string, std::string, Genre, Classification);
};

Movie::Movie(std::string a, std::string b, std::string c, std::string d, Genre e, Classification f){
    title = a;
    director = b;
    starring = c;
    duration = d;
    genre = e;
    classification = f;
}