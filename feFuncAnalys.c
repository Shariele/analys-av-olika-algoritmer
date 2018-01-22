#include "feFuncAnalys.h"
#include "beFuncAnalys.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static void printTable(long double *buff, char *name){
	int i, num = NUMBERS, milliPrecision = 1000; 

	printf(" ------------------------------------------------------------------\n");
	printf(" %s\n", name);
	printf(" --------------------------------------------------------------------\n");
	printf(" ---      N     Time(T)          T/N          T/N^2         T/N^3\n");
	for(i = 0; i < 5; i++){
		if(i == 4){
			printf(" ---  %d    %d      %e    %Le      %Le\n", num,  (((int)buff[i])/milliPrecision), (double)(((int)buff[i])/num), (buff[i]/(num*num)), (buff[i]/(num*num*num)));
		}else{
			printf(" ---   %d    %d      %e    %Le      %Le\n", num,  (((int)buff[i])/milliPrecision), (double)(((int)buff[i])/num), (buff[i]/(num*num)), (buff[i]/(num*num*num)));
		}
		
		num = num*2;
	}
	printf(" ------------------------------------------------------------------\n\n");	
}
// Recieve function and name.
static void fRunTests(long double (*f)(int), char *name){
	int i, num = NUMBERS, n;
	double arr[5], arr2[8], sum = 0;
	// char name[] = {'B', 'u', 'b', 'b', 'l', 'e', 's', 'o', 'r', 't', ' ', '-', ' ', 'B', 'e', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	
	for(i = 0; i < 5; i++){ 
		arr[i] = (*f)(num);
		num = num*2;
	}
	// (*f)(num);
	printTable(arr, name);								//Print the results
}

/*
****
****	Binary Search
****
*/
// Binary Search - Best case
void febisbc(){
	char name[] = {'B', 'i', 'n', 'a', 'r', 'y', ' ', 's', 'e', 'a', 'r', 'c', 'h', ' ', '-', ' ', 'B', 'e', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(bebisbc, name);
}

// Binary Search - Worst case
void febiswc(){
	char name[] = {'B', 'i', 'n', 'a', 'r', 'y', ' ', 's', 'e', 'a', 'r', 'c', 'h', ' ', '-', ' ', 'W', 'o', 'r', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(bebiswc, name);
}

// Binary Search - Random case
void febisrc(){
	srand(time(NULL));
	char name[] = {'B', 'i', 'n', 'a', 'r', 'y', ' ', 's', 'e', 'a', 'r', 'c', 'h', ' ', '-', ' ', 'R', 'a', 'n', 'd', 'o', 'm', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(bebisrc, name);
}

/*
****
****	Linear Search
****
*/
// Linear Search - Best case
void felsbc(){
	char name[] = {'L', 'i', 'n', 'e', 'a', 'r', ' ', 's', 'e', 'a', 'r', 'c', 'h', ' ', '-', ' ', 'B', 'e', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(belsbc, name);
}

// Linear Search - Worst case
void felswc(){
	char name[] = {'L', 'i', 'n', 'e', 'a', 'r', ' ', 's', 'e', 'a', 'r', 'c', 'h', ' ', '-', ' ', 'W', 'o', 'r', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(belswc, name);
}

// Linear Search - Random case
void felsrc(){
	srand(time(NULL));
	char name[] = {'L', 'i', 'n', 'e', 'a', 'r', ' ', 's', 'e', 'a', 'r', 'c', 'h', ' ', '-', ' ', 'R', 'a', 'n', 'd', 'o', 'm', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(belsrc, name);
}

/*
****
****	Quicksort
****
*/
// Quicksort - Best case
void feqsbc(){
	char name[] = {'Q', 'u', 'i', 'c', 'k', 's', 'o', 'r', 't', ' ', '-', ' ', 'B', 'e', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	// fRunTests(beqsrc, name);		//Ändra
	printf("TO BE DONE\n");
}
// Quicksort - Worst case
void feqswc(){
	char name[] = {'Q', 'u', 'i', 'c', 'k', 's', 'o', 'r', 't', ' ', '-', ' ', 'W', 'o', 'r', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(beqswc, name);
}
// Quicksort - Random case
void feqsrc(){
	srand(time(NULL));
	char name[] = {'Q', 'u', 'i', 'c', 'k', 's', 'o', 'r', 't', ' ', '-', ' ', 'R', 'a', 'n', 'd', 'o', 'm', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(beqsrc, name);
}
/*
****
****	Insertionsort
****
*/
// Insertionsort - Best case
void feisbc(){
	char name[] = {'I', 'n', 's', 'e', 'r', 't', 'i', 'o', 'n', 's', 'o', 'r', 't', ' ', '-', ' ', 'B', 'e', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(beisbc, name);
}
// Insertionsort - Worst case
void feiswc(){
	char name[] = {'I', 'n', 's', 'e', 'r', 't', 'i', 'o', 'n', 's', 'o', 'r', 't', ' ', '-', ' ', 'W', 'o', 'r', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(beiswc, name);
}
// Insertionsort - Random case
void feisrc(){
	srand(time(NULL));
	char name[] = {'I', 'n', 's', 'e', 'r', 't', 'i', 'o', 'n', 's', 'o', 'r', 't', ' ', '-', ' ', 'R', 'a', 'n', 'd', 'o', 'm', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(beisrc, name);
}
/*
****
****	Bubblesort
****
*/
// Best Case
void febsbc(){
	char name[] = {'B', 'u', 'b', 'b', 'l', 'e', 's', 'o', 'r', 't', ' ', '-', ' ', 'B', 'e', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(bebsbc, name);
	// double sum;
	// sum = bebsbc(16384);
}

// Worst case
void febswc(){
	char name[] = {'B', 'u', 'b', 'b', 'l', 'e', 's', 'o', 'r', 't', ' ', '-', ' ', 'W', 'o', 'r', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
	fRunTests(bebswc, name);
}

// Random case
void febsrc(){
	srand(time(NULL));
	char name[] = {'B', 'u', 'b', 'b', 'l', 'e', 's', 'o', 'r', 't', ' ', '-', ' ', 'R', 'a', 'n', 'd', 'o', 'm', ' ', 'c', 'a', 's', 'e', '\0'};
	double sum;
	// fRunTests(bebsrc, name);
	// sum = bebsrc(16384);
}

void feRunAllTests(){
	srand(time(NULL));
	// Bubble
	febsbc();
	febswc();
	febsrc();

	// Insertion
	feisbc();
	feiswc();
	feisrc();

	// Quicksort
	feqsbc();
	feqswc();
	feqsrc();

	felsbc();
	felswc();
	felsrc();
}