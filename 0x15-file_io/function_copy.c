#include "main.h"
#define BUFFER_SIZE 1024
/**
 * func_copy - copies content from one file to another
 * @file_from: source file descriptor
 * @file_to: destination file
 * @source_name: source file name
 * @sent_name: destination file name
*/
void func_copy(int file_from, int file_to, char *source_name, char *sent_name)
{
	ssize_t read_data, written_data;
	char bff[BUFFER_SIZE];
	int close_file;

	read_data = BUFFER_SIZE;
	while (read_data == BUFFER_SIZE)
	{
		read_data = read(file_from, bff, BUFFER_SIZE);
		if (read_data == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source_name);
			exit(98);
		}

		written_data = write(file_to, bff, read_data);
		if (written_data == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", sent_name);
			exit(99);
		}

		close_file = close(file_from);
		if (close_file == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
			exit(100);
		}
		close_file = close(file_to);
		if (close_file == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
			exit(100);
		}
	}
}
