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

char * get_next_line(int fd)
{
	static char str[BUFFER_SIZE + 1];
	char	*line1;
	char	*line2;
	static int position;
	
	line1 = (char *)malloc(1);
	if (line1 == NULL)
		return (NULL);
	else
		line1[0] = '\0';
	while (1)
	{
		if (str[position] == '\0')
		{
			int size_str = read(fd, str, BUFFER_SIZE);
			if (size_str <= 0)
				{
					if (line1 != NULL && line1[0] == '\0')
					{
						free(line1);
						return (NULL);
					}
					else
						return (line1);
				}
			else
			{
				str[size_str] = '\0';
				position = 0;
			}
		}
		line2 = ft_read(str, &position);
		if (line2 == NULL)
		{
			free(line1);
			return (NULL);
		}
		else
			line1 = ft_strjoin(line1, line2);
		if (line1 == NULL)
			return (NULL);
		if (line1[ft_strlen(line1) - 1] == '\n')
				return (line1);
		else
			continue ;
	}
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
