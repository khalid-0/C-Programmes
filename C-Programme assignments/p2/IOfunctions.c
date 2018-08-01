#include "Header.h"

int input(FILE *fp, char *hosting, int *a, int *b, int *c, int *d, int *e, char *visiting, int *f, int *g, int *h, int *i){
	return fscanf(fp, "%s %d %d %d %d %d %s %d %d %d %d", hosting, a, b, c, d, e, visiting, f, g, h, i);
}

void output(char *hosting, char *visiting, float sum){
	if (sum >= 0)
		printf("Predicted %s over %s by %i\n", hosting, visiting, (int)absVal(sum));
	else
		printf("Predicted %s over %s by %i\n", visiting, hosting, (int)absVal(sum));
}

void summary(int totalGames, int hostingWin){
	printf("Out of %i games, %0.2f%% favor the home team", totalGames, ((float)hostingWin / (float)totalGames) * 100);
}