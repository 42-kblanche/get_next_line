*This project has been created as part of the 42 curriculum by kblanche.*

# Get Next Line

## Description

The goal of this project is to create a function (`get_next_line`) that reads a line from a file descriptor and returns it, using static variables.

## Instructions

### Basic usage

- Use the function `get_next_line` to read from a file descriptor.
	- The function prototype is the following: `char *get_next_line(int fd);`
	- Do not forget to include `get_next_line.h` in the files using the function.
	- Do not forget to include `get_next_line.c` and `get_next_line_utils.c` when compiling your program.
		- See [Exemple code](#exemple-code) to see the use-case

### Testing

If this project was downloaded from github, you should also be able to create a testing program.

- To run tests, use `make`
	- The resulting `gnl_test` program should display the file provided as argument.

## Ressources

[man read](https://man7.org/linux/man-pages/man2/read.2.html)

*AI was not used in this project*

After my first attempt, I searched for a better algorithm and ended up on [this page](https://medium.com/@beatrizbazaglia/get-next-line-3872eb3189e6) from a 42 student.

## Technical choices

### todo

## Exemple code

#### gnl_test.c

	#include "get_next_line.h"
	#include <stdio.h>
	#include <stlib.h>
	#include <fcntl.h>

	int	main(int argc, char **argv)
	{
		char	*line;
		int		fd;

		if (argc > 1)
			fd = open(argv[1], O_RDONLY);
		else
			fd = open("README.md", O_RDONLY);
		if (fd < 0)
			return (fd);
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			line = get_next_line(fd);
		}
		close(fd);
		return (0);
	}

#### Compiling
`cc -Wall -Werror -Wextra [-D BUFFER_SIZE=1] gnl_test.c get_next_line.c get_next_line_utils.c -o gnl_test`
