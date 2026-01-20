#include <stdio.h>
#include <stdlib.h>
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

void view_tasks()
{
	if (todo_list[0] == "" || todo_list[0] == NULL)
	{
		return;
	}
	
	else
	{	
		printf("To-Do List:\n\n");
		printf("INDEX        TASK\n");
		for (int i = 0; i < task_counter; i++) //percorre a todo list
		{
			printf("%d           %s\n", i, todo_list[i]);
		}
	}
}

void update_task(char * task_index, char * task)
{
	int task_index_value = atoi(task_index);
	if (task_index_value < 0 || task_index_value >= task_counter)
	{
		return;
	}

	else
	{
		strcpy(todo_list[task_index_value], task);
	}

}

