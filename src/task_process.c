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

    int i = 0;
    while (fgets(todo_list[i], MAX_CHARS, data_file))
    {
        size_t len = strlen(todo_list[i]);
        if (todo_list[i][len-1] == '\n')
        {
            todo_list[i][len-1] = '\0';
        }
        i++;
    }

    task_counter = i;

    fclose(data_file);
}

void add_task(char * task)
{
    load_data();
	if (task_counter == MAX_TASKS)
	{
		return;
	}

	strcpy(todo_list[task_counter], task);
	task_counter++;
    save_data();
}

void view_tasks()
{
    load_data();
	if (strcmp(todo_list[0], "") == 0 || todo_list == NULL)
	{
		return;
	}
	
	printf("To-Do List:\n\n");
	printf("INDEX       TASK\n");
	for (int i = 0; i < task_counter; i++) //percorre a todo list
	{
        if (strcmp(todo_list[i], "") == 0 || strcmp(todo_list[i], " ") == 0)
        {
            continue;
        }
		printf("%d           %s\n", i, todo_list[i]);
	}
}

void update_task(char * task_index, char * task)
{
    load_data();
    int task_index_value = atoi(task_index);

    if (task_index_value > task_counter || task_index_value < 0)
    {
        return;
    }

    strcpy(todo_list[task_index_value], task);
    save_data();
}

void remove_task(char * task_index)
{
    load_data();
    int task_index_value = atoi(task_index);

    for (int i = task_index_value; i < task_counter; i++)
    {
        strcpy(todo_list[i], todo_list[i+1]);
    }

    task_counter--;
    save_data();
}

