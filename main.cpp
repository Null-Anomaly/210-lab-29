/*Comsc 210 | Lab 29 | Lawrence Bryant
IDE used: VSC*/

//Generic includes for this pseudocode.
#include <iostream>
#include <string>
#include <map>
#include <array>
#include <ifstream>
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

    //Variables
    string treeput;
    string fruit;
    string num;
    string age;
    map<string, array<string,3>> farm;

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

    return 0;
}

void event_Resolution(int, map<string, array<string,3>>)
{

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