// Khalid Almutairi 
// professor Richard Fox
// CSC 362 section 001
// Programme #6

/*
The program is to sort items having weights in bins. The bins are stored in array and items are linked to binsmain function
loops through items and inner loop look for bin to put item in then it sends it to insert function to insert item into the
bin and insert it with alphapatical order. In the end it's going to to call output function to output each bins and its
items with capacity size left in each bin after that, it's going to call destroyItems fumction to free data from the memory.
*/

#include <stdio.h>
#include <string.h>


void output(struct bin array[]); //A function to output the final result
void insert(struct bin *bin, struct item x);//A function to insert the item x into recieved bin.
void destroyItems(struct bin *array); // Destroy the items by deallocating nodes from the list.

struct item{
	char *name;			//Name of an item.
	double size;		//The weight size of an item.
	struct item *next;	//Next will take the next item
};

struct bin{
	double binw;		//Bin weight
	struct item *next;	//next will take the next item.
};


void main(){
	int bin;
	struct bin array[10];
	struct item x;
	int i;
	int NumberOfItems;
	int isInserted;


	//The name of items
		char* items[] = { "Small-dog", "Moose-skull", "Squirrel", "Mouse" , "Goldfish" , 
						  "Snake", "Human-finger" , "Pig-head" , "Eagle-feather" , "Shark-teeth" 
						  , "Camel-hump" , "Crocodile", "Elephant-tusk" , "Cat" , "Horse-manure" 
						  , "Monkey-hand" , "Octopus-eye" , "Sheep-coat" , "Bat" , "Chicken-wing"};
	
		/*
		//The name of items
	char* items[] = { "Operating Systems", "Computer Graphics", "The History of the Universe", "Discrete Mathematics", "Statistics",
		"English for Dummies", "American History 2000", "Computer Architecture", "C Programming", "Hitchhiker's Guide",
		"English-Minbari Dictionary", "Zen and the Art of Programming ", "The Joy of Cooking", "Cincinnati Yellow Pages",
		"Artificial Intelligence", "Business Programming: Why? ", "Heart of Darkness ", "The History of the Ohio State Buckeyes" };
	
	//The weight of items
	/*float sizes[] = { 0.75, 0.62, 0.27, 0.78, 0.41, 0.55, 0.20, 0.90, 0.21, 0.23, 0.42, 0.33, 0.56, 0.98, 0.32
					 , 0.12, 0.21, 0.82 };
	*/
	
	//The weight of items
		float sizes[] = { .63, .25, .41, .15, .06, .52, .09, .39, .02, .11, .24, .94, .63, .28, .04, .21, 
						  .05, .33, .42, .12 };
	
	

	for (bin = 0; bin < 10; bin++){  // For loop to set up the bin's weight and next to null.
		array[bin].binw = 1.0;
		array[bin].next = NULL;
	}

	NumberOfItems = sizeof(items) / sizeof(items[0]); //number of items

	for (i = 0; i < NumberOfItems; i++){//loop through each item
		x.name = items[i];				//item name
		x.size = sizes[i];				//item weight size
		x.next = NULL;
		
		isInserted = 1; //1 means the item was not inserted;
		bin = 0;
		while (bin < 10 && isInserted){
			if (array[bin].binw - x.size + 0.00001 >= 0){ //0.00001 for precision
				array[bin].binw = array[bin].binw - x.size;
				isInserted = 0;// The item is inserted
				bin--;// Since the item is inserted, subtract one to undo the work of the next bin++
			}
			bin++;
		}
		
		insert(&array[bin], x);		//insert item in that bin

	}

	output(array);		//output bins items
	destroyItems(array);//free bins items
	getchar();
}




// insert item X in the bin
void insert(struct bin *bin, struct item x){
	struct item *xHolder = (struct item *)malloc(sizeof(struct item));	// for the items.		
	struct item *temp;// for linked list in the bin

	*xHolder = x;	// item holder.
	int done = 0;	// boolean for item to be ordered in bin or not.

	if (bin->next == NULL) // if it's empty.
		bin->next = xHolder; // put the item

	else{ //if not
		temp = bin->next;	//temp is hte head of the list

		//if item name is smaller alphabatically, put it first
		if (strcmp(xHolder->name, temp->name) <= 0){
			xHolder->next = temp;
			bin->next = xHolder;
		}

		//if not, find the right place
		else{
			while (!done){
				// in case greater:
				if (strcmp(xHolder->name, temp->name) > 0){
					//if next null put item
					if (temp->next == NULL) {
						temp->next = xHolder;
						done = 1;
					}
					//if not, check the next and put it if smaller
					else if (strcmp(temp->next->name, xHolder->name) > 0){
						xHolder->next = temp->next;
						temp->next = xHolder;
						done = 1;

					}
				}
				//not greater, continue 

				temp = temp->next;

			}


		}

	}

}
// Destroy the items by deallocating nodes from the list.
void destroyItems(struct bin *array)
{
	struct item *temp;							// points to current node to be deallocated
	int i;
	for (i = 0; i < 10; i++){
		while (array[i].next != NULL)
		{
			temp = array[i].next;				// temp point to the current
			array[i].next = array[i].next->next;// move to next
			free(temp);							//remove the current by temp pointer
		}
	}
}

// The output function.
void output(struct bin array[])
{
	int used = 0;	// This variable to calculate number of used bin.
	struct item *temp;
	int i;

	for (i = 0; i < 10; i++){
		if (array[i].binw < 1) {// if < 1 increased number of used
			used = used + 1;
			temp = array[i].next; //point to the first item
			printf("Bin %i: ", i + 1);//output bin number	
			while (temp != NULL){	//output items		
				printf("%s %0.2f ", temp->name, temp->size);
				temp = temp->next;
			}
			// print capacity size remaining
			printf("Bin's weight left is %2.2f\n\n", array[i].binw);

		}
	}
	//output number of used
	printf("Number of used bin is %i", used);
}
