//Player.c 
#include "prototypes.h" 
#define BASE_WEIGHT 0 

player player1; 

void GeneratePlayerData(){
	//This can loaded in from a file or something if you want to save or whatever 
	player1->name = "Aaron. The God of Mayslo."; 
	player1->player_location = {0, 0, 0}; 
	player1->weight = BASE_WEIGHT; 
	player1->health = 1; 
	player1->player_status[0] = 0; 
	
}
