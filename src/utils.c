#include <stdio.h>
#include "utils.h"

void display_help_message(char * program_name)
{
	printf("\nTOMMY\n");
	printf("A CLI To-Do list.\n\n");

	printf("Usage: %s [FLAG] [ARGUMENTS]\n\n", program_name);

	printf("Commands:\n");
	printf(" -a  --add <TITLE> <DESC> <DATE>	Add a new task to your list.\n");
	printf(" -v  --view				                View your to-do list.\n");
	printf(" -u  --update <INDEX> <TITLE> <DESC> <DATE>\n");
	printf("					                        Update a task information.\n");
	printf(" -r  --remove <INDEX>			        Remove a task from your list.\n");
  printf(" -d  --view-details <INDEX>       View a task details.\n");
}

void display_program_version()
{
	printf("Tommy\n");
	printf("by Lucas Arcoverde.\n");
	printf("\nVersion [ 2.13.2.26 ].\n");
}

