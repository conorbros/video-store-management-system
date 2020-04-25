#include <string>
#include "MovieCollection.h"
#include "Movie.h"
#include "Node.h"

Node *MakeEmpty(Node *t)
{
    if (t == NULL)
        return NULL;
    {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        delete t;
    }
    return NULL;
}

void p(std::string s)
{
    std::cout << s << std::endl;
}

void PrintInOrder(Node *t)
{
    if (t == NULL)
        return;
    PrintInOrder(t->left);
    t->movie->PrintMovie();
    PrintInOrder(t->right);
}

Node *Insert(Movie *inserted_movie, Node *t)
{
    // If the node is null go there
    if (t == NULL)
    {
        t = new Node(inserted_movie, NULL, NULL, NULL);
    }
    // If the key is greater than the node's key go right
    else if (inserted_movie->borrowed >= t->GetBorrowed())
    {
        t->right = Insert(inserted_movie, t->right);
        t->right->parent = t;
    }
    // If the key is less than the node's key go left
    else if (inserted_movie->borrowed < t->GetBorrowed())
    {
        t->left = Insert(inserted_movie, t->left);
        t->left->parent = t;
    }
    return t;
}

Node *FindMinimum(Node *t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return FindMinimum(t->left);
}

Node *Remove(std::string removed_movie_title, Node *t)
{
    Node *temp;
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->movie->title == removed_movie_title)
    {
        temp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        delete temp;
    }
    Remove(removed_movie_title, t->left);
    Remove(removed_movie_title, t->right);
    return t;
}

Node *Remove(Movie *movie, Node *t)
{
    // The given node is
    // not found in BST
    if (t == NULL)
        return t;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (movie->borrowed < t->GetBorrowed())
        t->left = Remove(movie, t->left);

    // If the key to be deleted is greater than the t's key,
    // then it lies in right subtree
    else if (movie->borrowed > t->GetBorrowed())
        t->right = Remove(movie, t->right);

    // if key is same as t's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (t->left == NULL)
        {
            Node *temp = t->right;
            free(t);
            return temp;
        }
        else if (t->right == NULL)
        {
            Node *temp = t->left;
            free(t);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node *temp = FindMinimum(t->right);

        // Copy the inorder successor's content to this node
        t->movie = temp->movie;

        // Delete the inorder successor
        t->right = Remove(temp->movie, temp);
    }
    return t;
}

Node *Find(Node *t, std::string movie_title)
{
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->GetTitle() == movie_title)
        return t;

    Node *node = Find(t->left, movie_title);
    if (node != NULL)
    {
        return node;
    }
    node = Find(t->right, movie_title);
    return node;
}

MovieCollection::MovieCollection()
{
    this->root = NULL;
}

MovieCollection::~MovieCollection()
{
    this->root = MakeEmpty(root);
}

void MovieCollection::InsertMovie(Movie *movie)
{
    this->root = Insert(movie, root);
}

void MovieCollection::RemoveMovie(std::string movie_title)
{
    Movie *movie = GetMovie(movie_title);
    this->root = Remove(movie, this->root);
}

bool MovieCollection::DoesMovieExist(std::string movie_title)
{
    Node *node = Find(this->root, movie_title);
    if (node == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Movie *MovieCollection::GetMovie(std::string movie_title)
{
    Node *node = Find(this->root, movie_title);
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        return node->movie;
    }
}

void MovieCollection::DisplayMoviesInOrder()
{
    PrintInOrder(this->root);
}

void MovieCollection::Search(Movie *movie)
{
    this->root = Find(root, movie->title);
}