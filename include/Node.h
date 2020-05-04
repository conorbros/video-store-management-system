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
    Node *parent;
    Node(Movie *movie, Node *left, Node *right, Node *parent);
    std::string GetTitle();
    int GetBorrowed();
};