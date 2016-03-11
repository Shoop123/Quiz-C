#include <stdio.h> //input output library included

//define struct for questions
typedef struct
{
	int number; //the number of the struct
	char question[1000]; //the question
	char answer; //the answer from the options
	char *answers[4]; //the choices
}Question;

//prints question
void print_question(Question q)
{
	printf("%i. Question: %s\n", q.number, q.question); //print the number and the question
}

//print all of the options for the question
void print_answers(Question q)
{
	//print a, b, c, and d choices
	printf("a) %s\n", q.answers[0]);
	printf("b) %s\n", q.answers[1]);
	printf("c) %s\n", q.answers[2]);
	printf("d) %s\n", q.answers[3]);
}

//check the answer with the correct answer
int check_answer(char user_answer, char correct_answer)
{
	//checks if answer is correct
	if (user_answer == correct_answer)
	{
		//proceeds to the next question of answer is correct
		printf("Correct! :)\n");
		printf("\n--------------------------\n\n");
		return 1;
	}
	else
	{
		//stays at the current question because user got it wrong
		printf("Incorrect! :(\n\n");
		return 0;
	}
}

