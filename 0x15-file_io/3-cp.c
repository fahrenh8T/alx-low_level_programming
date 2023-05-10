#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 1024
/**
 * main - copies the content from one file to another
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 if success, exit when code error
*/
int main(int argc, char *argv[])
{
	int fdes_source, fdes_sent, data_read, data_written, close_source, close_sent;
	char buffer[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,  "Usage: cp file_from file_to\n");
		exit(97);
	}

	fdes_source = open(argv[1], O_RDONLY);
	if (fdes_source == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fdes_sent = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fdes_sent == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fdes_source);
		exit(99);
	}

	while ((data_read = read(fdes_source, buffer, BUF_SIZE)) > 0)
	{
		data_written = write(fdes_sent, buffer, data_read);
		if (data_written != data_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", argv[2]);
			close(fdes_source);
			close(fdes_sent);
			exit(99);
		}
	}

	close_source = close(fdes_source);
	close_sent = close(fdes_sent);
	if (close_source == -1 || close_sent == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", close_source == -1 ? fdes_source : fdes_sent);
		exit(100);
	}
	return (0);
}
