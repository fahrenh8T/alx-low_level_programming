#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX stdout
 * @filename: name of the file to be read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it should read and print
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *data;
	ssize_t data_read, data_written;
	int file_des;

	if (filename == NULL)
		return (0);

	 file_des = open(filename, O_RDWR);
	 if (file_des == -1)
	 	return (0);
	 
	 data = (char *) malloc(letters * sizeof(char));
	 if (data == NULL)
		return (0);

	data_read = read(file_des, data, letters);
	data_written = write(STDOUT_FILENO, data, data_read);

	free(data);

	close(file_des);
	return (data_written);
}
