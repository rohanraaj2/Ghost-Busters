#include "GhostBuster.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Currently rows and columns are set to 8, however your game implementation should work for any other number
const int rows = 8, cols = 8;

// grid will store characters matrix of rows*cols size, you have to allocate memory to it in initialize function below
char* grid = NULL;

// Ghost will be placed over this location
int ghostRow, ghostCol;

// *****************************************************************************************************
// No change zone: Don't change anything until the next stars line
// *****************************************************************************************************

// Don't Change it: Screen width and height values
const int width = 1000, height = 600;

// Don't Change: This function is dealing with SDL and currently it's complete. Don't change anything here
void drawOneBlock(SDL_Renderer* renderer, SDL_Texture* texture, int row, int col, char sym){
    int xbox = width/cols;
    int ybox = height/rows;
    SDL_Rect src;
    switch(sym){
        case 'L': src = {141, 7, 104, 113}; break;
        case 'S': src = {427, 12, 129, 103}; break;
        case 'T': src = {268, 10, 130, 111}; break;
        case 'B': src = {0, 3, 114, 111}; break;
        case 'G': src = {571, 0, 123, 121}; break;
        case 'Z': src = {571, 0, 25, 25}; break;
        case 'F': src = {707, 16, 90, 86}; break;
    }
    SDL_Rect mov = { xbox*col, ybox*row, xbox - 10, ybox - 10};
    SDL_RenderCopy(renderer, texture, &src, &mov);
}

void drawBlocks(SDL_Renderer* renderer, SDL_Texture* texture){
    // Call drawOneBlock for all of the blocks of grid
    // for example to draw a snake over block (3, 5) you call it this way:
    // drawOneBlock(renderer, texture, 3, 5, 'S');
    if(grid == NULL) return;
    for(int i=0;i<rows; i++){
        for(int j=0;j<cols; j++){
            drawOneBlock(renderer, texture, i, j, grid[i*cols+j]);
        }   
    }
}

// *****************************************************************************************************
// No change zone ends here
// *****************************************************************************************************



// To Do zone: 

bool ended = false; //it is initialized to false as the game will be running as run the code

void initialize() // this function will initialize different variables, arrays, store values, etc.
{
    // Create memory for grid here, it should be one dimensional array.
    // The memory should be rows*cols size.
    // Initialize entire grid with 'L' so that locks are displayed all over

    // generate two random numbers and store in ghostRow and ghostCol variables
    int size = rows * cols; // this is the total number of elements in the game.
    grid = new char [size]; // memory is allocated based on the number of rows and columns.
    for (int i = 0; i < size; i++) // a loop is run to initialize all the elements/blocks of the grid.
    {
        *(grid + i) = 'L'; // 'L' represents the lock.
    }
    srand(time(NULL)); // random value is being generated for row.
    ghostRow = rand()%rows; // the random value for row is stored in ghostRow
    srand(time(NULL)); // random value is being generated for column.
    ghostCol = rand()%cols; // the random value for column is stored in ghostCol
}

void huntGhost(int x, int y) // this will run when we left click. This function will handle the information displayed regarding the ghost.
{
    // this function is called every time you click on the screen
    // x, y are screen coordinates, you need to identify the block from these coordinates and using screen width and height values
    // each block size is width/cols x height/rows
    // according to game rules you need to put appropriate character in the grid for that block
    // Place 'S' to draw a snake
    // place 'T' to draw a turtle
    // place 'B' to draw a bunny
    if (ended == false) // if game is running.
    {
        int x_coordinate = x/(width/cols); // x coordinate is scaled based on the column number in the same row.
        int y_coordinate =  y/(height/rows); // y coordinate is scaled based on the row number in the same column.
        int distance_from_ghost = sqrt((pow((ghostRow - x_coordinate) , 2)) + (pow((ghostCol - y_coordinate) , 2))); // distance is being calculated from the block where the ghost lies.
        cout << "Distance is " << distance_from_ghost; // displays the distance from the ghost as displayed in Solution.exe.
        const char animals[3] = {'S', 'T', 'B'}; // array consisting characters reperesenting different animals that can be displayed.
        if (distance_from_ghost >= 0 && distance_from_ghost <= 1)
        {
            *(grid + ((y_coordinate * rows) + x_coordinate)) = animals[0]; // snake will be displayed
        }
        else if (distance_from_ghost >= 2 && distance_from_ghost <= 3)
        {
            *(grid + ((y_coordinate * rows) + x_coordinate)) = animals[1]; // turtle will be displayed
        }
        else if (distance_from_ghost == 4)
        {
            *(grid + ((y_coordinate * rows) + x_coordinate)) = animals[2]; // bunny will be displayed
        }
        else if (distance_from_ghost > 4)
        {
            srand(time(NULL)); // random index is being generated for picking character representing animal.
            *(grid + ((y_coordinate * rows) + x_coordinate)) = animals[rand() % 3]; // animal is selected based on the index generated.
        }
    }
}

void bustGhost(int x, int y) // this is the final part of the game. It will run on right click. This will reveal whether the right clicked block is where the ghost is or not.
{
    // this function is called when you right-click
    // it should work only one time, and you decide whether game is won or failed
    // once the game is won/failed, nothing in game should change anymore.
    // according to game rules you need to put appropriate character in the grid for that block
    // place 'G' to draw ghost, when the game is won
    // place 'F' to draw failed symbol, when the game is failed
    if (ended == false) // if game is running.
    {
        int x_coordinate = x/(width/cols); // x coordinate is scaled based on the column number in the same row.
        int y_coordinate =  y/(height/rows); // y coordinate is scaled based on the row number in the same column.
        if (y_coordinate == ghostRow && x_coordinate == ghostCol) // we clicked the block where the ghost lies.
        {
            *(grid + ((y_coordinate * rows) + x_coordinate)) = 'G'; // ghost will be displayed.
        }
        else // either row or column or both, of the block we selected are different than ghost's.
        {
            *(grid + ((y_coordinate * rows) + x_coordinate)) = 'F'; // fail sign will be displayed.
        }
    }
    ended = true; // game is finished.
}

void quitGhostBuster() // this will quit the game and the reset the value for grid.
{
    // delete the grid here
    delete[] grid; // grid is deleted.
    grid = nullptr; // grid is set to nullptr.
}