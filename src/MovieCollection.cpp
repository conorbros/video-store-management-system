#include <string>
#include <iostream>
#include "MovieCollection.h"
#include "Movie.h"
#include "Node.h"

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

void p(std::string s)
{
    std::cout << s << std::endl;
}

void InOrderTraversalToArray(Node *t, Movie *arr[], int *i)
{
    if (t == NULL)
    {
        return;
    }

    InOrderTraversalToArray(t->left, arr, i);
    arr[*i] = t->movie;
    ++*i;
    InOrderTraversalToArray(t->right, arr, i);
}

void Heapify(Movie *movies[], int n, int i)
{
    int smallest = i;  // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && movies[l]->borrowed < movies[smallest]->borrowed)
        smallest = l;

    // If right child is larger than largest so far
    if (r < n && movies[r]->borrowed < movies[smallest]->borrowed)
        smallest = r;

    // If largest is not root
    if (smallest != i)
    {
        Movie *temp = movies[i];
        movies[i] = movies[smallest];
        movies[smallest] = temp;

        // Recursively heapify the affected sub-tree
        Heapify(movies, n, smallest);
    }
}

void HeapSort(Movie *movies[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(movies, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        Movie *temp = movies[i];
        movies[i] = movies[0];
        movies[0] = temp;
        Heapify(movies, i, 0);
    }
}

void GetTopTenBorrowedMovies(Node *t, int n)
{
    Movie *movies[n];
    int i = 0;
    InOrderTraversalToArray(t, movies, &i);

    HeapSort(movies, n);

    if (n > 10)
    {
        n = 10;
    }

    for (int i = 0; i < n; i++)
    {
        movies[i]->PrintMovie();
    }
}

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

Node *Insert(Movie *inserted_movie, Node *t)
{
    Node *new_node = new Node(inserted_movie, NULL, NULL, NULL);
    Node *trav_node = t;
    Node *trailing_node = NULL;

    while (trav_node != NULL)
    {
        trailing_node = trav_node;
        if (inserted_movie->title < trav_node->GetTitle())
            trav_node = trav_node->left;
        else
            trav_node = trav_node->right;
    }

    if (trailing_node == NULL)
    {
        trailing_node = new_node;
    }
    else if (inserted_movie->title < trailing_node->GetTitle())
    {
        trailing_node->left = new_node;
    }
    else
    {
        trailing_node->right = new_node;
    }
    return trailing_node;
}

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

Node *Remove(Movie *movie, Node *t)
{
    if (t == NULL)
    {
        return t;
    }

    if (movie->title < t->GetTitle())
    {
        t->left = Remove(movie, t->left);
    }
    else if (movie->title > t->GetTitle())
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

void MovieCollection::DisplayTopTenBorrowedMovies()
{
    GetTopTenBorrowedMovies(this->root, this->movie_count);
}