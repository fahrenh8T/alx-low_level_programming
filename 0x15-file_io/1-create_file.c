#include "main.h"
#include <string.h>
/**
 * create_file - creates a file and writes text content into it
 * @filename: name of the file to be created
 * @text_content: text to be written to the file
 *
 * Return: 1 if success, -1  if failure
*/
int create_file(const char *filename, char *text_content)
{
	int fdes, data_written, txtlength;

	if (filename == NULL)
		return (-1);

	fdes = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fdes == -1)
		return (-1);

	if (text_content != NULL)
	{
		txtlength = strlen(text_content);
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
