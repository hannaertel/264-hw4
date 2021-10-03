// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
	// count the number of integers in the file
	// Please notice that if a file contains
	// 124 378 -56
	// There are three integers: 124, 378, -56
	// DO NOT count individual character '1', '2', '4' ...
	//
	// If fopen fails, return -1
	FILE * finput;
	finput = fopen(filename, "r");
	if(finput == NULL) {
		return(-1);
	}

	//int newElem = 0;
	int totalElem;
	int num;
	while(!feof(finput)){
		fscanf(finput, "%d\n", &num); //do i need the &num after since we arent storing it
		//totalElem += newElem; 	
		totalElem += 1;
		
	}
	fclose(finput);
	return(totalElem); 

	// remember to fclose if fopen succeeds
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
	// if fopen fails, return false
	// read integers from the file.
	FILE * fp;
	fp = fopen(filename, "r");
	if(fp == NULL) {
		return false;
	} 
	
	int count = 0;
//	int newElem = 0;

	while(!feof(fp)) {
		fscanf(fp, "%d\n", &intArr[count]);
		count +=1; 	
		

	}
	fclose(fp);
	
	if(count != size) {
		return false;
	}
	
	return true;
	
	
	// if the number of integers is different from size (too
	// few or too many) return false
	// 
	// if everything is fine, fclose and return true

//	return true; should i comment this out or no???
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
	// needed by qsort
	//
	// return an integer less than, equal to, or greater than zero if
	// the first argument is considered to be respectively less than,
	// equal to, or greater than the second.
	
	int a1 = 0;
	int a2 = 0;
	a1 = *(int*) p1;
	a2 = *(int*) p2;
	if(a1 < a2){
		return -1;
	}

	else if (a1 == a2) {
		return 0;
	}

	else{
		return 1;
	}

}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
	// if fopen fails, return false
	// write integers to the file.
	// one integer per line
	
	FILE * foutput;
	foutput = fopen(filename, "w");
	if(foutput == NULL) {
		return false;
	}	
	
	int count = 0;
	for(count = 0; count < size; count += 1) {
		fprintf(foutput, "%d\n", intArr[count]);
	

	}

 	fclose(foutput);
	return true; 	

	// fclose and return true
}
#endif

