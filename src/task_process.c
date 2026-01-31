#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task_process.h"

#define MAX_TITLE_SIZE 100
#define MAX_DESCRIPTION_SIZE 500
#define MAX_DATE_SIZE 25
#define MAX_TASKS 500

int task_counter = 0;

typedef struct {
  char title[MAX_TITLE_SIZE];
  char description[MAX_DESCRIPTION_SIZE];
  char date[MAX_DATE_SIZE];
} Task;

Task todo_list[MAX_TASKS];

void save_data()
{
  FILE * data_file = fopen("data.txt", "w");

  for (int i = 0; i < task_counter; i++)
  {
    fprintf(data_file, "%s\n", todo_list[i].title);
    fprintf(data_file, "%s\n", todo_list[i].description);
    fprintf(data_file, "%s\n", todo_list[i].date);
  }

  fclose(data_file);
}

void add_task(char * title, char * description, char * date)
{
  if (task_counter == MAX_TASKS)
  {
    return;
  }

  strcpy(todo_list[task_counter].title, title);
  strcpy(todo_list[task_counter].description, description);
  strcpy(todo_list[task_counter].date, date);

  save_data();

  task_counter++;
}

