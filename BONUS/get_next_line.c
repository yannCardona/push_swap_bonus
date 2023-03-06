/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:47:08 by ycardona          #+#    #+#             */
/*   Updated: 2023/02/13 12:44:27 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_nl(char *buff, char **next_line)
{
	int	i;

	i = 0;
	while (i < ft_strlen(buff))
	{
		if (buff[i] == '\n')
		{
			*next_line = ft_strjoin(*next_line, buff, i + 1);
			if (*next_line == NULL)
			{
				ft_bzero(buff);
				return (1);
			}
			ft_shiftbuff(buff, i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_find_next_line(int fd, char *buff, char *next_line)
{
	int	r;

	r = 1;
	while (0 < r)
	{
		if (ft_find_nl(buff, &next_line) == 1)
			return (next_line);
		next_line = ft_strjoin(next_line, buff, ft_strlen(buff));
		if (next_line == NULL)
		{
			ft_bzero(buff);
			return (NULL);
		}
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0 || (r == 0 && ft_strlen(buff) == 0))
		{
			ft_bzero(buff);
			free(next_line);
			return (NULL);
		}
		buff[r] = '\0';
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*next_line;

	if (fd < 0 || FOPEN_MAX < fd || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = ft_calloc(sizeof(char) * (ft_strlen(buff[fd]) + 1));
	if (next_line == NULL)
	{
		ft_bzero(buff[fd]);
		return (NULL);
	}
	next_line = ft_find_next_line(fd, buff[fd], next_line);
	return (next_line);
}

/* int	main(void)
{
	int fd1 = open("test.txt", O_RDONLY);
	char *next_line = get_next_line(fd1);
	printf("%i\n", fd1);
	printf("1: %s\n", next_line);
	free(next_line);
	next_line = get_next_line(fd1);
	printf("2: %s\n", next_line);
	free(next_line);
	next_line = get_next_line(fd1);
	printf("3: %s\n", next_line);
	free(next_line);
	next_line = get_next_line(fd1);
	printf("4: %s\n", next_line);
	free(next_line);
	close(fd1);
} */