#include <stdio.h>
#include <ctype.h>
#include <math.h>

//defining the constants
#define OFFENSIVE_FACTOR 1.5
#define SPECIAL_TEAMS_FACTOR 1.2
#define HOME_FIELD_ADVANTAGE 1.3
#define OVERALL_FACTOR 1.15
#define OFFENSIVE_WORTH 0.32
#define DEFENSIVE_WORTH 0.28
#define SPECIAL_WORTH 0.15
#define HOME_WORTH 0.1
#define OVERALL_WORTH 0.15

//to compute the value of prefrences
void compute(float *, float*, float *, float *, int, int, int, int, int, int, int, int, int);
//computing the value of prediction
void prediction(float *, float, float, float, float, float);
//updateing the number of games to be played, number of hometown winings, and the number of visiting team wining
void update(float, int *, int *, int *);

//getting 11 elements from the file to the vatiables at a time
int input(FILE *, char *, int *, int *, int *, int *, int *, char *, int *, int *, int *, int *);
//outputing a summary of a game
void output(char *, char *, float);
//outputing the summary of HT favore in the games
void summary(int, int);


