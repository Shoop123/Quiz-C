//includes extra resources the program uses
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "question.h" //include the question structure
#include "player.h" //include the player structure

void run_question_loop();//declare the run loop function

//amount of question in the array
int questions_amount = 10;

Question questions[10]; //create an array of 10 questions

Player player;

char quit = 'q'; //in case user wants to exit the program

int main()
{	 
	init();

	//intro to the quiz
	printf("Amount of Questions: %d \n", questions_amount);
	printf("Type \"%c\" to quit\n\n", quit); //tell the user that they may quit by typing 'q'
	printf("Lives: %i\n", player.lives); //print the amount of lives they have
	
	set_questions(); //set up all of the questions
	
	run_question_loop(); //run the main loop that will ask and re-ask the questions
}

void init()
{
	printf("Please Enter Your Name: ");
	gets(player.name);
	player.lives = 3;
}

//the main quiz loop
void run_question_loop()
{
	int i; //interator
	
	//loops through each question and evaluates the answer
	for (i = 0; i < questions_amount; i++)
	{
		char answer[10]; /*stores answer of user*/
	
		//asks the question by printing it on the screen
		print_question(questions[i]);
		
		//prints choices for user
		print_answers(questions[i]);
		
		//prints "Answer"
		printf("Answer: ");
		
		//allows user to asnwer the  question, and stores the answer in the answer variable
		gets(answer);
		
		//stores the answer correctness result
		int answer_result = check_answer(answer[0], questions[i].answer);
		
		//checks the answer
		if (!answer_result)
		{
			//checks of the user inputted 'q' to quit
			check_quit(answer[0]);
			//make the question repeat
			i--;
			
			//loose a life
			lose_life(player);
		}
		
		//if this is the last question, then print "Great Job!" and the amount of lives
		if (i == questions_amount - 1)
		{
			printf("Great Job :)\n");
			printf("You ended with: %i lives!", player.lives);
		}
	}
}

//sets the questions up
void set_questions()
{
	questions[0].number = 1;
	strcpy(questions[0].question, "What is the code to comment in c?");
	questions[0].answer = 'c';
	questions[0].answers[0] = "\\\\";
	questions[0].answers[1] = "**";
	questions[0].answers[2] = "/**/";
	questions[0].answers[3] = "\\**\\";
	
	questions[1].number = 2;
	strcpy(questions[1].question, "What is the initializing function called?");
	questions[1].answer = 'b';
	questions[1].answers[0] = "init()";
	questions[1].answers[1] = "main()";
	questions[1].answers[2] = "start()";
	questions[1].answers[3] = "initialize()";
	
	questions[2].number = 3;
	strcpy(questions[2].question, "What is the code for printing to the console?");
	questions[2].answer = 'a';
	questions[2].answers[0] = "printf();";
	questions[2].answers[1] = "prinf();";
	questions[2].answers[2] = "print();";
	questions[2].answers[3] = "type();";
	
	questions[3].number = 4;
	strcpy(questions[3].question, "How do you store a string array in c?");
	questions[3].answer = 'd';
	questions[3].answers[0] = "string[] arrName";
	questions[3].answers[1] = "char[] arrName";
	questions[3].answers[2] = "string  arrName";
	questions[3].answers[3] = "*char[]  arrName";
	
	questions[4].number = 5;
	strcpy(questions[4].question, "What is the proper syntax for an if statement in c?");
	questions[4].answer = 'c';
	questions[4].answers[0] = "if (condition) {body};";
	questions[4].answers[1] = "if (body) {condition}";
	questions[4].answers[2] = "if (condition) {body}";
	questions[4].answers[3] = "if (\"true\") {body}";
	
	questions[5].number = 6;
	strcpy(questions[5].question, "What library is used for input and output?");
	questions[5].answer = 'b';
	questions[5].answers[0] = "#include <stdlib.h>";
	questions[5].answers[1] = "#include <stdio.h>";
	questions[5].answers[2] = "#include <time.h>";
	questions[5].answers[3] = "#include <string.h>";
	
	questions[6].number = 7;
	strcpy(questions[6].question, "Each line in c must end in:");
	questions[6].answer = 'd';
	questions[6].answers[0] = ":";
	questions[6].answers[1] = ".";
	questions[6].answers[2] = "!";
	questions[6].answers[3] = ";";
	
	questions[7].number = 8;
	strcpy(questions[7].question, "C is a:");
	questions[7].answer = 'a';
	questions[7].answers[0] = "Structured Language";
	questions[7].answers[1] = "OOP Language";
	questions[7].answers[2] = "Both";
	questions[7].answers[3] = "None";
	
	questions[8].number = 9;
	strcpy(questions[8].question, "C is most similar to:");
	questions[8].answer = 'b';
	questions[8].answers[0] = "Python";
	questions[8].answers[1] = "C++";
	questions[8].answers[2] = "C#";
	questions[8].answers[3] = "Java";
	
	questions[9].number = 10;
	strcpy(questions[9].question, "C is missing the data type of:");
	questions[9].answer = 'c';
	questions[9].answers[0] = "Integer";
	questions[9].answers[1] = "Floating Point Number";
	questions[9].answers[2] = "String";
	questions[9].answers[3] = "Char";
}

void check_quit(char answer)
{
	if (answer == quit)
	{
		quit_quiz();
	}
}

void quit_quiz()
{
	//exits the quiz if user types in 'q'
	printf("You Lose! :'(");
	exit(0);
}

