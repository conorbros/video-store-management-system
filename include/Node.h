#pragma once
#include <Movie.h>

/**
 * @brief Class for representing nodes in the movie collection
 * 
 */
class Node
{
public:
    Movie *movie;
    Node *left;
    Node *right;
    Node(Movie *movie, Node *left, Node *right);
    std::string GetTitle();
    int GetBorrowed();
};