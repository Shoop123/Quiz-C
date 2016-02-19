//includes extra resources the program uses
#include <stdio.h>
#include<stdlib.h>

void print_options(int index);

//array of questions to ask
char *questions[] = {"What is the code to comment in c?",
"What is the initializing function called?", 
"What is the code for printing to the console?",
"How do you store a string array in c?",
"What is the proper syntax for an if statement in c?",
"What library is used for input and output?",
"Each line in c must end in:"};

//array of answers to questionsk
char correct_answers[] = {'c',
'b',
'a',
'd',
'c',
'b',
'd'};

char quit = 'q'; //in case user wants to exit the program

//choices for quiz
char *options_a[] = {"\\\\", "init()", "printf();", "string[] arrName", "if (condition) {body};", "#include <stdlib.h>", ":"};
char *options_b[] = {"**", "main()", "prinf();", "char[] arrName", "if (body) {condition}", "#include <stdio.h>", "."};
char *options_c[] = {"/**/", "start()", "print();", "string  arrName", "if (condition) {body}", "#include <time.h>", "!"};
char *options_d[] = {"\\**\\", "initialize()", "type();", "*char[]  arrName", "if (\"true\") {body}", "#include <string.h>", ";"};

//amount of question in the array
int questions_amount = sizeof(questions) / sizeof(questions[0]);

int main()
{	 
	//intro to the quiz
	printf("Amount of Questions: %d \n", questions_amount);
	printf("Type \"%c\" to quit\n\n", quit);
	
	int i; //interator
	
	//loops through each question and evaluates the answer
	for (i = 0; i < questions_amount; i++)
	{
		char answer[10]; /*stores answer of user*/
	
		//asks the question by printing it on the screen
		printf("%i. Question: %s\n", i + 1, questions[i]);
		
		//prints choices for user
		print_options(i);
		
		printf("Answer: ");
		
		//allows user to asnwer the  question, and stores the answer in the answer variable
		gets(answer);
		
		//checks if answer is correct
		if (answer[0] == correct_answers[i])
		{
			//proceeds to the next question of answer is correct
			printf("Correct! :)\n");
			printf("\n--------------------------\n\n");
		}
		else if (answer[0] == quit)
		{
			//exits the quiz if user types in 'q'
			printf(":'(");
			exit(0);
		}
		else
		{
			//stays at the current question because user got it wrong
			printf("Incorrect! :(\n\n");
			i--;
		}
		
		//if this is the last question, then print "Great Job!
		if (i == questions_amount - 1)
		{
			printf("Great Job!");
		}
	}
}

//prints options for the question at the given index
void print_options(int index)
{
	printf("a) %s\n", options_a[index]);
	printf("b) %s\n", options_b[index]);
	printf("c) %s\n", options_c[index]);
	printf("d) %s\n", options_d[index]);
}

