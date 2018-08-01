#include "Header.h"

void compute(float *pr1, float *pr2, float *pr3, float *pr4, float *pr5, int HTO, int HTD, int HTS, int HTH, int HTC, int VTO, int VTD, int VTS, int VTR){
	*pr1 = HTO * OFFENSIVE_FACTOR - VTD;
	*pr2 = HTD + 2 - VTO * OFFENSIVE_FACTOR;
	*pr3 = HTS * SPECIAL_TEAMS_FACTOR - VTS;
	*pr4 = HTH + HTC * HOME_FIELD_ADVANTAGE - VTS;
	*pr5 = HTO * HTD * HTH * OVERALL_FACTOR - VTO * VTD * VTR;
}

void prediction(float *sum, float pr1, float pr2, float pr3, float pr4, float pr5){
	*sum = pr1 * OFFENSIVE_WORTH + pr2 * DEFENSIVE_WORTH + pr3 * SPECIAL_WORTH + pr4 * HOME_WORTH + pr5 * OVERALL_WORTH;
	if ((int)*sum ==0) *sum = *sum+1;
}

void update(float sum, int *totalGames, int *hostingWin, int *visitingWin){
	*totalGames = *totalGames + 1;
	if (sum >= 0)
		*hostingWin = *hostingWin + 1;
	else
		*visitingWin = *visitingWin + 1;
}

float absVal(float value){
	if (value < 0) return value / -1;
	return value;
}