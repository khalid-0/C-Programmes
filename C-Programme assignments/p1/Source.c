/*
Khalid Almutairi
Dr. Richard Fox
CSC 362 section 001
Programme #1

The programme will read character by character from the a text file till the end of the file then goes to a while loop. In every rotation the
loop will check if it's conatins the one of the controling letters q, z or x then store it in a temporary variable "last" after checking if it's
digit, then put in another while loop that will skip character by decrement the number of skipping character. Too check for charcter 'z' and 'x'
is the same algorthim of 'q' but we put the punctuation character in a second varialble call 'secondlast'. The programe will make sure that every
rotation the variable last and secondlast will be empty becuase We don't need what the last character we read was.

*/


#include <stdio.h>
#include <ctype.h>

int main()
{

	FILE *fp; //a pointer to open a text file.
	char c, last, secondlast; // c to store first character last to store last and second last are use to store later in the while loop
	double percent_decrease; // a variable to calculate the percentage of decreasing characters 
	int i, number_of_codes, input_character, output_character = 0;// A variable to count the number of coded codes and a variable to count the number of decoded codes.

	fp = fopen("p1-in1.txt", "r");  // a function to read the text file in the same directory of the source.c file.
	number_of_codes = 0; // initialize to 0 for counting the number of codes 
	input_character = 0; // initialize to 0 for counting the total number of char in the file

	last = 0;
	secondlast = 0;

	while ((c = getc(fp)) != EOF) // This loop will store all the character in the text file to the variable c until the end of file.
	{
		input_character++; // increment by one in every character pass.
		if (c == 'q' || c == 'Q' || c == 'z' || c == 'Z' || c == 'x' || c == 'X')  // if the character is one of the controling character then store it in last variable to use it later.
			last = c;
		else if (isdigit(c) && last != ' ' && (last == 'q' || last == 'Q')) 
		{
			i = (int)c - 48; // to convert the charater digit to integer so we can put it in a while loop that will skip the character
			number_of_codes++; // increment by one in every codes that pass on.
			input_character += i; // increment the character by one plus the converted number.
			while (i > 0 && getc(fp) != EOF) // This while loop will skip a character by i number so every rotation we use getc() until i become 0
			{
				i--;
			}
			last = ' ';
		}
		else if (last == 'q' || last == 'Q')
		{
			printf("%c%c", last, c);
			output_character += 2; //Add two to the output char counter becuse we printed the var lastand c
			last = ' '; //We don't care what the last char we read was
		}
		else if (ispunct(c) && last != ' ' && (last == 'z' || last == 'Z' || last == 'x' || last == 'X'))
			secondlast = c; //Save it, so we can check the next char
		else if (isdigit(c) && secondlast != ' ' && ispunct(secondlast) && last != ' ' && (last == 'z' || last == 'Z' || last == 'x' || last == 'X'))
		{
			i = (int)c - 48; // to convert the charater digit to integer so we can put it in a while loop that will skip the character
			input_character += i;
			number_of_codes++;
			while (i > 0 && getc(fp) != EOF) // This while loop will skip a character by i number so every rotation we use getc() until i become 0
				i--;
			last = ' '; //We don't need what the last char we read was
			secondlast = ' '; //We don't need what the second last char we read was
		}
		else if (last != ' ' && (last == 'z' || last == 'Z' || last == 'x' || last == 'X'))
		{
			printf("%c%c", last, c);
			output_character += 2; //Add two to the output char counter becuse we printed the var last and c
			last = ' ';
		}
		else if (secondlast != ' ' && ispunct(secondlast) && last != ' ' && (c == 'z' || c == 'Z' || c == 'x' || c == 'X'))
		{
			printf("%c%c%c", last, secondlast, c); // print the three coded characters.
			output_character += 3; //Add three to the output char counter becuse we printed the var last, secondlast and c
			last = ' ';
			secondlast = ' ';
		}
		else
		{
			printf("%c", c);
			output_character++; //Add one to the output char counter becuse we printed the var c
			last = ' ';
			secondlast = ' ';
		}

	}

	percent_decrease = 100 * ((double)(input_character - output_character) / input_character); // to claculate the percentage of decreasing
	printf("\nPercent decrease: %.2f%%\n", percent_decrease); // print the decreasing percentage rounded by two.
	printf("\nNumber of codes: %d\n", number_of_codes); // print the number of coded characters.
	fclose(fp);  // close the text file.

	getchar(); // to keep the window open.


}
