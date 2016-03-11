#include <stdio.h>

typedef struct
{
	char name[100];
	int lives;
}Player;

void getName(Player *player)
{



}
void lose_life(Player player)
{
	player.lives -= 1; //subtracts a life
	printf("Lives: %i\n", player.lives); //print the amount of lives again
	
	//checks if the lives have depleted
	if (player.lives <= 0)
	{
		//exits the quiz if user types in 'q'
		printf("You Lose! :'(");
		exit(0);
	}
}

