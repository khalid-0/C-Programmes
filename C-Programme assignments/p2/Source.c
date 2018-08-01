#include "Header.h"

void main(){
	FILE *fp;
	char hosting[20];
	char visiting[20];
	int totalGames=0, hostingWin=0, visitingWin=0;
	int  HTO, HTD, HTS, HTH, HTC, VTO, VTD, VTS, VTR;
	float preference1, preference2, preference3, preference4, preference5, sumOfprediction;

	printf("FILE 1:\n");
	fp = fopen("football1.txt", "r");
	while (input(fp, hosting, &HTO, &HTD, &HTS, &HTH, &HTC, visiting, &VTO, &VTD, &VTS, &VTR) > 0){
		compute(&preference1, &preference2, &preference3, &preference4, &preference5, HTO, HTD, HTS, HTH, HTC, VTO, VTD, VTS, VTR);
		prediction(&sumOfprediction, preference1, preference2, preference3, preference4, preference5);
		output(hosting, visiting, sumOfprediction);
		update(sumOfprediction, &totalGames, &hostingWin, &visitingWin);
	}
	summary(totalGames, hostingWin);
	fclose(fp);

	printf("\n\nFILE 2:\n");
	fp = fopen("football2.txt", "r");
	while (input(fp, hosting, &HTO, &HTD, &HTS, &HTH, &HTC, visiting, &VTO, &VTD, &VTS, &VTR) > 0){
		compute(&preference1, &preference2, &preference3, &preference4, &preference5, HTO, HTD, HTS, HTH, HTC, VTO, VTD, VTS, VTR);
		prediction(&sumOfprediction, preference1, preference2, preference3, preference4, preference5);
		output(hosting, visiting, sumOfprediction);
		update(sumOfprediction, &totalGames, &hostingWin, &visitingWin);
	}
	summary(totalGames, hostingWin);
	fclose(fp);

	getchar();
}