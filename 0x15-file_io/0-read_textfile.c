#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX stdout
 * @filename: name of the file to be read
 * @letters: number of letters it should read and print
 *
 * Returns: actual number of letters it should read and print
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file = fopen(filename, "r");
	char *data = (char*) malloc(letters * sizeof(char));
	ssize_t data_read = fread(data, sizeof(char), letters, file);
	ssize_t data_written = write(STDOUT_FILENO, data, data_read);

	if (filename == NULL)
		return (0);

	if (data == NULL)
	{
		fclose(file);
		return (0);
	}

	if (data_read < 0)
	{
		fclose(file);
		free(data);
		return (0);
	}

	if (data_written < 0 || data_written != data_read)
	{
		fclose(file);
		free(data);
		return (0);
	}

	fclose(file);
	free(data);
	return (data_read);
}
