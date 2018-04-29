#include "prototypes.h"
#define NUM_OF_COMMANDS 1 

#define COMMAND(x) (command)(x)

	
//to avoid unnessary function prototpye creating marcos the commmand_check function is at the botttom 

void command0(char* input){ //help command 
	printf("You have accesssed the help function.\n"); 
}

void command_check(char* input)
{
	//This will check to see if the input matches any possible command 
	char* commands[NUM_OF_COMMANDS] = {"help"};   
	int i; 
	int check = -1; 
	for (i = 0; i < NUM_OF_COMMANDS; i++){
		if (strcmp(commands[i], input) == 0){
			check = i; 
			break; 
		}
	}
	if (check <= -1){
		printf("Unknown Command.\n"); 
	}
	else {
		//This is probably one of the funnest things in c 
		void (*command_ptr)(char*) = &(COMMAND(check)); //generates a function pointer address using the macro 
		(*command_ptr)(input); //Runs the function with the user input 
	}
	
}

