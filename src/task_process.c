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

  if (!data_file)
  {
    data_file = fopen("data.txt", "w");
    fclose(data_file);
    data_file = fopen("data.txt", "r");
  }

  char line1[500];
  char line2[500];
  char line3[500];

  int i = 0;
  while (i < MAX_TASKS &&
         fgets(line1, sizeof(line1), data_file) &&
         fgets(line2, sizeof(line2), data_file) && 
         fgets(line3, sizeof(line3), data_file))
  {
    line1[strcspn(line1, "\n")] = '\0';
    line2[strcspn(line2, "\n")] = '\0';
    line3[strcspn(line3, "\n")] = '\0';

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
  load_data();
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
    printf("\n==================== TODO LIST ====================\n");
    printf("%-5s | %-30s | %-20s\n", "ID", "TITLE", "DATE");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < task_counter; i++)
    {
        printf("%-5d | %-30s | %-20s\n",
               i,
               todo_list[i].title,
               todo_list[i].date);
    }

    printf("===================================================\n"); 
}

void update_task(char * task_index, char * title, char * description, char * date)
{
  load_data();
  int task_index_value = atoi(task_index);

  if (task_index_value < 0 || task_index_value >= task_counter)
  {
    return;
  }

  strcpy(todo_list[task_index_value].title, title);
  strcpy(todo_list[task_index_value].description, description);
  strcpy(todo_list[task_index_value].date, date);

  save_data();
}

void remove_task(char * task_index)
{
  load_data();
  int task_index_value = atoi(task_index);

  if (task_index_value < 0 || task_index_value >= task_counter)
  {
    return;
  }

  for (int i = task_index_value; i < task_counter-1; i++)
  {
    strcpy(todo_list[i].title, todo_list[i+1].title);
    strcpy(todo_list[i].description, todo_list[i+1].description);
    strcpy(todo_list[i].date, todo_list[i+1].date);
  }
  
  task_counter--;
  save_data();
}

