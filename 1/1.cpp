#include <stdio.h>
#include <stdbool.h>
#define SIZE 10


int todec(int array[SIZE], int temp, int counter, int notation);

int fromdec(int array[SIZE], int number, int temp, int counter, int notation);


int main(void) {
	
	int chooseaction;
	printf("Choose the action (convert from decimal - 1, to decimal - 2) : ");
	scanf_s("%d", &chooseaction);
	
	bool fromdecimal = (chooseaction == 1) ? true : false;

	int notation;
	printf("Choose the notation (3 - ternary, 4 - fourfold, 5 - fivefold) : ");
	scanf_s("%d", &notation);
	
	int number;
	printf("Enter the three-digit number : ");
	scanf_s("%d", &number);
	
	int counter = 0;
	int temp = number;
	int array[SIZE] = { 0 };

	if (fromdecimal) {
		
		counter = fromdec(array, number, temp, counter, notation);
		
		printf("The result is: ");
		for (int i = counter - 1; i >= 0; i--)
			printf("%d ", array[i]);
		
	} else {
		for (int i = 0; number != 0; i++, counter++) {
			temp = number % 10;
			array[i] = temp;
			number /= 10;
		}
		printf("The result is %d", todec(array, temp, counter, notation));
	}
	return 0;
}

int fromdec(int array[SIZE], int number, int temp, int counter, int notation) {
	for (int i = 0; number != 0; i++, counter++) {
		number /= notation;
		array[i] = temp - (number * notation);
		temp /= notation;
	}
	return counter;
}

int todec(int array[SIZE], int temp, int counter, int notation) {
	int sum = 0;
	for (int i = 0, temp = 1; i < counter; i++) {
		for (int j = 1; j <= i; j++)
			temp *= notation;

		array[i] *= temp;
		sum += array[i];
	}
	return sum;
}
