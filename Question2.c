#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;
	/*write your implementation here*/
	int size; //declare size variable

    FILE *input_file = fopen(filename, "r"); //open file and assign it to *input_file

    if (input_file == NULL) {
        printf("ERROR: COULD NOT OPEN FILE\n"); //if file is null, then print error message
        exit(1);
    }

    fscanf(input_file, "%d", &size); //assign the size pointer to the number of students, which is given by the first entry
    *sizePtr = size;

    class_list = calloc(size, sizeof(student*)); //allocate memory using calloc() function with the size of the student structure

    int i; //declare counter variable i

    for (i=0; i<size; i++) {
        class_list[i] = calloc(1, sizeof(student)); //assign a given entry memory to place student ID number, first, and last names
        fscanf(input_file, "%d", &class_list[i] -> student_id);

        fscanf(input_file, "%s", class_list[i] -> first_name);

        fscanf(input_file, "%s", class_list[i] -> last_name);
    }

    fclose(input_file); //close the file

    /* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	
	/*write your implementation here and update the return accordingly*/
	int i, in=-1; //declare counter i, and assign variable "in" to -1

	for (i=0; i<size; i++) {
	    if (list[i] -> student_id == idNo){ //asks if the ID number is equal to the input ID number
	        in = i; //only return the index provided the student ID matches idNo
	        break;
	    }
	}

	return in; //in will return -1 if there is no student ID match
}

void input_grades(char *filename, student **list, int size)
{
	/*write your implementation here*/
    int i, index, ID; //declare index and ID variables, as well as the counter i
    FILE *input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("ERROR: COULD NOT OPEN FILE\n"); //if file is null, then print error message
        exit(1);
    }

    for (i=0; i<size; i++) { //loop iterates from 0 until i=size-1
        fscanf(input_file, "%d", &ID); //scan the input file and assign it to the variable ID
        index = find (ID, list, size); //use the find function, inputing the ID found in the line above

        if (index != -1) { //only executes code block if the ID number exists
            fscanf(input_file, "%d", &(list[index]->project1_grade)); //assign project 1 grade
            fscanf(input_file, "%d", &(list[index]->project2_grade)); //assign project 2 grade
        }
    }

    fclose(input_file); //close file!

}

void compute_final_course_grades(student **list, int size)
{
	/*write your implementation here*/

	int i; //declare counter i
	for (i=0; i<size; i++) { //for loop iterates from 0 until i=size-1
	    // list[i] -> final_grade = ((double)list[i]-> project1_grade + (double)list[i]-> project2_grade)/2.0;
	    list[i] -> final_grade = (float)(list[i]->project1_grade + list[i]->project2_grade)/2.0; //calculate final grade
	}

}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/
    int i; //declare counter i
    FILE *output_file = fopen(filename, "w"); //make a function to write to

    fprintf(output_file, "%d\n", size);
    for (i=0; i<size; i++){ //for loop iterates from 0 until i=size-1
        fprintf(output_file, "%d\t%f\n", list[i]->student_id, list[i]->final_grade); //assign final grade with associated student ID number
    }

    fclose(output_file); //close file

}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int j; //declare counter j
	int scannedID_position = find(idNo, list, *sizePtr); //use find function, passing inputed idNo, list, and pointer

	if (scannedID_position == -1) {
	    printf("Student with ID of %d was not found in the class list \n", idNo); //print message if student does not exist
	}

	else {
	    free(list[scannedID_position]); //deallocate the memory for that student
	    *sizePtr = *sizePtr - 1; //decrease *sizePtr by 1

	    for (j=scannedID_position; j<*sizePtr; j++) {
	        list[j] = list[j+1];
	    }
	}
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/

	for (int i=0; i<*sizePtr; i++) { //declare counter variable i that iterates until the size
	    free(list[i]); //deallocate the memory using free()
	}
	*sizePtr=0;
}

/*
void print_list(student **list, int *sizePtr){
	for(int i=0; i<*sizePtr; i++){
		printf("ID: %d, NAME: %s %s\n", list[i]->student_id, list[i]->first_name, list[i]->last_name);
	}
	printf("\n");
}
*/



