//Sorcha Nic Conmara
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

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
	int smartness;
	int strength;
	int dexterity;
	int magic_skills;
	int luck;
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
	hum.smartness = 1 + rand() % 49;
	hum.strength = 1 + rand() % 49;
	hum.dexterity = 1 + rand() % 49;
	hum.magic_skills = 1 + rand() % 49;
	hum.luck = 1 + rand() % 49;
	printf("\nHuman:\n lifepoints: %d\tsmartness: %d\tstrength: %d\tdexterity: %d\tmagicSkills: %d\tluck: %d\n", hum.life_pts, hum.smartness, hum.strength, hum.dexterity, hum.magic_skills, hum.luck);
}
//function for ogre's capabilites
void ogre(struct capabilities og)
{
	srand (time(NULL));
	og.life_pts = 100;
	og.smartness = 1 + rand() % 20;
	og.strength = 80 + rand() % 20;
	og.dexterity = 80 + rand() %20;
	og.magic_skills = 0;
	og.luck = 1 + rand() % 30;
	printf("\nOgre:\n lifepoints: %d\tsmartness: %d\tstrength: %d\tdexterity: %d\tmagicSkills: %d\tluck: %d\n", og.life_pts, og.smartness, og.strength, og.dexterity, og.magic_skills, og.luck);
}
//function for elf's capabilities
void elf(struct capabilities el)
{
	struct capabilities player;
	srand (time(NULL));
	el.life_pts = 100;
	el.smartness = (70 + rand()) % 30;
	el.strength = 1 + rand() % 50;
	el.dexterity = 1 + rand() %100;
	el.magic_skills = 50 + rand() %30;
	el.luck = 60 + rand() % 40;
	printf("\nElf:\n lifepoints: %d\tsmartness: %d\tstrength: %d\tdexterity: %d\tmagicSkills: %d\tluck: %d\n", el.life_pts, el.smartness, el.strength, el.dexterity, el.magic_skills, el.luck);
}
//function for wizard's capabilities
void wizard(struct capabilities wiz)
{
	struct capabilities player;
	srand (time(NULL));
	wiz.life_pts = 100;
	wiz.smartness = (90 + rand()) % 10;
	wiz.strength = 1 + rand() % 20;
	wiz.dexterity = 1 + rand() %100;
	wiz.magic_skills = 80 + rand() %20;
	wiz.luck = 50 + rand() % 50;
	printf("\nWizard:\n lifepoints: %d\tsmartness: %d\tstrength: %d\tdexterity: %d\tmagicSkills: %d\tluck: %d\n", wiz.life_pts, wiz.smartness, wiz.strength, wiz.dexterity, wiz.magic_skills, wiz.luck);
}

//MOVE AND ATTCK FUNCTIONS 
void move()
{
	
}
void attack()
{
	
}

//main function
int main()
{
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
	return 0;
}//end of main function
