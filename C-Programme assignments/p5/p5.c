// Khalid Almutairi 
// professor Richard Fox
// CSC 362 section 001
// Programme #5


/* assembly program to sort array by selection sorting*/

#include <stdio.h>

void main(){
	int i;		// i is iterator and n is array's length.

	int a[] = {100, 99, 97, 95, 90, 87, 86, 83, 81, 77, 74, 69, 63, 50, 44, 43, 39, 31, 29, 12};
	//int a[] = { 8, -1, 7, -8, 6, 3, -4, 4, 1, -2, 9, -5, 0, 2 };
	int n = sizeof(a);	// length in byte, the array in assemply language.

	__asm{
		// eax is for i and j. ebx is for min index

		mov		i, 0
		mov		eax, i			// eax = i
		for1 : mov		ecx, n
			   sub		ecx, 4			// ecx = length-1
			   cmp		eax, ecx
			   jge		end				// leave for loop if i>= n.
			   mov		ebx, eax		// minposition = i


		   for2 : add		eax, 4			// eax is j now. j=i+1
				  cmp		eax, n
				  jge		for1X			// if j>= length leave for loop
				  mov		ecx, a[ebx]		// ecx temporarliy is a[minposition]
				  cmp		a[eax], ecx
				  jge		for2			// if a[j]>= a[minposition] keep looping
				  mov		ebx, eax		// if not, minposition = j
				  jmp		for2			// loop

			  for1X :
		mov		eax, i
			mov		ecx, a[eax]		// swap between a[minposition] and a[i]
			mov		edx, a[ebx]
			mov		a[ebx], ecx
			mov		a[eax], edx		// end of swap

			add		i, 4			//i++
			mov		eax, i
			jmp		for1			// loop
		end :
	}

	// print the sortted array in c
	n = sizeof(a) / sizeof(int);
	for (i = 0; i < n; i++) printf("%i ", a[i]); // print the elements of the array.


	getchar();
}
