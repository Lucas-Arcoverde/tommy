#include <stdio.h>
#include "utils.h"

void display_help_message(char * program_name)
{
	printf("\nTOMMY\n");
	printf("A CLI To-Do list.\n\n");

	printf("Usage: %s [FLAG] [ARGUMENTS]\n\n", program_name);

	printf("Commands:\n");
	printf(" -h  --help			Display this help message.\n");
	printf(" --version			Display the current version of the program.\n");
	printf(" -a  --add <TASK>		Add a new task to your list.\n");
	printf(" -v  --view			Display your To-Do List.\n");
	printf(" -u  --update <TASK_INDEX>	Change a task info.\n");
	printf(" -r  --remove <TASK_INDEX>	Remove a task from your list.\n\n");
}

void display_program_version()
{
	printf("Tommy\n");
	printf("by Lucas A Melo.\n");
	printf("\nVersion [ 1.26.01.2026 ].\n"); // version 1 realise january 26th 2026.
}

