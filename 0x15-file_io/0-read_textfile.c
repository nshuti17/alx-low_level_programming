#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - Entry point
 * Description: Reads a text file and prints it to the POSIX standard output
 * @filename: Name of the file to be read
 * @letters: The number of letters it should read and print
 *
 * Return: The actual number of letters it could read and print
 *		if the file can not be opened or read, return 0
 *		if filename is NULL return 0
 *		if write fails or does not write the expected amount of bytes, return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buff;
	ssize_t bytes, b;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}

	buff = malloc(sizeof(char) * letters);
	if (!buff)
	{
		close(fd);
		return (0);
	}

	bytes = read(fd, buff, letters);

	if (bytes == -1)
	{
		close(fd);
		free(buff);
		return (0);
	}

	b = write(STDOUT_FILENO, buff, bytes);

	if (b == -1)
	{
		close(fd);
		free(buff);
		return (0);
	}
	close(fd);
	return (bytes);
}






