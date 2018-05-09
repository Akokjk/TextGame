#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define MAXBYTES 80
#define MAX_INVENTORY 99 
#define NUM_EFFECTS 6  
#define MAX_DESC 200 
#include "command_check.c"
#include "player.c"

//I need a player structure to hold useful information about the player 

int SizeOfPlayerInv = 3; 

typedef struct{
	int x; 
	int y; 
	int z;
}location; 

typedef struct{
	char** type = {"Weapon", "Quest Item", "Misc", "Magic", "Money"}; 
	
}typeOfItem; 

typedef struct{
	unsigned int id; 
	typeOfItem item_type; 
	char name[MAXBYTES]; 
	char description[MAX_DESC]; 
	unsigned int weight; 
	location item_location; //items can be picked up thus need a location 
	unsigned int size; //This can be used to figure out when to show it in a prompt needs to math equation most likely a sqaure radius 
	//I might need something for objects or other world based entities that you cant pick up but interact with 
	unsigned int amount; //for the case of having like 5000 gold or something 
	//money might need you carry a wallet or bag. I might need a seperate  function handling that 
}item;

typedef struct{
	//This is going to happen later on 
	char* type[NUM_EFFECTS] = {"Sick", "Sleepy", "Hungry", "Encumbered", "Bleeding", "Content"};
	int id; 
	
}player_effects; 

struct player{
	//location x y z 
	//items: type, name, description   
	//hp 
	//status or effects on the player 
	//hungry, sick, sleepy, bleeding, encumbered 
	//stance this will change player height 
	char name[MAXBYTES]; 
	int weight; 
	location player_location; 
	//inventory needs to dynmaically allocated 
	item inventory[MAX_INVENTORY]; //this might increase if you get a backpack or something
	unsigned int health; 
	player_effects player_status[NUM_EFFECTS]; 
}

player *player1; 




void GeneratePlayerData(); 
void command_check(char* input); //This might have to return updated player information based off what the command accoplished

#endif 
