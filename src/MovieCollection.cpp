#include <string>
#include <iostream>
#include <stdint.h>
#include <cmath>
#include "MovieCollection.h"
#include "Movie.h"
#include "Node.h"

/**
 * @brief Deletes every node in the tree
 * 
 * @param t the root node
 * @return Node* 
 */
Node *MakeEmpty(Node *t)
{
    if (t == NULL)
    {
        return NULL;
    }

    MakeEmpty(t->left);
    MakeEmpty(t->right);
    delete t;
    return NULL;
}

/**
 * @brief Traverses the movie collection in order and copies it to an array
 * 
 * @param t the root node
 * @param movies the array to copy to
 * @param i the current index
 */
void InOrderTraversalToArray(Node *t, Movie *movies[], int *i)
{
    if (t == NULL)
    {
        return;
    }

    InOrderTraversalToArray(t->left, movies, i);
    movies[*i] = t->movie;
    ++*i;
    InOrderTraversalToArray(t->right, movies, i);
}

/**
 * @brief Prints the movies to output in order
 * 
 * @param t root node
 */
void PrintInOrder(Node *t)
{
    if (t == NULL)
    {
        return;
    }

    PrintInOrder(t->left);
    t->movie->PrintMovie();
    PrintInOrder(t->right);
}

/**
 * @brief Inserts the supplied movie into the movie collection
 * 
 * @param inserted_movie The movie to insert
 * @param t The root node
 * @return Node* Pointer to the trailing node of the new node
 */
Node *Insert(Movie *inserted_movie, Node *t)
{
    Node *new_node = new Node(inserted_movie, NULL, NULL, NULL);
    Node *trav_node = t;
    Node *trailing_node = NULL;

    while (trav_node != NULL)
    {
        trailing_node = trav_node;
        if (inserted_movie->TitleStripPrefix() < trav_node->movie->TitleStripPrefix())
            trav_node = trav_node->left;
        else
            trav_node = trav_node->right;
    }

    if (trailing_node == NULL)
    {
        trailing_node = new_node;
    }
    else if (inserted_movie->TitleStripPrefix() < trailing_node->movie->TitleStripPrefix())
    {
        trailing_node->left = new_node;
    }
    else
    {
        trailing_node->right = new_node;
    }
    return trailing_node;
}

/**
 * @brief Finds the minimum node (alphabetically) in the movie collection
 * 
 * @param t The root node
 * @return Node* Pointer to the minimum node
 */
Node *FindMinimum(Node *t)
{
    if (t == NULL)
    {
        return NULL;
    }

    if (t->left == NULL)
    {
        return t;
    }

    return FindMinimum(t->left);
}

Node *FindMaximum(Node *t)
{
    if (t == NULL)
    {
        return NULL;
    }

    if (t->right == NULL)
    {
        return t;
    }

    return FindMaximum(t->right);
}

/**
 * @brief Removes a movie from the movie collection 
 * 
 * @param movie movie to remove
 * @param t root node
 * @return Node* pointer to root node
 */
Node *Remove(Movie *movie, Node *t)
{
    if (t == NULL)
    {
        return t;
    }

    if (movie->TitleStripPrefix() < t->movie->TitleStripPrefix())
    {
        t->left = Remove(movie, t->left);
    }
    else if (movie->TitleStripPrefix() > t->movie->TitleStripPrefix())
    {
        t->right = Remove(movie, t->right);
    }
    else
    {
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
        Node *temp = FindMinimum(t->right);
        t->movie = temp->movie;
        t->right = Remove(temp->movie, temp);
    }
    return t;
}

/**
 * @brief Finds a movie in the 
 * 
 * @param t 
 * @param movie_title 
 * @return Node* 
 */
Node *Find(Node *t, std::string movie_title)
{
    if (t == NULL || t->GetTitle() == movie_title)
    {
        return t;
    }

    if (movie_title > t->GetTitle())
    {
        return Find(t->right, movie_title);
    }

    return Find(t->left, movie_title);
}

MovieCollection::MovieCollection()
{
    this->root = NULL;
    this->movie_count = 0;
}

MovieCollection::~MovieCollection()
{
    this->root = MakeEmpty(root);
}

void MovieCollection::InsertMovie(Movie *movie)
{
    this->movie_count += 1;

    if (this->root == NULL)
    {
        this->root = Insert(movie, this->root);
    }
    else
    {
        Insert(movie, this->root);
    }
}

void MovieCollection::RemoveMovie(std::string movie_title)
{
    Movie *movie = GetMovie(movie_title);
    if (movie != NULL)
    {
        this->movie_count -= 1;
        this->root = Remove(movie, this->root);
    }
}

bool MovieCollection::DoesMovieExist(std::string movie_title)
{
    Node *node = Find(this->root, movie_title);
    if (node == NULL)
    {
        return false;
    }

    return true;
}

Movie *MovieCollection::GetMovie(std::string movie_title)
{
    Node *node = Find(this->root, movie_title);
    if (node == NULL)
    {
        return NULL;
    }

    return node->movie;
}

void MovieCollection::DisplayMoviesInOrder()
{
    PrintInOrder(this->root);
}

void MovieCollection::Search(Movie *movie)
{
    this->root = Find(root, movie->title);
}

void print(std::string str)
{
    std::cout << str << std::endl;
}

/**
 * @brief Gets the index to insert the new movie at
 * 
 * @param a array of movies currently in the top 10
 * @param item new movie to insert
 * @param count current of the movie array
 * @return int index to insert at
 */
int GetIndex(Movie *a[], Movie *item, int count)
{
    int ans = -1;
    int l = 0;
    int r = count - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m]->borrowed == item->borrowed)
        {
            return m;
        }
        else if (a[m]->borrowed < item->borrowed)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans + 1;
}

void AddToArray(Movie *movies[], int *count, Movie *movie)
{
    if (*count == 0)
    {
        movies[0] = movie;
        return;
    }

    int location = GetIndex(movies, movie, *count);

    if (*count < 10)
    {
        for (int i = *count; i > location; i--)
        {
            movies[i] = movies[i - 1];
        }
    }
    else
    {
        for (int i = 0; i < location; i++)
            movies[i] = movies[i + 1];

        location = location - 1;
    }

    movies[location] = movie;
}

int *GetTopTen(Movie *movies[], int *count, Node *t)
{

    if (t == NULL)
    {
        return count;
    }
    count = GetTopTen(movies, count, t->left);

    if (*count < 10)
    {
        AddToArray(movies, count, t->movie);
        (*count)++;
    }
    else if (t->GetBorrowed() > movies[0]->borrowed)
    {
        AddToArray(movies, count, t->movie);
    }

    count = GetTopTen(movies, count, t->right);

    return count;
}

void MovieCollection::DisplayTopTenBorrowedMovies()
{
    Movie *movies[10];
    int x = 0;
    int *count = &x;
    GetTopTen(movies, count, this->root);

    for (int i = *count - 1; i >= 0; i--)
    {
        movies[i]->PrintMovie();
    }
}