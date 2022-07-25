#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*temp;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	temp = get_next_line(fd);
	// while ((temp = (get_next_line(fd)) != 0))
	// {
	// 	printf("%s\n", temp);
	// 	free(temp);
	// }
	printf("%s\n", temp);
	free(temp);
	close(fd);
	return (0);
}