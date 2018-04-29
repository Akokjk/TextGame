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

#include "command_check.c"

void command_check(char* input); //This might have to return updated player information based off what the command accoplished

#endif 