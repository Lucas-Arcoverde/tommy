#include <string.h>
#include "utils.h"
#include "task_process.h"

int flag_to_int(char * flag)
{
	if (strcmp(flag, "-h") == 0 || strcmp(flag, "--help") == 0)
	{
		return 0;
	}

	else if (strcmp(flag, "--version") == 0)
	{
		return 1;
	}

	else if (strcmp(flag, "-a") == 0 || strcmp(flag, "--add") == 0)
	{
		return 2;
	}
	
	else if (strcmp(flag, "-v") == 0 || strcmp(flag, "--view") == 0)
	{
		return 3;
	}	

	else if (strcmp(flag, "-u") == 0 || strcmp(flag, "--update") == 0)
	{
		return 4;
	}

	else if (strcmp(flag, "-r") == 0 || strcmp(flag, "--update") == 0)
	{
		return 5;
	}

}

int main(int argc, char * argv[])
{
	if (argc < 2) // verifica se há argumentos suficientes.
	{
		return 1;
	}

	char * flag = argv[1];
	int flag_value = flag_to_int(flag);

	switch (flag_value)
	{
		case 0: // -h  --help
			char * program_name = argv[0];
			display_help_message(program_name);
			break;

		case 1: // --version
			display_program_version();
			break;

		case 2: // -a  --add | Create
			char * task = argv[2];
			//add_task(task);
			break;

		case 3: // -v  --view | Read
			//view_tasks();
			break;

		case 4: // -u  --update | Update
			char * task_index = argv[2];
			char * updated_task = argv[3];
			//update_task(task_index, updated_task);
			break;

		case 5: // -r  --remove | Delete
			char * task_to_remove_index = argv[2];
			//remove_task(task_to_remove_index);
			break;

		default:
			break;
	}

	return 0;
}
