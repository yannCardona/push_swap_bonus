/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:12:05 by ycardona          #+#    #+#             */
/*   Updated: 2023/02/12 15:39:44 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len ++;
	return (len);
}

void	ft_shiftbuff(char *str, int start)
{
	int	i;

	i = 0;
	while (str[start + i])
	{
		str[i] = str[start + i];
		i++;
	}
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *str, char *str_add, int size)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = malloc(ft_strlen(str) + size + 1);
	if (new_str == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	j = 0;
	while (j < size)
	{
		new_str[i + j] = str_add[j];
		j++;
	}
	new_str[i + j] = '\0';
	free (str);
	return (new_str);
}

char	*ft_calloc(size_t size)
{
	size_t	i;
	char	*str;

	str = malloc(size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

void	ft_bzero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}
