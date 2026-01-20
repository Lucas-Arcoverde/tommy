#include <string.h>
#include "task_process.h"

#define MAX_TASKS 100
#define MAX_CHARS 500

char todo_list[MAX_TASKS][MAX_CHARS];
int task_counter = 0;

void add_task(char * task)
{
	if (task_counter == MAX_TASKS)
	{
		return;
	}

	else
	{
		strcpy(todo_list[task_counter], task);
		task_counter++;
	}
}

