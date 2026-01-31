#ifndef TASK_PROCESS
#define TASK_PROCESS

void add_task(char * title, char * description, char * date);
void view_tasks();
void update_task(char * task_index, char * title, char * description, char * date);
void remove_task(char * task_index);

#endif TASK_PROCESS
