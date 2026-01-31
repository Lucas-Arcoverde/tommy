#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task_process.h"

#define MAX_TITLE_SIZE 100;
#define MAX_DESCRIPTION_SIZE 500;
#define MAX_DATE_SIZE 25;

typedef struct {
  char title[MAX_TITLE_SIZE];
  char description[MAX_DESCRIPTION_SIZE];
  char date[MAX_DATE_SIZE]
} Task;

