/* Assignment 3 - Question 1 - stats.c
   Authors: John Hebb & Matthew Souter
   Date: Monday, November 4th, 2018
   Description: This program takes in 7 values and creates 3 different threads, one to find the average of the numbers, one to find the max value and one to find the min value
   Github Link- https://github.com/John-Hebb/OS_Assignment3/blob/master/stats.c
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 
#include <string.h>

//Global variables that hold the calculated stats of the numbers
double average_num;
int max_num = 0;
int min_num = 1000000;//this is a big number so that it is guaranteed to get overwritten by a smaller one that is entered.


//Average function
void *average(void *arg) 
{ 
	int *val_p = (int *) arg;//Getting the input from the command line array
	int val[7];//size of the array is 7
	size_t n = sizeof(val_p) - 1;//-1 because it takes the "./stats" as the varaible that would be taking up the first spot
	double sum = 0;
	
	for(int k = 0; k <= n; k++){
       sum = sum + val_p[k];//Adding up the numbers as it runs through all the input
    }//end of for loop

	average_num = sum/n;//calculating the average of the numbers
 
	return NULL; 
} //end of average function



//Max function
void *max(void *arg) 
{ 
	int *val_p = (int *) arg;//Getting the input from the command line array
	int val[7];//size of the array is 7
	size_t n = sizeof(val_p) - 1;//-1 because it takes the "./stats" as the varaible that would be taking up the first spot

	for (int k = 1; k <= n; k++)//starts at 1 becasue 0 is the "./Q1" value
	{
	    	
		if (val_p[k] > max_num)
		{
			max_num = val_p[k]; //Calculating the max number
		}//end of if
	}//end of for loop

	return NULL; 		
}//end of max function



//Min function
void *min(void *arg) 
{ 
	int *val_p = (int *) arg;//Getting the input from the command line array
	int val[7];//size of the array is 7
	size_t n = sizeof(val_p) - 1;//-1 because it takes the "./stats" as the varaible that would be taking up the first spot

	for (int k = 1; k <= n; k++)
	{
	  	
		if (val_p[k] < min_num)
		{
			min_num = val_p[k];  //Calculating the min number
		}//end of if
	}//end of for loop
	
	return NULL; 
} //end of min function



//Main
int main(int argc, char*argv[]) 
{ 

//This if statement is checking to see if there were 8 arguments entered into the commandline	
	if (argc != 8){
		printf("Usage: ./stats <Number 1> <Number 2> <Number 3> <Number 4> <Number 5> <Number 6> <Number 7>\n");
	exit(1);
	}	

	int temp,temparray[argc],i;//Creating the arrays

	int array[1000];//Creating the array that the commandline input is saved into

	for(int i=1;i<argc;i++)
		{
			temparray[i]=atoi(argv[i]);//Actually putting the numbers into the array that is passed up the the threads
			array[i]=atoi(argv[i]);
		}

	//Defining the threads
	pthread_t average_thread_id;
	pthread_t max_thread_id; 
	pthread_t min_thread_id; 
	
	pthread_create(&average_thread_id, NULL, average, array); 
	pthread_join(average_thread_id, NULL); 
	
	/*comment for the above code:
	When creating the pthread,
	First variable is a pointer to thread_id which is set by this function.
	Second argument specifies attributes. If the value is NULL, then default attributes shall be used.
	Third argument is name of function to be executed for the thread to be created.
	Fourth argument is used to pass arguments to the function, myThreadFun.
	*/

	//This code has the same comment as above
	pthread_create(&max_thread_id, NULL, max, array); 
	pthread_join(max_thread_id, NULL); 
	
	pthread_create(&min_thread_id, NULL, min, array); 
	pthread_join(min_thread_id, NULL); 
	
	//Printing out the content after it has been calculated
	printf("Assignment 3 Question 1\n\n"); 
	printf("=============\n");
	printf("Average is: %.2f \n", average_num); 
	printf("Max is: %d \n", max_num); 
	printf("Min is: %d \n", min_num); 
	printf("=============\n\n");
	printf("Program complete \n"); 
	exit(0); 
}

