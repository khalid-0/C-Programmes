/*
Khalid Almutairi
professor Richard Fox
CSC 362 section 001
Programme #4

The programme is to prove the Goldbach’s conjecture which every even integer greater than 2 is the sum of 2
prime numbers. The programme will prove the number from 6 to 100 by assembly language programme.

*/

#include <stdio.h>
#include <ctype.h>

void main()
{

	int sum = 4; // The sum of two prime numbers, incremented by two, starting by 4+2
	int x = 1; // for the first prime number, incremented by two. Starting from 1+2
	int y; // the second prime number
	int f = 0; // for the division of the prime numbers.


	__asm{
		mov eax, sum // put the sum in eax
		OuterLoop :  // This loop to iterate even numbers from 6 to 100
		add eax, 2  //  add two, for the first loop eax = 4+2= 6
			cmp eax, 100 // compare the even number to 100
			jg xout // leave the loop if sum is greater than 100
			mov edx, 1 // edx = X = 1
		innerloop : // Enter to a loop that generate the Y which that another prime number.
					mov ebx, eax // The innerloop should end if x >= sum-2, put eax(sum) in ebx
					sub ebx, 3 // subtract 3 from ebx, prepare for compare
					cmp ebx, edx // Will never be used unless Goldbach’s conjecture is false
					jle OuterLoop
					add edx, 2 // x+=2
					//Get y
					mov ebx, eax // y = sum
					sub ebx, edx // y = sum - x
					mov sum, eax // Save the value of sum
					mov x, edx // Save x
					mov y, ebx // Save y

					// Check if ebx and edx are prime, if yes continue then jmp OutLoop , else jmp innerloop
					mov f, 2
				    isXPrime:
		              mov ebx, x
			          mov  eax, x		// prepare for division
			          mov  edx, 0     
			          cmp ebx, f  
			            je isYprimeOut // X is prime
					  div f  // eax = x / f, edx = remainder
					  cmp edx, 0
					    je nextX // Not prime
					  add f, 1
					  jmp isXPrime

		            isYprimeOut : // come here is x is prime
		             mov f, 2
		         isYPrime :
				 mov ebx, y
				 mov  eax, y		// prepare for division
				 mov  edx, 0
				 cmp ebx, f
				 je solutionFound // X is prime
				 div f  // eax = e / f, edx = remainder
				 cmp edx, 0
				 je nextX //Not prime
				 add f, 1
				 jmp isYPrime

			 solutionFound :

	} printf("%d = %d + %d\n", sum, x, y); // Print the output.
	__asm{ // after the programme gets the a Goldbach’s conjecture number, this asm will go to the same loop 

		mov eax, sum // take the printed sum then put it into another loop for next Goldbach’s conjecture number.
			mov edx, x // take the printed x then put it into another loop for next prime number.
			jmp OuterLoop // jump to the outerloop.

		nextX : mov eax, sum
				mov edx, x
				jmp innerloop // jump the loop that generate another prime number.
			xout : // exit the loop
	}

	getchar();

}