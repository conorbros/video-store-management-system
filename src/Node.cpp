#include <Node.h>
#include <Movie.h>

Node::Node(Movie *movie, Node *left, Node *right, Node *parent)
{
    this->movie = movie;
    this->left = left;
    this->right = right;
    this->parent = parent;
}

std::string Node::GetTitle(){
    return this->movie->title;
}

int Node::GetBorrowed()
{
    return this->movie->borrowed;
}