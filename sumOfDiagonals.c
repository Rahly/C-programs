//sum of diagonals intersecting at point A(x,y)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** allocate(int height, int width);
void fillArray(int height, int width, int **array);
void freeArray(int width, int ***array);



int main(int argc, char *argv[]) {
	
	int height;
	int width;
	int Ax, Ay;

	
	printf("Podaj wymiary macierzy A (MxN)\n");
	scanf("%d%d", &height, &width);
	
	int **array = allocate(height, width);
	
	return 0;
}


int ** allocate(int height, int width){

	int widthCounter;
	int **array = NULL;
	
	array = (int**)calloc(height, sizeof(int));
		
		for(widthCounter = 0; widthCounter < width; widthCounter++){
			
			*(array + widthCounter) = (int*)calloc(width, sizeof(int));
		}

	return array;
}

void freeArray(int width, int ***array){
	
	int widthCounter;
	
	for(widthCounter = 0; widthCounter< width; widthCounter++){
		
		free(*((*array)+widthCounter));
	}
	
	free(*array);
	*array = NULL;
	
	return;
}

void fillArray(int height, int width, int **array){
	
	int widthCounter;
	int heightCounter;
	

	
	for(heightCounter = 0; heightCounter< height; heightCounter++){
		
		for(widthCounter = 0; widthCounter< width; widthCounter++){
			
			*(*(array+heightCounter)+widthCounter) = (1+rand()%10);
		}
	}
	
	return;
}

