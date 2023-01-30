#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/

	int s1, s2, s3, i = 0, j = 0; //initialize string length variables and counter variables

	s1 = strlen(str1); //find length of strings
	s2 = strlen(str2);
	s3 = s1+s2+1; //assign added length to s3 variable

	z = malloc(s3); //allocate memory for z of length s3


	while(*(str1+i) != '\0') { //loop executes as long as the string is not equal to the null character
	    z[i] = *(str1+i); //assign z at i to string value
	    i++; //increase i increment
	}

	while(*(str2+j) != '\0') { //loop executes as long as the string is not equal to the null character
	    z[i] = *(str2+j);
	    i++; //increase i increment
	    j++; //increase j increment
	}

	z[i] = '\0'; //complete z with the null character

	/* finally, return the string*/
	return z;
	
}

