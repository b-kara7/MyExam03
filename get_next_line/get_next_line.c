#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *ft_strdup(char *s)
{
	int i = -1;
	while (s[++i]);
	char *a = malloc (i + 1);
	if (!a)
		return NULL;
	i = -1;
	while (s[++i])
		a[i] = s[i];
	a[i] = '\0';
	return a;
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static char line[70000];
	static int buffer_pos;
	static int buffer_read;
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return 0;
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break;
		}
		line[i++] = buffer[buffer_pos++];
		if (buffer[buffer_pos - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return NULL;
	return (ft_strdup(line));
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("ilyas", O_CREAT | O_RDWR , 777);
	printf("%s", get_next_line(fd));
}