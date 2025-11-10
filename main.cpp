/*Comsc 210 | Lab 29+30+31 | Lawrence Bryant
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
void event_Resolution(int, map<string, array<string,3>>&);
void print_Trees(map<string, array<string,3>>);
string tree_Type();
string fruit_Number();
string tree_Age();

//These are for actually editing it once running.
void fruit_Change(map<string, array<string,3>>&, int);
void age_Up(map<string, array<string,3>>&, int);


//The main
int main()
{
    //srand
    srand(time(NULL));

    //Variables
    string treeput;
    string fruit;
    string num;
    string age;
    int randocool = 0;
    map<string, array<string,3>> farm;

    ifstream fin("Values.txt)");
    fin.open("Values.txt");

    //While file input is good
    while(fin.good())
    {
        getline(fin, treeput);
        fruit = tree_Type();
        num = fruit_Number();
        age = tree_Age();
        farm[treeput] = {fruit, num, age};
    }

    //Print initial conditions here. Then from there we begin doing the various loops
    print_Trees(farm);
    
    //The main loop that handles each year that passes.
    for(int i = 0; i < 25; i++)
    {
        randocool = rand() % 100;

        if(randocool <= 20)
        {
            event_Resolution(randocool,farm);

        }
        else
        {
            fruit_Change(farm, 0);
            age_Up(farm, 0);
        }

        cout << "Year: " << i + 1 << "\n";
        print_Trees(farm);

    }

    cout << "Just here to look at all of the info. Just hit enter to close.\n";
    cin.get();

    return 0;
}

//Takes in a number, then spits out according to that number.
void event_Resolution(int rando, map<string, array<string,3>> &treee)
{
    
    static bool pestecide_Used = NULL;
   
    if (rando == 1)
    {
        pestecide_Used = false;
        fruit_Change(treee, rando);
        age_Up(treee, rando);
        //Rain. Increases fruit count.
    }
    if (rando == 2)
    {
        pestecide_Used = false;
        fruit_Change(treee, rando);
        age_Up(treee, rando);
        //Fertilized. Increases Fruit count. Maintains age
    }
    if (rando == 3)
    {
        fruit_Change(treee, rando);
        age_Up(treee, rando);
        pestecide_Used = true;
        //Pestecide. Increases age. Reduce effect of plague
    }
    if (rando == 4)
    {
        fruit_Change(treee, rando);
        if(pestecide_Used == true)
        {
            age_Up(treee, 6);
        }
        else
        {
            age_Up(treee, rando);
        }
        pestecide_Used = false;
        
        //Plague. Will be reduced if pestecide was used last round. Decrease fruit
    }
    if (rando == 5)
    {
        fruit_Change(treee, rando);
        age_Up(treee, rando);
        pestecide_Used = false;
        //Droughts. Decrease Fruit count.
    }

};

//Tree print function
void print_Trees(map<string, array<string,3>> treee)
{
    auto it = treee.begin();
    while(it != treee.end())
    {
        cout << "Tree ID: " << it->first << " | Type: " << it->second[0] << " | Fruit Count: " << it->second[1] << " | Age: " << it->second[2] << "\n";
        it++;
    };

};

//Dictates the tree type
string tree_Type()
{
    array<string, 5> trees = {"apple", "orange", "lemon", "plum", "peach"};
    int randomized = rand() % 5;
    return trees[randomized];

};

//Generates a random number of fruit at start
string fruit_Number()
{

array<string, 51> fruit = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
  "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
  "twenty-one", "twenty-two", "twenty-three", "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine", "thirty",
  "thirty-one", "thirty-two", "thirty-three", "thirty-four", "thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine", "forty",
  "forty-one", "forty-two", "forty-three", "forty-four", "forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine", "fifty",};
int randomized = rand() % 51;
return fruit[randomized];

};

//Selects the tree's starting age
string tree_Age()
{
    array<string, 52> age = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
  "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
  "twenty-one", "twenty-two", "twenty-three", "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine", "thirty",
  "thirty-one", "thirty-two", "thirty-three", "thirty-four", "thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine", "forty",
  "forty-one", "forty-two", "forty-three", "forty-four", "forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine", "fifty",
  "fifty-one"};
    int randomized = rand() % 51;
    return age[randomized];

};

//Changes the fruit's fruit number
void fruit_Change(map<string, array<string,3>> &treee,int disaster)
{
    array<string, 51> fruit = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
  "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
  "twenty-one", "twenty-two", "twenty-three", "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine", "thirty",
  "thirty-one", "thirty-two", "thirty-three", "thirty-four", "thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine", "forty",
  "forty-one", "forty-two", "forty-three", "forty-four", "forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine", "fifty",};

    int randomization = 0;
    auto it = treee.begin();
    //Rain
    for(int i = 0; i < treee.size(); i++)
    {
        if(disaster == 1)
        {
            randomization = rand() % 50 + 10;
            if(randomization > 50)
            {
                randomization = 50;
                it->second[1] = fruit[randomization];
            }
            else
            {
                it->second[1] = fruit[randomization];
            }
        }

        //Fertilizer
        else if(disaster == 2)
        {
            randomization = rand() % 50 + 15;
            if(randomization > 50)
            {
                randomization = 50;
                it->second[1] = fruit[randomization];
            }
            else
            {
                it->second[1] = fruit[randomization];
            }
        }

        //Plague occurs
        else if(disaster == 4)
        {
            randomization = rand() % 50 - 20;
            if(randomization < 0)
            {
                randomization = 0;
                it->second[1] = fruit[randomization];
            }
            else
            {
                it->second[1] = fruit[randomization];
            }
        }

        //Drought
        else if(disaster == 5)
        {
            randomization = rand() % 50 - 10;
            if(randomization < 0)
            {
                randomization = 0;
                it->second[1] = fruit[randomization];
            }
            else
            {
                it->second[1] = fruit[randomization];
            }   
        }

        //Plague but pesticides were used.
        else if(disaster == 6)
        {
            randomization = rand() % 50 - 5;
            if(randomization < 0)
            {
                randomization = 0;
                it->second[1] = fruit[randomization];
            }
            else
            {
                it->second[1] = fruit[randomization];
            }
        }
        
        //Any other non-fruit affecting event case.
        else
        {
            randomization = rand() % 50;
            it->second[1] = fruit[randomization];
        }
        advance(it,1);
        //Adjusts fruit count. Accounts for disasters.
    }
}

//Increases tree's age
void age_Up(map<string, array<string,3>> &treee, int disaster)
{
    array<string, 101> age = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
  "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
  "twenty-one", "twenty-two", "twenty-three", "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine", "thirty",
  "thirty-one", "thirty-two", "thirty-three", "thirty-four", "thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine", "forty",
  "forty-one", "forty-two", "forty-three", "forty-four", "forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine", "fifty",
  "fifty-one", "fifty-two", "fifty-three", "fifty-four", "fifty-five", "fifty-six", "fifty-seven", "fifty-eight", "fifty-nine", "sixty",
  "sixty-one", "sixty-two", "sixty-three", "sixty-four", "sixty-five", "sixty-six", "sixty-seven", "sixty-eight", "sixty-nine", "seventy",
  "seventy-one", "seventy-two", "seventy-three", "seventy-four", "seventy-five", "seventy-six", "seventy-seven", "seventy-eight", "seventy-nine", "eighty",
  "eighty-one", "eighty-two", "eighty-three", "eighty-four", "eighty-five", "eighty-six", "eighty-seven", "eighty-eight", "eighty-nine", "ninety",
  "ninety-one", "ninety-two", "ninety-three", "ninety-four", "ninety-five", "ninety-six", "ninety-seven", "ninety-eight", "ninety-nine", "one hundred"};

    int i = 0;

    auto it = treee.begin();
    for(int j = 0; j < treee.size(); j++)
    {
        while( it->second[2] != age[i])
        {
            i++;
        }

        if (disaster == 3)
        {
            i ++;
        }
        if (disaster == 2)
        {
            i--;
        }
        it->second[2] = age[i+1];
        advance(it,1);
        i = 0;
    }

}
