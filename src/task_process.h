#ifndef TASK_PROCESS
#define TASK_PROCESS

void add_task(char * task);
void view_tasks();
void update_task(char * task_index, char * task);
void remove_task(char * task_index);

void save_data();
void load_data();

#endif
