// a31-The-League-with-Structs

// CS110B Assignment 8: The League with Structs
// Rewrite your league application from Assignment 6 so that each team/wins pair is stored in a struct 
// named WinRecord.  Your program must meet the following requirements:


#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;


// 1.  The WinRecord struct must have two fields: an int named wins, and a char* named name.  
// name will point to a dynamically allocated array of characters, see requirement 4 below.

struct WinRecord
{
    int wins; 
    char* name;                                                    // points to a dynamically allocated array of characters
};

char* getLine();
void initializeData(WinRecord* standings, int size);
void displayData(WinRecord* standings, int size);
void sortData(WinRecord* standings, int size);
void deleteData(WinRecord* standings, int size);
void charSwapper(char* x, char* y);
void intSwapper(int& x, int& y);



// 2.  Instead of using two parallel arrays like Assignment 6, 
// the data must be stored in a single array -- a dynamically allocated array of WinRecord structs.  
// You must ask the user how many teams are in the league to determine how big this array needs to be 
// and then dynamically allocate memory for it using new.  
// It must deallocate the memory when it is done with the array using delete [].



int the_league()
{

    const int MAX_CHAR = 128;

    WinRecord *standings = NULL;

    int size;

    cout << "How many teams are in the league? " << endl;
    cin >> size;
    // for every cin we must clean out cin garbage so getLine function can work
    cin.ignore();

    standings = new WinRecord[size];

    initializeData(standings,size);

    // so close but I have an infinate loop:
    // sortData(standings,size);

    displayData(standings,size);

    
    deleteData(standings,size);
    delete [] standings;
    standings = NULL;

}

void charSwapper(char* x, char* y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

//swaps ints passed in by reference
void intSwapper(int& x, int& y)
{
    int temp = x;

    x = y;
    y = temp;


}


// gets standings information from input using cin
void initializeData(WinRecord* standings, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter team name #" << i+1 << ": " << endl;
        standings[i].name = getLine();                             // array notation to input from user using fuction

        cout << "Enter the wins for team #" << i+1 << ": " << endl;
        cin >> standings[i].wins;                                  // array notation to get input from user
        cin.ignore();
    }
}

// prints standings information to screen
void displayData(WinRecord* standings, int size)
{
    cout << "League Standings:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << standings[i].name << ": " << standings[i].wins << endl;
    }
}

// deallocates memory for the created standing names
void deleteData(WinRecord* standings, int size)
{
    for (int i = 0; i < size; i++)
        {
            delete standings[i].name;   
        }
}


// so close but I have an infinate loop
void sortData(WinRecord* standings, int size)
{
    bool swapped = false; //set swapped true if any swap occurs
    do
    {  
        for (int i = 0; i < size-1; i++)
        {
            swapped = false;
            if (standings[i].wins < standings[i+1].wins)
            {
                cout << "Before sort # " << i+1 << " " << standings[i].wins << endl;
                cout << "Before sort # " << i+1 << " " << standings[i+1].wins << endl;             
                

                intSwapper(standings[i].wins, standings[i].wins);

                cout << "After sort # " << i+1 << " " << standings[i+1].wins << endl;             
                cout << "After sort # " << i+1 << " " << standings[i].wins << endl;
                
                charSwapper(standings[i].name, standings[i].name);
                // swapperChar(names[i], names[i+1]);
                
                swapped = true;
            }
            else
                swapped = false;
        }

    }while (swapped);
}



// 4.  Note that the name field of each WinRecord struct is just a char* which you need to use to store a C-String.
// For this assignment, you must use C-strings, not C++ string objects.  
// Unlike a C++ string object, the memory to store the actual character array for the C-String 
// is not allocated for you automatically!  
// I encourage you to develop a function to do this on your own, 
// but I have provided the getLine() function getLine.cpp to use if you wish.  
// Note that this function returns a line of text from the keyboard contained in a dynamically allocated array.  
// You will thus need to deallocate this memory using delete [] when you are done using any arrays 
// you allocated using this function.  
// Note that this is in addition to de-allocating the array of WinRecord structs discussed in step 2 above!



// Max Luttrels given function
char* getLine() 
{
  const int BUFFER_SIZE = 1000;

  // Allocate a buffer local to this function
  char buffer[BUFFER_SIZE];
    
  // Use cin.getline() to input the buffer from the user
  cin.getline(buffer, BUFFER_SIZE);
    
  // Find the length of the string in buffer
  int length = strlen(buffer);

  // Dynamically allocate an array, to be returned
  char *rValue = new char[length + 1];

  // Copy the string into the dynamically allocated array
  strncpy(rValue, buffer, length);

  // Return the address of the dynamically allocated array
  return rValue;
}



// // getLine tester
//     char name;
//     cout << "Name? " << endl;
//     cin >> getLine() >> name;
//     cout << name << endl;

// // deleteData tester
// cout << "Deleting name #" << i+1 << ": " << endl;


// allocates memory to store the actual character array for the C-String  




// 5.  As usual, provide sample output demonstrating your program works correctly and submit via Canvas.  

// sample run

// How many teams are in the league? 
// 2
// Enter team name #1: 
// f
// Enter the wins for team #1: 
// 2
// Enter team name #2: 
// g
// Enter the wins for team #2: 
// 3
// League Standings:
// f: 2
// g: 3
