/*
merge-sort.cpp
Janner Conde
date: 2/3/2021
ECE 331

*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

#define ARRAYSIZE 16 

double* createRandomArray(int size)
{
	srand(time(NULL));

	double* Array;
	Array = new double[size];
	if (Array == nullptr)
	{
		std::cout << "Error: memory could not be allocated." << std::endl;
	}

	for (int i = 0; i < size; i++)
	{
		Array[i] = (double)rand() / (double)RAND_MAX;
	}

	return Array;
}

void printArray(double* array, int size)
{
	std::cout << "|";
	std::cout.precision(5);
	for (int i = 0; i < size; i++)
	{
		std::cout << std::fixed << array[i] << "|";
	}
	std::cout << std::endl;

	return;
}

/*
merge - 
Assumed:
start to midpoint is sorted
midpoint+1 to end is sorted
*/
void merge(double* array, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	double* L;
	L = new double[n1+1];
	double* R;
	R = new double[n2+1];

	if (L == nullptr || R == nullptr)
	{
		std::cout << "Error: memory could not be allocated." << std::endl;
	}

	for (int i = 0; i < n1; i++)
	{
		L[i] = array[p+i];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = array[q+1+i];
	}
	L[n1] = INFINITY;
	R[n2] = INFINITY;

	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
	}
}

double* mergeSort(double* array, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2; // floored due to int division

		mergeSort(array, p, q);
		mergeSort(array, q + 1, r);
		merge(array, p, q, r);

		// print merge step
		printArray(array, ARRAYSIZE);
	}

	return array;
}


int main(void)
{
	// create random array of ARRAYSIZE elements from (0..1)
	double* Array = createRandomArray(ARRAYSIZE);

	// print Initial Array
	std::cout << "Original Array: " << std::endl;
	printArray(Array, ARRAYSIZE);

	// Sort Array
	std::cout << "Sorting Steps: " << std::endl;
	mergeSort(Array, 0, ARRAYSIZE -  1);

	// Print end result
	std::cout << "Final Array: " << std::endl;
	printArray(Array, ARRAYSIZE);


	return 0;
}
