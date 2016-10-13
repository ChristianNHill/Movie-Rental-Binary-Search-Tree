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
#include <algorithm>
#include "MovieTree.hpp"
#include "MovieTree.cpp"
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
    MovieTree test;
    ifstream file;
    //takes in file through command line argument
    file.open(argv[1]);
    int i=0;
    string ranking;
    string title;
    string release;
    string quantity;
    // extract the text from file and create the binary search tree
    while(i<50)
    {
        getline( file, ranking, ',');
        int r;
        stringstream stoi(ranking);
        stoi>>r;
        getline( file, title, ',');
        getline(file, release, ',');
        int re;
        stringstream sto(release);
        sto>>re;
        getline(file, quantity);
        int q;
        stringstream st(quantity);
        st>>q;
        test.addMovieNode(r,title,re,q);
        i++;
    }


    int ch=0;

// this is the menu where the user can select what function they want to use
    while(ch!=4)
    {
        cout<<"===== Main Menu =====";
        cout<<"\n 1. Find Movie";
        cout<<"\n 2. Rent a Movie";
        cout<<"\n 3. Print Entire Inventory";
        cout<<"\n 4. Quit program"<<endl;
        cin>>ch;
        if(ch==1)
        {
            cout<<"\n 1. Enter movie title:";
            string title;
            cin>>ws;
            getline(cin,title);
            test.findMovie(title);

        }
        else if(ch==2)
        {
            cout<<"\n 2. Enter movie title:";
            string title;
            cin>>ws;
            getline(cin,title);
            test.rentMovie(title);
        }


        else if(ch==3)
        {
            cout<<"\n 3. Print Entire Inventory: "<<endl;
            test.printMovieInventory();

        }

        else if(ch==4)
        {
            cout << "Goodbye!" << endl;
        }
    }


}

