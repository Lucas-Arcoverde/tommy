#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_process.h"

#define MAX_TASKS 100
#define MAX_CHARS 500

char todo_list[MAX_TASKS][MAX_CHARS];
int task_counter = 0;

void save_data()
{
    FILE * data_file = fopen("data.txt", "w");
    if (data_file == NULL)
    {
        return;
    }

    for (int i = 0; i < task_counter; i++)
    {
        fprintf(data_file, "%s\n", todo_list[i]);
    }

    fclose(data_file);
}

void load_data()
{
    FILE * data_file = fopen("data.txt", "r");
    if (data_file == NULL)
    {
        return;
    }

    while (task_counter < MAX_TASKS && fgets(todo_list[task_counter], MAX_CHARS, data_file))
    {
        task_counter++;
    }

    fclose(data_file);
}

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
		printf("INDEX       TASK\n");
		for (int i = 0; i < task_counter; i++) //percorre a todo list
		{
			printf("%d           %s", i, todo_list[i]);
		}
	}

    printf("%d", task_counter);
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

void remove_task(char * task_index)
{
	int task_index_value = atoi(task_index);
	if (task_index_value < 0 || task_index_value >= task_counter)
	{
		return;
	}

	for (int i = task_index_value; i < task_counter; i++)
	{
		strcpy(todo_list[i], todo_list[i + 1]);
	}

	task_counter--;
}

