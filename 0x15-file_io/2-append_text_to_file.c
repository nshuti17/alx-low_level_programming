#include "main.h"

/**
 * append_text_to_file - Entry point
 * Description: Appends text at the end of a file
 * @filename: The name of the file to be read
 * @text_content: The NULL terminated string to add at the end of the file
 *
 * Return: 1 on sucess, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t b;
	int size;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}

	size = _strlen(text_content);
	b = write(fd, text_content, size);

	if (b == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}

/**
 * _strlen - len
 *
 * @s: is a pointer to a char
 *
 * Return: Always 0.
 */

int _strlen(const char *s)
{
	int a = 0;

	while (*(s + a) != '\0')
	{
		a++;
	}

	return (a);
}
