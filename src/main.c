int main(int argc, char * argv[])
{
	if (argc < 2) // verifica se há argumentos suficientes.
	{
		return 1;
	}

		char * flag = argv[1];

	switch (flag)
	{
		case "-h":
		case "--help":
			//display_help_message(program_name);
			break;

		case "-v":
		case "--version":
			//display_program_version();
			break;

		case "-a": //Create
		case "--add":
			//char * task = argv[2];
			//add_task(task);
			break;

		case "-v": //Read
		case "--view":
			//view_tasks();
			break;

		case "-u": //Update
		case "--update":
			//char * task_index = argv[2];
			//char * task = argv[3];
			//update_task(task_index, task);
			break;

		case "-r": // Delete
		case "--remove":
			//char * task_index = argv[2];
			//remove_task(task_index);
			break;

		default:
			break;
	}

	return 0;
}
