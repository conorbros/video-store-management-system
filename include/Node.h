#pragma once
#include <Movie.h>

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