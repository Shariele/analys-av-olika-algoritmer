#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BILLION 1E9 
#define TRUE 1
#define FALSE 0

// typedef void (*functionType)()()

// call this function to start a nanosecond-resolution timer
struct timespec timerStart(){
    struct timespec start;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    return start;
}

// call this function to end a timer, returning nanoseconds elapsed as a long
double timerEnd(struct timespec start){
    struct timespec end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    double diff = (double)(((end.tv_sec - start.tv_sec)*BILLION) + (end.tv_nsec - start.tv_nsec));
    return diff;
}

// Cred till http://www.ritambhara.in/optimized-bubble-sort-algorithm/ för en optimerad variant av bubblesort.
static double bBubbelSort(int *buff, int size){
	int temp, i, n, swapped;
	double sum;

	// printf("Time: %f\n", sum);
	// Start clock, sort and stop
	// result1 = clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

	struct timespec startTime = timerStart();
	for(i = 0; i < size; i++){
		swapped = FALSE;

		for(n = 0; n < size-i; n++){
			if(buff[n] > buff[n+1]){

				// swap
				temp = buff[n+1];
				buff[n+1] = buff[n];
				buff[n] = temp;
				swapped = TRUE;
			}
		}
		if(!swapped){
			break;
		}
	}
	sum = timerEnd(startTime);

	for(i = 0; i < size; i++){
		printf("%d\n", buff[i]);
	}

	printf("Time taken (nanoseconds): %f\n", sum);


	// printf("Result: %i\n", result1);
	// printf("Result: %i\n", result2);
	// printf("End - sec: %lld\n", end.tv_sec);
	// printf("End - nsec: %ld\n", end.tv_nsec);
	// printf("Start - sec: %lld\n", start.tv_sec);
	// printf("Start - nsec: %ld\n", start.tv_nsec);

	// // Get time in nanoseconds 
	// sum = (end.tv_nsec + start.tv_nsec);
	// printf("Time: %f\n", sum);
	return sum;
}

// Cred till http://www.geeksforgeeks.org/insertion-sort/
static long double bInsertionSort(int *buff, int size){
    int i, key, n, k;
    long double sum;
	struct timespec start, end;
	
	// Start clock, sort and stop
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    for (i = 1; i < size; i++){
        key = buff[i];
        n = (i-1);
 
        while (n >= 0 && buff[n] > key){
			buff[n+1] = buff[n];
			n = (n-1);
		}
		buff[n+1] = key;
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

	// Get time in nanoseconds
	return sum = (double)((end.tv_sec - start.tv_sec)*BILLION) + (end.tv_nsec - start.tv_nsec);
}

static int partition(int *buff, int a, int b) {
	int pivot, lower, upper, temp;
	pivot = buff[a];
	lower = a + 1;
	upper = b;
	do {
		while (buff[lower] <= pivot && lower <= upper) lower = lower + 1;
		while (buff[upper] > pivot && lower <= upper) upper = upper - 1;

		if (lower <= upper) {
			temp = buff[lower];
			buff[lower] = buff[upper];
			buff[upper] = temp;
			lower = lower + 1;
			upper = upper - 1;
		}
	}while (lower <= upper);

	temp = buff[upper];
	buff[upper] = buff[a];
	buff[a] = temp;

	return upper;
}

static void bQuickSort(int *buff, int a, int b) {
	int k;
	
	if (a < b) {
		k = partition(buff, a, b);
		bQuickSort(buff, a, k-1);
		bQuickSort(buff, k+1, b);
	}
}

static void bLinearSearch(int *buff, int size, int searchValue){
	int i;
	for(i = 0; i < size; i++){
		if(searchValue == buff[i]){
			// printf("Found at element: %d\n", i);
			break;							//if value found, don't search anymore.
		}
	}
}

static void bBinarySearch(int *buff, int size, int searchValue){
	int found = 0, low = (size-size), high = size, mid = (size/2);

	while(found != 1 && high >= low){
		mid = low + (high - low) / 2;	/*Beräknar en ny mitt-siffra varje gång beroende på om talet var mindre eller större i jämförelsen.*/

		if(searchValue < buff[mid])	/*Om det sökta talet är mindre än mitt talet, då blir det högsta talet mitten talet minus 1*/
			high = mid - 1;	
		else if(searchValue > buff[mid])	/*Om det sökta talet är större än mitt talet så blir det lägsta talet mitten talet plus 1*/
			low = mid + 1; 
		else
			found = 1;
	}
}

static void bCreateAscending(int *buff, int size){
	int i;
	for (i = 0; i < size; i++)
		buff[i] = i;
}

static void bCreateDescending(int *buff, int size){
	int i;
	for (i = size; i > 0; i--)
		buff[(size - i)] = i;
}

static void bCreateRandom(int *buff, int size){
	int i;
	for (i = 0; i < size; i++)
		buff[i] = rand() % size;
}

//(*f) = what buff, (*g) = sorting func, random = TRUE - srand will run.
static double long bRunSortAlgorithms(void (*f)(int*, int), double (*g)(int*, int), int size){
	long double sum;
	int buff[size], i;

	// Create numbers
	(*f)(buff, size);
	// for(i = 0; i < size; i++){
	// 	printf("%d \n", buff[i]);
	// }
	sum = (*g)(buff, size);
	// for(i = 0; i < size; i++){
	// 	printf("%d \n", buff[i]);
	// }
	// printf("Time: %Lf\n", sum);
	return sum;
}

//(*f) = what buff, (*g) = search func, a searchValue
static double long bRunSearchAlgorithms(void (*f)(int*, int), void (*g)(int*, int, int), int size, int searchValue){
	struct timespec start, end;
	long double sum;
	int buff[size], i;

	// Create numbers
	(*f)(buff, size);

	// Start clock, sort and stop
	clock_gettime(CLOCK_REALTIME, &start);
	(*g)(buff, size, searchValue);
	clock_gettime(CLOCK_REALTIME, &end);

	// Get time in seconds?
	sum = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec)/ BILLION);
	
	return sum;
}

/*
****
****Bubblesort
****
*/
// Best Case
long double bebsbc(int size){
	long double sum;
	sum = bRunSortAlgorithms(bCreateAscending, bBubbelSort, size);

	return sum;
}

// Worst case
double bebswc(int size){
	double sum;
	sum = bRunSortAlgorithms(bCreateDescending, bBubbelSort, size);

	return sum;
}

// Random Case
double bebsrc(int size){
	long double sum;
	// printf("%d\n", size);
	sum = bRunSortAlgorithms(bCreateRandom, bBubbelSort, size);
	
	return sum;
}

/*
****
****Insertionsort
****
*/
// Best Case
long double beisbc(int size){
	long double sum;
	sum = bRunSortAlgorithms(bCreateAscending, bInsertionSort, size);
	
	return sum;
}

// Worst case
long double beiswc(int size){
	long double sum;
	sum = bRunSortAlgorithms(bCreateDescending, bInsertionSort, size);
	
	return sum;
}

// Random case
long double beisrc(int size){
	long double sum;
	sum = bRunSortAlgorithms(bCreateRandom, bInsertionSort, size);
	
	return sum;
}
/*
****
****Quicksort
****
*/
// Best Case
long double beqsbc(int size){
	struct timespec start, end;
	int buff[size], i;
	double sum;
	srand(time(NULL));

	// Create random numbers
	bCreateRandom(buff, size);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	bQuickSort(buff, 0, size);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);	

	sum = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec)/ BILLION);
	
	return sum;		//TO DO
}
// Worst Case
long double beqswc(int size){
	struct timespec start, end;
	int buff[size], i;
	double sum;

	// Create random numbers
	bCreateAscending(buff, size);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	bQuickSort(buff, 0, size);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);	

	sum = (double)((end.tv_sec - start.tv_sec)*BILLION) + (end.tv_nsec - start.tv_nsec);
	
	return sum;		//TO DO
}
// Random Case
long double beqsrc(int size){
	struct timespec start, end;
	int buff[size], i;
	long double sum;
	srand(time(NULL));

	// Create random numbers
	bCreateRandom(buff, size);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	bQuickSort(buff, 0, size);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);		

	sum = (double)((end.tv_sec - start.tv_sec)*BILLION + (end.tv_nsec - start.tv_nsec));
	
	return sum;
}


/*
****
****Linear Search
****
*/
// Best Case
long double belsbc(int size){
	long double sum;
	// Searchvalue is 0 becasue we know 0 will be the first value in an ascending created array.
	sum = bRunSearchAlgorithms(bCreateAscending, bLinearSearch, size, (size-size));

	return sum;
}

// Worst case
long double belswc(int size){
	long double sum;
	// size -1 because numbers are created from 0 -> size-1
	sum = bRunSearchAlgorithms(bCreateAscending, bLinearSearch, size, (size-1));

	return sum;
}

// Random case
long double belsrc(int size){
	long double sum;
	// printf("Meep\n");
	// size -1 because numbers are created from 0 -> size-1
	// searchvalue is 0 as it will be randomized at function
	sum = bRunSearchAlgorithms(bCreateRandom, bLinearSearch, size, (rand() % size));

	return sum;
}

/*
****
****Binary Search
****
*/
// Best Case
long double bebisbc(int size){
	long double sum;
	// Best case should effectively be when the searched value is at first split in binary search
	sum = bRunSearchAlgorithms(bCreateAscending, bBinarySearch, size, (size/2));

	return sum;
}

// Worst case
long double bebiswc(int size){
	long double sum;
	// Worst case should be when the binary search has to reach the furthest down the tree to find the value
	sum = bRunSearchAlgorithms(bCreateAscending, bLinearSearch, size, (size-size));

	return sum;
}

// Random case
long double bebisrc(int size){
	long double sum;
	// printf("Meep\n");
	// Randomizes a search value
	sum = bRunSearchAlgorithms(bCreateAscending, bBinarySearch, size, (rand() % size));

	return sum;
}