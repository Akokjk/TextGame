#include "prototypes.h"
#define NUM_OF_COMMANDS 1 


	
void help_com(char input[MAXBYTES]){ //help command
	printf("You have accesssed the help function.\n Hizzah!\n");
}

/**********************************************************************************************  
* Everytime a new command is created the address of the command function needs to be put into 
*  the get_command array, the NUM_OF_COMMANDS needs to be updated, and the command_checker 
* commands array needs to be updated. I wish I could simplify the process, but it's the best 
* I can implement right now.  
**********************************************************************************************/
int get_command(int value)
{
    int commands[NUM_OF_COMMANDS] = {&help_com};
    return commands[value];

}

void command_check(char input[MAXBYTES])
{
	//This will check to see if the input matches any possible command
	char* commands[NUM_OF_COMMANDS] = {"help"};
	int i;
	int check = -1;
	for (i = 0; i < NUM_OF_COMMANDS; i++){
		if (strcmp(commands[i], strtok(input, " ")) == 0){ //looks at frist word in the input 
			check = i;
			break;
		}
	}
	//We only really care when check is equal to zero 
	if (check <= -1){
		printf("Unknown Command.\n");
	}
	else {
		void (*command_ptr)(char*) = get_command(check); //generates a function pointer address using array found in get_command 
		(*command_ptr)(input); //Runs the function with the user input
	}

}
