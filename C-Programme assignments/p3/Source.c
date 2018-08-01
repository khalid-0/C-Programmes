// Khalid Almutairi 
// professor Richard Fox
// CSC 362 section 001
// Programme #3



/*
The programme demonstartes a race between a hare and a tortoise. Every move from the two animals will be repersented on a path of array of 50
that contains rock stream and carrot. The race path will iterate until one animal win.
The programme has three functions. The first function for the tortoise movment. This function will generate a random number from 1-3 and then check
if there is a collision with the hare movement function. If so then the tortoise will step one space of the hare. The second function is for the
hare movement. The fucntion strictly moves hare only on the character of 'C' and ' ', Then the function will generate a number from 1-8 and check
the hare move if it's lands on a carrot, then hare eat it or check if the hare is sleeping or awake. If the hare awake then generate number from
1-8. Also, the function check if the hare collide with rock, stream or tortoise, if so then step back one move. The third function is for the
output. This function will print the Hare, the tortoise and the race path.  Also it show if the two animal collide.
*/


#include <stdio.h>
#include <stdlib.h>	
#include <time.h>


// Function for the tortoise movement.
char* mtortoise(char* hare, char* tortoise, char* end, int* collision);
// Function for the hare movement.
char* mhare(char* hare, char* tortoise, char* end, int* collision);
// Function for the output.
void output(char* p, char* hare, char* tortoise, int* collision);


void main(){

	char path[] = " R R R SSSSS R R R R CCCCCCCCCC R SSSR "; // The race path.
	char* hare;	     // pointer for hare location movement.
	char* tortoise;	 // pointer for tortoise location.
	char* end;	     // pointer for the end of the race path.
	int turn = 1;	 // for the number of turn.
	int collision;	 // to determine if there is a collision.

	srand(time(NULL));

	// assign locations for hare, tortoise and the end of the path array.
	hare = &path[0];	     // Initialize hare location.
	tortoise = &path[0];	 // Initialize tortoise location.
	end = &path[sizeof(path) / sizeof(char) - 1];	// Initialize the last location of the path array.

	// while loop for the three functions.
	while (tortoise <= end && hare <= end){  // the loop will end when reach reach the "end"
		tortoise = mtortoise(hare, tortoise, end, &collision); // Tortoise's movement.
		hare = mhare(hare, tortoise, end, &collision);   // Hare's movement.
		printf("Turn: \t%i\t", turn);  // print number of turns.
		turn++; // turn iterator.
		output(&path[0], hare, tortoise, &collision); // The locations of hare, tortoise and array path. Also show if there is a collision.
	}
	// A condtion for the winner.
	if (tortoise > hare){

		printf("\nTortoise won !");
	}
	else{

		printf("\nHare won !");
	}

	getchar();
}

// Function for the tortoise's movement.
char* mtortoise(char *hare, char *tortoise, char* end, int *collision){

	int random = rand() % 3 + 1;	 //	Generate random number from 1-3 for the tortoise's movement.
	if (tortoise + random == hare){	 // If tortoise's move land on the hare location. Move back one location and set collision to 1.

		random--;
		*collision = 1;
	}
	else if(tortoise+random > end){ //if this movement will take it to the end
		tortoise = end+1;	 //move tortoise to the end location
	}
	else{
		tortoise += random;	//	set tortoise to random number for the movment.
	}
	return tortoise;
}

// Function for the hare's movement.
char* mhare(char *hare, char *tortoise, char *end, int *collision)
	{
	int random;
	//If the hare location lands on a carrot then eat the carrot. Or the hare either sleeping or awake.
	if (*hare == 'C')
	{
		*hare = ' ';
	}
	else{
		random = rand() % 2;	    // Generate random numbers either 0 or 1. If random number is 1 that means the hare is awake then keep hopping
		if (random == 1){	        // if the radnom number is 0 that means the hare is sleeping.
			random = rand() % 8 + 1;

			if (hare + random <= end){

				// If the hare's move lands on rock, stream or tortoise then step back one location
				while (*(hare + random) == 'R' || *(hare + random) == 'S' || hare + random == tortoise){

					random--;

					// if the move move will land on the tortoise then set collision to 1.
					if (hare + random == tortoise) { *collision = 1; }
				}
				hare += random;	 // move the hare.
			}

			else{ hare = end+1; }	 // move the hare to the end.

		}
	}
	return hare; // Return the new hare's move.
}

// Function to output the race path, hare, tortoise and collision.
void output(char *racePath, char *hare, char *tortoise, int *collision){

	while (*racePath != '\0'){	 // While the location of the race path is not the end of the path.

		// If the location of path = to hare then print 'H'
		if (racePath == hare)
		{
			printf("%c", 'H');
		}
		// If the location of path = to tortoise then print 'T'
		else if (racePath == tortoise)
		{
			printf("%c", 'T');
		}
		else
		{
			printf("%c", *racePath);  // else print the rest path race.
		}
		racePath++;	 // Next location.
	}

	if (*collision == 1){	 // If there is a collisiosn print "---Collision---"
		printf("---Collision---");
		*collision = 0;	 // Set to 0
	}
	// new turn.
	printf("\n");
}