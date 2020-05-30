#include <Node.h>
#include <Movie.h>

/**
 * @brief Construct a new Node:: Node object
 * 
 * @param movie 
 * @param left 
 * @param right 
 */
Node::Node(Movie *movie, Node *left, Node *right)
{
    this->movie = movie;
    this->left = left;
    this->right = right;
}

/**
 * @brief Gets the title of the node's movie
 * 
 * @return std::string 
 */
std::string Node::GetTitle(){
    return this->movie->title;
}

/**
 * @brief Gets the borrowed count of the node's movie
 * 
 * @return int 
 */
int Node::GetBorrowed()
{
    return this->movie->borrowed;
}