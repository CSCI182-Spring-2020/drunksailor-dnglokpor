
/*
CSCI 182 - Assignment 5
DrunkSailor.cpp
Compute a random number of steps of a "drunk man" on a 20x20 map

Brett Huffman
v1.2 2/12/2020
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// preprocessor constants
#define WIDTH 20
#define HEIGTH 20
#define MAX_STEPS 1000

using namespace std;

// possible directions enum
enum Directions {NORTH, EAST, SOUTH, WEST};

int main()
{
	// position markers
	int posX = WIDTH / 2, posY = HEIGTH / 2;

	// movement board
	int board[WIDTH][HEIGTH];

	// direction indicator
	Directions movementDirection;

	// reseed random generator
	srand(time(NULL));

	// zero out the board
	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGTH; y++)
			board[x][y] = 0;

	// record initial position
	board[posX][posY]++;

	// movement loop
	for (int steps = 0; steps < MAX_STEPS; steps++) {
		// get next random move
		movementDirection = static_cast<Directions>(rand() % 4); // will return an int between 0 and 3 that is typecasted as an enum Directions
		
		// movement
		switch (movementDirection) {
			case NORTH:
				if (posY > 0) // we make sure we are not at the board limit
					posY--; // move up
				break;
			case EAST:
				if (posX < (WIDTH - 1)) // we make sure we are not at the board limit
					posX++; // move right
				break;
			case SOUTH:
				if (posY < (HEIGTH - 1)) // we make sure we are not at the board limit
					posY++; // move down
				break;
			default: //case WEST:
				if (posX > 0) // we make sure we are not at the board limit
					posX--; // move left
				break;
		}

		// record step position
		board[posX][posY]++;
	}

	// printing results
	for (int x = 0; x < WIDTH; x++){
		for (int y = 0; y < HEIGTH; y++)
			cout << board[x][y] << "; ";
		cout << endl;
	}
}