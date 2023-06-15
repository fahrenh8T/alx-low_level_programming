#include "main.h"
/**
 * append_text_to_file - appends text to the end of a file
 * @filename: name of the file to append to
 * @text_content: text to be appended
 *
 * Return: 1 if success, -1 if failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fdes, data_written, txtlength;

	if (filename == NULL)
		return (-1);

	fdes = open(filename, O_WRONLY | O_APPEND);
	if (fdes == -1)
		return (-1);

	if (text_content != NULL)
	{
		txtlength = 0;
		while (text_content[txtlength])
			txtlength++;

		data_written = write(fdes, text_content, txtlength);
		if (data_written != txtlength)
		{
			close(fdes);
			return (-1);
		}
	}

	close(fdes);
	return (1);
}

void funct_copy(int file_from, int file_to, char *source_name, char *sent_name)
{
}
