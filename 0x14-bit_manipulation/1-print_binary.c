#include "main.h"
#include <stdio.h>

/**
 * print_binary - converts unsigned int to binary
 * @m: Printed in binary format
 * Description:  Prints the binary representation of a number
 * Return: binary
 */
void print_binary(unsigned long int m)
{
	if (m > 1)
		/*right shift operator*/
		/*shifts all bits towards right by certain numbf 1 bits*/
		print_binary(m >> 1);

	_putchar((m & 1) + '0');
}
