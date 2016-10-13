//
//Christian Hill
//HW4 _ 10/12/16
//CSCi 2270 - Boese
//This program is a movie rental type service that uses a binary search tree,
//the user can find, rent, or print out all movies available
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include "MovieTree.hpp"
#include <string>

using namespace std;

MovieTree::MovieTree()
{
    MovieTree::root = NULL;
}

MovieTree::~MovieTree()
{
}
void MovieTree::printMovieInventory(MovieNode* node)
{
    if (node== NULL)
    {
        return;
    }
    printMovieInventory(node -> leftChild);
    cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
    printMovieInventory(node -> rightChild);
}

void MovieTree::printMovieInventory()
{
    printMovieInventory(root);
}


void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity)
{
        MovieNode* foundMovie=new MovieNode;
        foundMovie->ranking=ranking;
        foundMovie->title=title;
        foundMovie->year=releaseYear;
        foundMovie->quantity=quantity;
        foundMovie->rightChild=NULL;
        foundMovie->leftChild=NULL;
        foundMovie->parent=NULL;

    if (root == NULL)
    {
        root=foundMovie;
    }
    else
        {
        MovieNode *temp = root;
        MovieNode *temp1=root;
        while(temp!=NULL)
        {
        if(temp->title.compare(foundMovie->title)>0)
        {
            temp1=temp;
            temp=temp->leftChild;
        }
        else
            {
            temp1=temp;
            temp=temp->rightChild;
            }

    }
        if(temp1->title.compare(foundMovie->title)>0)
            {
        temp= foundMovie;
        temp1->leftChild=temp;
        temp->parent=temp1;
            }
            else
            {
            temp= foundMovie;
            temp1->rightChild=temp;
            temp->parent=temp1;
            }
    }
}
//search function that compares string on a pointer called temp (set to root)
//will return the the pointer that contains the movie the user wants
MovieNode* MovieTree::search(string title)
{
MovieNode* temp=root;
    while(temp!=NULL)
    {
    if(temp->title==title)
    {
        return temp;
    }

    if(temp->title.compare(title)<0)
            {
                temp=temp->rightChild;
            }
            else if(temp->title.compare(title)>0)
            {
                temp=temp->leftChild;
            }
    }
    return temp;
}
//Uses the search function to find the movie the uses wants, and prints the information
void MovieTree::findMovie(string title)
{
    MovieNode* temp=search(title);
     if(temp==NULL)
    {
    cout << "Movie not found" << endl;
    return;
    }
            cout << "Movie Info:" << endl;
            cout << "===========" << endl;
            cout << "Ranking:" << temp->ranking << endl;
            cout << "Title:" << temp->title << endl;
            cout << "Year:" << temp->year << endl;
            cout << "Quantity:" << temp->quantity << endl;
            return;
}

//Uses the search function to find the movie the uses wants, prints the information
//and decrements the quantity of that movie
void MovieTree::rentMovie(string title)
{
    MovieNode* temp=search(title);

            if(temp->quantity==0)
            {
                cout << "Movie out of stock." << endl;
                return;
            }
            MovieNode* foundMovie=temp;
            foundMovie->quantity--;
            cout << "Movie has been rented." << endl;
            cout << "Movie Info:" << endl;
            cout << "===========" << endl;
            cout << "Ranking:" << foundMovie->ranking << endl;
            cout << "Title:" << foundMovie->title << endl;
            cout << "Year:" << foundMovie->year << endl;
            cout << "Quantity:" << foundMovie->quantity << endl;
            return;
    if(temp==NULL)
    cout << "Movie not found." << endl;
}
