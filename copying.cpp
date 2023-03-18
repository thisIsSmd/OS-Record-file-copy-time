/*
EUID: smm0705
Name: Mohammed Mudasir Shaik
Student Id: 11608752

Program: C Program to record copying time of file from A to B in the range 1KB to 100 MB (doubling in each step) 
*/
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>

int main()
{
	int maxSize, minSize, loop, index = 0;
	FILE *fptr1, *fptr2;
	char filename_1[100], filename_2[100], c;
	
	printf("Enter the filename to open for reading \n");
	scanf("%s", filename_1); //Source file name

	printf("Enter the filename to open for writing \n");
	scanf("%s", filename_2); //Destination file name
		
	printf("Enter the maximum file size:\n");
	scanf("%d", &maxSize); //max file size should be 104857600 bytes
	
	for(loop = 1024; loop <= maxSize; loop = loop * 2) //defining array size
	{
		index = index + 1;
	}
	
	float a[2][index + 1];
	index = 0;
	
	for (minSize = 1024; minSize <= maxSize; minSize = minSize * 2) 
	{
		 
		 int X = minSize;
		 printf("The file size we are transferring is: %d\n", X);
		 FILE *fp = fopen(filename_1, "w");
		 fseek(fp, X, SEEK_SET); //increasing the file size to twice in every iteration
		 fputc('\0', fp);
		 fclose(fp);		
		
		// Open one file for reading
		fptr1 = fopen(filename_1, "r");
		if (fptr1 == NULL)
		{
			printf("Cannot open file %s \n", filename_1);
			exit(0);
		}
	  
		// Open another file for writing
		fptr2 = fopen(filename_2, "w");
		
		//Start the clock to calculate the execution time
		clock_t begin = clock(); 
		
		// Read contents from file
		c = fgetc(fptr1);
		while (c != EOF)
		{
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}
		
		// here, do your time-consuming job 
		clock_t end = clock();
		
		double time_spent = (double)(end - begin)/ CLOCKS_PER_SEC;
		
		a[0][index] = minSize;
		a[1][index] = time_spent;		
		
		index = index + 1;
		
		printf("Time spent in transferring the file from A to B is: %f\n", time_spent);
		fclose(fptr1);
		fclose(fptr2); 
	}
	
	 	 FILE *fp = fopen(filename_1, "w");
		 fseek(fp, 104857600, SEEK_SET); //increasing the file size to twice in every iteration
		 fputc('\0', fp);
		 fclose(fp);	
		 
		 // Open one file for reading
		fptr1 = fopen(filename_1, "r");
		if (fptr1 == NULL)
		{
			printf("Cannot open file %s \n", filename_1);
			exit(0);
		}
	  
		// Open another file for writing
		fptr2 = fopen(filename_2, "w");
		
		//Start the clock to calculate the execution time
		clock_t begin = clock(); 
		
		// Read contents from file
		c = fgetc(fptr1);
		while (c != EOF)
		{
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}
		
		// here, do your time-consuming job 
		clock_t end = clock();
		
		double time_spent = (double)(end - begin)/ CLOCKS_PER_SEC;
		printf("The file size we are transferring is: %d\n", 104857600);
		printf("Time spent in transferring the file from A to B is: %f\n", time_spent);
		
		a[0][index] = 104857600;
		a[1][index] = time_spent;
		
		loop = 0;
		
		printf("File Size    CPU Time took to copy\n");
		for(loop = 0; loop < index + 1; loop++)
		{
			printf("%d      %f\n", (int)a[0][loop], a[1][loop]);
		}
		fclose(fptr1);
		fclose(fptr2); 
	
return 0;
}
