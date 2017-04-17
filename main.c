/*
player chooses player types and names and each player is given characteristics
player then selects a slot position from the 7x7 board
//Sorcha Nic Conmara

 */

#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "crossfireOperations.h"


//structs for slots and player capabilities
struct slots
{
	char level_ground;
	char hill;
	char city;
	char n;
	char x;
};
struct capabilities
{
	int life_pts;
	int Smartness;
	int strength;
	int Dexterity;
	int magic_skills;
	int Luck;
};

//function prototypes
void ogre(struct capabilities);
void elf(struct capabilities);
void wizard(struct capabilities);
void human(struct capabilities);


//function for human's capabilities
void human(struct capabilities hum)
{
	struct capabilities player;
	srand (time(NULL));
	hum.life_pts = 100;
	hum.Smartness = 1 + rand() % 49;
	hum.strength = 1 + rand() % 49;
	hum.Dexterity = 1 + rand() % 49;
	hum.magic_skills = 1 + rand() % 49;
	hum.Luck = 1 + rand() % 49;
	printf("\nHuman:\n Lifepoints: %d\tsmartness: %d\tstrength: %d\tdexterity: %d\tmagicSkills: %d\tluck: %d\n", hum.life_pts, hum.Smartness, hum.strength, hum.Dexterity, hum.magic_skills, hum.Luck);
}
//function for ogre's capabilites
void ogre(struct capabilities og)
{
	srand (time(NULL));
	og.life_pts = 100;
	og.Smartness = 1 + rand() % 20;
	og.strength = 80 + rand() % 20;
	og.Dexterity = 80 + rand() %20;
	og.magic_skills = 0;
	og.Luck = 1 + rand() % 30;
	printf("\nOgre:\n Lifepoints: %d\tsmartness: %d\tstrength: %d\tdexterity: %d\tmagicSkills: %d\tluck: %d\n", og.life_pts, og.Smartness, og.strength, og.Dexterity, og.magic_skills, og.Luck);
}
//function for elf's capabilities
void elf(struct capabilities el)
{
	struct capabilities player;
	srand (time(NULL));
	el.life_pts = 100;
	el.Smartness = (70 + rand()) % 30;
	el.strength = 1 + rand() % 50;
	el.Dexterity = 1 + rand() %100;
	el.magic_skills = 50 + rand() %30;
	el.Luck = 60 + rand() % 40;
	printf("\nElf:\n Lifepoints: %d\tsmartness: %d\tstrength: %d\tdexterity: %d\tmagicSkills: %d\tluck: %d\n", el.life_pts, el.Smartness, el.strength, el.Dexterity, el.magic_skills, el.Luck);
}
//function for wizard's capabilities
void wizard(struct capabilities wiz)
{
	struct capabilities player;
	srand (time(NULL));
	wiz.life_pts = 100;
	wiz.Smartness = (90 + rand()) % 10;
	wiz.strength = 1 + rand() % 20;
	wiz.Dexterity = 1 + rand() %100;
	wiz.magic_skills = 80 + rand() %20;
	wiz.Luck = 50 + rand() % 50;
	printf("\nWizard:\n Lifepoints: %d\tsmartness: %d\tstrength: %d\tdexterity: %d\tmagicSkills: %d\tluck: %d\n", wiz.life_pts, wiz.Smartness, wiz.strength, wiz.Dexterity, wiz.magic_skills, wiz.Luck);
}


int main()
{

	int row, column;
	
	setvbuf(stdout, 0, _IONBF, 0);
	int randomise;
	int num_players, player_type, i;
	
	int s;
	int slots;
	char username [50];
	
	struct slots players;
	struct capabilities player;


	printf("Please select the number of players (maximum of 6):");
	scanf("%d", &num_players);
	
	//error message if user selects more than 6 players
	if (num_players > 6)
	{
		printf("ERROR: Can only have a max  of 6 players!");
	}
	if (num_players == 1)//must have min 2 players
	{
		printf("ERROR: Must have a minimum of 2 players!");
		exit(1);
	}
	//if user inputs suitable amount of players
	if (num_players <= 6)
	{
		for(i=0;i<num_players;i++)
		{
			printf("Please enter your player name:\n");
			scanf("%s", &username);
			printf("***Please select the type of player***\n\n 1.Human\n 2.Ogre\n 3.Elf\n 4.Wizard\n");
			scanf("%d",&player_type);

			
			srand (time(NULL));//generates different random number each time
			
			//assigns slots torandom number between 1 and 3
			randomise = 0 + rand() % 3;
			if (randomise == 0)
			{
				slots = players.level_ground;
			}
			if(randomise == 1)
			{
				slots = players.hill;
			}
			if(randomise == 2)
			{
				slots = players.city;
			}
			//slot type and player number is printed
			printf("\nSlot 0 = Level Ground\n Slot 1 = Hill\n Slot 2 = City\n");
			printf("Slot type: %d \nPlayer: %d\n", randomise, i);
			
			//switch board to call various functions depending on what type of player is selected
			switch(player_type)
			{
			case 1:
			human(player);//calls human function
			break;
			
			case 2:
			ogre(player);//calls ogre function
			break;
			
			case 3:
			elf(player);//calls elf function
			break;
			
			case 4:
			wizard(player);//calls wizard function
			break;
			}
		}
	}

	struct slot* currSlot = NULL;
	struct slot *foundSlots;
	bool explored[BOARD_SIZE][BOARD_SIZE];
	int count =0;

	//pointer to slot (0,0)
	struct slot *upLeft;

	//pointer to slot (0,boardSize -1)
	struct slot *upRight;

	//pointer to slot (boardSize - 1, 0)
	struct slot *downLeft;

	//pointer to slot (boardSize - 1, boardSize -1)
	struct slot *downRight;

	//Creates the board
	createBoard(BOARD_SIZE,&upLeft, &upRight, &downLeft, &downRight);

	/*	Asks the user the row and the column of the slot
		s/he wants to retrieve from the board.
		Note that the user needs to know the size of the board to input
		the correct row and column of the slot s/he wants to retrieve */
	getDesiredElement(BOARD_SIZE, &row,&column);

	
	//Finds the slot


	/*If the the required slot is closer to the down-right
	 * corner of the board the search starts from downRight,
	 * which points to slot at position (boardSize-1, boarSize -1)*/
	if(row >= BOARD_SIZE/2){
		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column,downRight);
		else
		/*If the the required slot is closer to the down-left
		* corner of the board the search starts from downLeft,
		* which points to slot at position (boardSize-1, 0)*/
			currSlot = reachDesiredElement(row,column,downLeft);
	} else {
		/*If the the required slot is closer to the up-right
		* corner of the board the search starts from upRight,
		* which points to slot at position (0, boarSize -1)*/
		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column, upRight);
		/*If the the required slot is closer to the up-left
		* corner of the board the search starts from upLeft,
		* which points to slot at position (0, 0)*/
		else currSlot = reachDesiredElement(row,column,upLeft);
	}
	//initialise the matrix that takes traces fo the elements explored
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE;j++){
			explored[i][j] = false;
		}
	}
	
	//the max number of adjacent slots at distance 3 that can be found is 16
	foundSlots = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
	printf("\n\nFunction findSlots invoked:\n");

	if(currSlot!= NULL){
		//invokes function findSlots. The required distance is a constant
		//However you can reuse this function providing as input any arbitrary distance
		findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, &count, explored);
		for(int i=0; i<count; i++){
			printf("(%d, %d)-> \t",foundSlots[i].row, foundSlots[i].column);
		}
	}

	return 0;
}
