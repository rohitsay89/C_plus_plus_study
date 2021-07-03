/*
 * cmd_hndlr.c
 *
 *  Created on: Jun 30, 2021
 *      Author: rohit
 */
#include "../main.h"
#include "cmd_hndlr.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

static commandStruct_t commands[] = {
	{"ver",          &getVersion,                        "Print version of firmware"      },
	{"git",          &getGitInfo ,                       "Get Git commit info"			  },
	{"time",         &getSystemTime,                     "Print system time on the screen"},
	{"help",         &printMenu,                         "Print all the available commands"},
	{"q",            &closeApp,                          "Close the application"          },

	{"arad",         &array_address_calculation,         "Array address calc demo"        },
	{"arsum",        &array_sum_wrapper,                 "Array sum test code"            },
	{"invnum",       &inverse_num_wrapper,               "Inverse of a number"            },
	{"findprime",    &find_prime,                        "Find if a given number is prime or not" },
	{"revbits",      &reverse_bits,                      "Reverse bits in a bin number"   },
	{"sLsort",       &vSelectionSort,                    "Selection sort test code"       },
	{"iNsort",       &vInsertionSort,                    "Insertion sort test code"       },
	{"stRev",        &string_reverse1,                   "Reverse of a string"            },
	{"stSrch",       &vstringSearch,                     "Search a string"                },
	{"CRC",          &CRC_Practice,                      "CRC calculation test code"      },
	{"fibo",         &vFibonacciSequence,                "Fibonnaci sequence test"        },
	{"recrn",        &vLearnRecursion,                   "Recursion example"              },
	{"flDir",        &vListFilesInDir,                   "Directory listings"             },
	{"stMchn",       &vLearnStateMachine,                "State machine test code"        },
	{"", 0, ""}
};


void printMenu(void)
{
	uint32_t index = 0;
	while(commands[index].execute != 0)
	{
		printf("  %d. %s --> %s\n", index+1, commands[index].name, commands[index].help);
		if( !(strcmp(commands[index].name, "q")) ){
			printf("\n");
		}
		index++;
	}
}

void getVersion(void){
  printf("Version is v0.1\r\n");
}


void getGitInfo(void){
  printf("Print git info here\r\n");
}

void getSystemTime(){
  printf("This function is to print time\r\n");
}

void closeApp(void){
	exit(0);
}

void run_command_handler(void)
{
	char cmd[20] = {0};
	uint32_t index = 0;

	printf("Enter command:> ");
	scanf("%s", cmd);

#if 0
	uint32_t i = 0;
	// check if the command is greater than 20 chars
	while(i <= 20){
		if( cmd[i] == '\0' ){
			break;
		}
		i++;
		if(i > 20){
			printf("  ** Invalid command **  \r\n");
			return ;
		}
	}
#endif


	while(commands[index].execute != 0){
		/*while(cmd[i] != 0x32){
			i++;
		}*/
		if( !(strcmp(commands[index].name, cmd)) ){
			commands[index].execute();
			break;
		}
		index++;
		if(commands[index].execute == 0){
			printf("  ** Invalid command **  \r\n");
		}
	}
}
