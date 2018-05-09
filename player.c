//Player.c 
#include "prototypes.h" 
#define BASE_WEIGHT 0 

struct{
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
}player; 


player *player1; 

void GeneratePlayerData(){
	//This can loaded in from a file or something if you want to save or whatever 
	player1->name = "Aaron. The God of Mayslo."; 
	player1->location = {0, 0, 0}; 
	player1->weight = BASE_WEIGHT; 
	player1->health = 1; 
	player1->player_status[0] = 0; 
	
}
