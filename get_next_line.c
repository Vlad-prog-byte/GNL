/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:17:54 by cayesha           #+#    #+#             */
/*   Updated: 2021/11/26 19:48:25 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include"fcntl.h"
#include"stdio.h"

char *init_line(char **line)
{
	*line = (char *)malloc(1);
	if (*line == NULL)
		return (NULL);
	else
		{
			(*line)[0] = '\0';
			return (*line);
		}
}


int part(int fd, char *str, char *line1, int *position)
{
	int size_str;
	
	size_str = read(fd, str, BUFFER_SIZE);
	if (size_str <= 0)
	{
		if (line1 != NULL && line1[0] == '\0')
		{
			free(line1);
			return (0);
		}
		else
		return (1);
	}
	else
	{
		str[size_str] = '\0';
		*position = 0;
		return (2);
	}
}

int find_me(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


char * get_next_line(int fd)
{
	static char str[BUFFER_SIZE + 1];
	char	*line1;
	char	*line2;
	static int position;
	int	x;/////////

	if (init_line(&line1) == NULL)
		return (NULL);
	while (find_me(line1) == 0)
	{
		if (str[position] == '\0')
		{
			x = part(fd, str, line1, &position);
			if (x == 0)
				return (NULL);
			else if (x == 1)
				return (line1);
		}
		line2 = ft_read(str, &position, line1);
		if (line2 == NULL)
			return (NULL);
		if (ft_strjoin(&line1, line2) == NULL)
			return (NULL);
	}
	return (line1);
}

// int main()
// {

// 	int fd = open("test.txt", O_RDONLY);
// 	char *str = get_next_line(fd);
// 	while(str != NULL)
// 	{
// 		printf("%s", str);
// 		str = get_next_line(fd);
// 	}
	
// }
