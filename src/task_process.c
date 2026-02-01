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

void load_data()
{
  FILE * data_file = fopen("data.txt", "r");

  char line1[500];
  char line2[500];
  char line3[500];

  int i = 0;
  while (fgets(line1, sizeof(line1), data_file) && fgets(line2, sizeof(line2), data_file) && fgets(line3, sizeof(line3), data_file))
  {
    line1[strcspn(line1, "\n")] = '\0';
    strcpy(todo_list[i].title, line1);
    strcpy(todo_list[i].description, line2);
    strcpy(todo_list[i].date, line3);
    i++;
  }

  task_counter = i;

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

  task_counter++;
  save_data();
}

void view_tasks()
{
  load_data();
  
  printf("\nTODO LIST\n");
  for (int i = 0; i < task_counter; i++)
  {
    printf("\nINDEX\tTASK\n");
    printf("%i\t%s\n", i, todo_list[i].title);
    printf("\n");
  }
}

