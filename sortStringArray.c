#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define stringLength 100

char **allocate (int quantity);
void freeAllocate(int quantity, char ***stringArray);
void showArray(int quantity, char **stringArray);
void fillArray(int quantity, char **stringArray);
int countLowercase(char *string);
void sortString(int quantity, char **stringArray);

int main(int argc, char *argv[]) {
	
	int quantity;
	
	printf("Ile napisow chcesz wprowadzic? ");
	scanf("%d", &quantity);
	
	char **stringArray = allocate(quantity);
	fillArray(quantity, stringArray);
	sortString(quantity, stringArray);
	showArray(quantity, stringArray);
	freeAllocate(quantity, &stringArray);
	
	return 0;
}

char **allocate (int quantity){
		
	int quantityCounter;
	char **array = NULL;
	
	array = (char**)calloc(quantity, sizeof(char*));
		
		for(quantityCounter = 0; quantityCounter < quantity; quantityCounter++){
			
			*(array + quantityCounter) = (char*)calloc(stringLength, sizeof(char));
		}

	return array;
}

void showArray(int quantity, char **stringArray){
	
	int quantityCounter;
	
	for(quantityCounter = 0; quantityCounter< quantity; quantityCounter++){
		
		printf("Napis nr %d: ", quantityCounter + 1);
		printf("%s\n",  stringArray[quantityCounter]);
		
	}
	
	return;
	
}

void freeAllocate(int quantity, char ***stringArray){
	
	int quantityCounter;
	
	for(quantityCounter = 0; quantityCounter< quantity; quantityCounter++){
		
				free(*((*stringArray)+quantityCounter));
	}
	
	free(*stringArray);
	*stringArray = NULL;
	
	return;
}

void fillArray(int quantity, char **stringArray){
	
	int quantityCounter;

	for(quantityCounter = 0; quantityCounter< quantity; quantityCounter++){
			
			printf("Podaj %d napis: ", quantityCounter+1);
			scanf("%s", stringArray[quantityCounter]);
	}

	return;
}

void sortString(int quantity, char **stringArray){
	
	int quantityCounter;
	int quantityCounter2;
	int lowercaseCounter = 0;
	int lowercaseCounter2 = 0;
	char tempArray[100];
		
	for(quantityCounter2 = 0; quantityCounter2< quantity-1; quantityCounter2++){
		
		for(quantityCounter = 0; quantityCounter< quantity-1; quantityCounter++){
				
				lowercaseCounter = countLowercase(stringArray[quantityCounter+1]);
				lowercaseCounter2 = countLowercase(stringArray[quantityCounter]);

				if(lowercaseCounter> lowercaseCounter2){
					
					strcpy(tempArray, stringArray[quantityCounter]);
					strcpy(	stringArray[quantityCounter], stringArray[quantityCounter+1]);
					strcpy(	stringArray[quantityCounter+1], tempArray);				
				}	
		}
	}
	
}

int countLowercase(char *string){
	
	int lowercaseCounter = 0;
	int counter;
	
	for(counter=0; string[counter] != '\0'; counter++)
		{
			if(islower(string[counter]))
				lowercaseCounter++;
		}
	
	return lowercaseCounter;
}

