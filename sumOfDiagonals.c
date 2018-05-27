//sum of diagonals intersecting at point A(x,y)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** allocate(int height, int width);
void fillArray(int height, int width, int **array);
int countDiagonalSum(int height, int width, int Ax, int Ay, int **array);
void showArray(int height, int width, int **array);
void freeArray(int height, int ***array);



int main(int argc, char *argv[]) {
	
	int height;
	int width;
	int Ax, Ay;
	int flag = 0;

	
	printf("Podaj wymiary macierzy A (MxN)\n");
	scanf("%d%d", &height, &width);
	
	int **array = allocate(height, width);
	
	do{
		printf("Podaj wspolrzedne punktu przeciecia diagonalnych (liczone od 0): ");
		scanf("%d%d", &Ax, &Ay);
		
		if(Ax < width && Ax >= 0 && Ay < height && Ay >= 0)
			flag = 1;
		
	}while(flag == 0);
	
	fillArray(height, width, array);
	showArray(height, width, array);

	printf("Suma diagonalnych przecinajacych sie w punkcie A wynosi: %d",  	countDiagonalSum(height, width, Ax, Ay, array));
	freeArray(width, &array);
	
	return 0;
}


int ** allocate(int height, int width){

	int heightCounter;
	int **array = NULL;
	
	array = (int**)calloc(height, sizeof(int*));
		
		for(heightCounter = 0; heightCounter < height; heightCounter++){
			
			*(array + heightCounter) = (int*)calloc(width, sizeof(int));
		}

	return array;
}

void freeArray(int height, int ***array){
	
	int heightCounter;
	
	for(heightCounter = 0; heightCounter< width; heightCounter++){
		
		free(*((*array)+heightCounter));
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

int countDiagonalSum(int height, int width, int Ax, int Ay, int **array){
	
	int widthCounter;
	int heightCounter;
	int sum = 0;
	
	for(heightCounter = 0; heightCounter< height; heightCounter++){
		
		for(widthCounter = 0; widthCounter< width; widthCounter++){
			
			if((heightCounter + widthCounter == Ax + Ay) || heightCounter - widthCounter == Ax - Ay)
				sum = sum + 	*(*(array+heightCounter)+widthCounter);
		}
	}
	
	return sum;
}


void showArray(int height, int width, int **array){
	
	
	
		int widthCounter;
	int heightCounter;
	
		for(heightCounter = 0; heightCounter< height; heightCounter++){
		
			printf("\n");
		for(widthCounter = 0; widthCounter< width; widthCounter++){
			
				printf("%d	", *(*(array+heightCounter)+widthCounter));
		}
	}
	
}
