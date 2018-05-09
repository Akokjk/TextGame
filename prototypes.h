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
#include "command_check.c"
#include "player.c"

//I need a player structure to hold useful information about the player 

typedef struct location{
	int x; 
	int y; 
	int z;
}; 

struct player{
	//location x y z 
	//items 
	//hp 
	//status or effects on the player 
	//stance this will change player height 
	location player_location; 
	
}


void command_check(char* input); //This might have to return updated player information based off what the command accoplished

#endif 
