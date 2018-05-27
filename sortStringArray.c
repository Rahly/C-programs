#include <stdio.h>
#include <stdlib.h>

#define stringLength 100

char **allocate (int quantity);
void freeAllocate(int quantity, char ***stringArray);
void showArray(int quantity, char **stringArray);

int main(int argc, char *argv[]) {
	
	int quantity;
	
	printf("Ile napisow chcesz wprowadzic? ");
	scanf("%d", &quantity);
	
	char **stringArray = allocate(quantity);
	
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
	int lengthCounter;
	
	for(quantityCounter = 0; quantityCounter< quantity; quantityCounter++){
		
		printf("\n");
		
		for(lengthCounter = 0; lengthCounter< stringLength; lengthCounter++){
		
			printf("%s",  *(*(stringArray+quantityCounter)+lengthCounter));
		}	
	}
	
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

