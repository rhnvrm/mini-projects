/*
QUIZ PROGRAM BY ROHAN VERMA

Planning:

We will read from a file called questions.dat in which we will store the data in such a way where:

What is the capital of India?
Delhi
Mumbai
Bangalore
Kolkata

Here the first line is the question
second line contains the correct answer
the next three lines contains the incorrect answers

We will then display the questions till the eof is reached or till an incorrect answer is reached.



*/



#include <stdio.h>
#include <string.h>

FILE* fin;
char buffer[100]; //buffer to store what i scan from questions file


typedef struct {

	char question[100];
	char a[100];
	char b[100];
	char c[100];
	char d[100];
	unsigned int correct;

} Questions;

Questions q;


int main()
{

	fin = fopen("questions.dat", "r");

	//check if we had an error in opening the file
	if (NULL == fin)
    {
         printf("error in opening the question database");
         return (-1);
    }

    int input = 0, score = 0, lvl = 1; //a loop iterator for saving the input in the structure
    

    while (EOF != fscanf(fin, "%100[^\n]\n", buffer))
    {
    	int user_answer = -1;

     	if(input == 0)
     		strcpy(q.question, buffer);
     	if(input == 1)
     		strcpy(q.a, buffer);
     	if(input == 2)
     		strcpy(q.b, buffer);
     	if(input == 3)
     		strcpy(q.c, buffer);
      	if(input == 4)
     		strcpy(q.d, buffer);
     	if(input == 5){
     	    input = -1;

     	    q.correct = atoi(buffer);

     	    //print the question
     	    printf("\n==============================\n");
     	    printf("===========[ QUIZ ]===========\n");
     	    printf("==[LVL:%2d]==========[PTS:%3d]=\n", lvl, score);
     	    printf("==============================\n");
     	    printf("Q. %s\n", q.question);
   			printf("==============================\n");
     	    printf("1.%s\n2.%s\n3.%s\n4.%s\n\n",q.a,q.b,q.c,q.d);

     	    //input their choice
     	   	printf("==============================\n");
     	    printf("Enter your choice (1,2,3,4): ");
     	    scanf("%d", &user_answer); 
     	    if(user_answer > 0 && user_answer < 5){
     	    	if(user_answer == q.correct+1){
     	    		score++;
     	    	}
     	    	else score--;
     	    }
     	    lvl++;
      	}


     	input++;

    }


    printf("\n\n\n\n===========[ QUIZ ]===========\n");
    printf("==[LVL:%2d]==========[PTS:%3d]=\n", lvl, score);
    printf("==============================\n");	

    printf(" Thank you for Participating\n");
    printf("==============================\n\n\n\n\n\n");	


	fclose(fin);

	return 0;
}