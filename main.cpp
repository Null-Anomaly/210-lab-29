/*Comsc 210 | Lab 29 | Lawrence Bryant
IDE used: VSC*/

//Generic includes for this pseudocode.
#include <iostream>
#include <string>
#include <map>
#include <array>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Functions that handle the event resolutions based on a random number
//Then we have a print function to display the trees.
//The print function will likely need to break up trees based on type

void event_Resolution(int, map<string, array<string,3>>);
void print_Trees(map<string, array<string,3>>);
string tree_Type();
string fruit_Number();
string tree_Age();


//The main will handle the filling of the data
//It should also handle the random event chance stuff. Ill give a 20%
//chance for event to occur.
int main()
{

    //This is going to be where the file input comes in.
    //The file will simply just shove into a new map..
    //The maps will likely be made by a loop just pushing in the values gotten from the text fiel
    //And the individual things about the map will be put in by some randomized choices.
    //The randomized choices will include the tree type, fruit it produced, and age.
    //I'll have the randomized tree options be individual function calls to reduce the size of main.

    //srand

    //Variables
    string treeput;
    string fruit;
    string num;
    string age;
    map<string, array<string,3>> farm;

    ifstream fin("Outline.txt)");

    //When I have file input this will actually do something
    while(fin.good())
    {
        getline(fin, treeput);
        fruit = tree_Type();
        num = fruit_Number();
        age = tree_Age();
        farm[treeput] = {fruit, num, age};
        //And so on and so forth.
    }

    //Print initial conditions here. Then from there we begin doing the various loops
    //So with this spot we start doing randomization
    //Insert random integer here.

    for(int i = 0; i < 25; i++)
    {
        //randomize each time. If under 20% do an if statement to put in a randomized event
        //Otherwise, just increase age by 1, and make it so that the trees have a random number of fruit
        
    }
    return 0;
}

//Takes in a number, then spits out according to that number.
void event_Resolution(int rando, map<string, array<string,3>> treee)
{
    if (rando == 1)
    {

    }
    if (rando == 2)
    {
        
    }
    if (rando == 3)
    {
        
    }
    if (rando == 4)
    {
        
    }
    if (rando == 5)
    {
        
    }

};
void print_Trees(map<string, array<string,3>>)
{

};
string tree_Type()
{

};
string fruit_Number()
{

};
string tree_Age()
{

};