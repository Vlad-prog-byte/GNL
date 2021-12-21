/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:10:13 by cayesha           #+#    #+#             */
/*   Updated: 2021/11/20 19:14:43 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	return (size);
}

char	*ft_strjoin(char **s1, char *s2)
{
	int		size1;
	int		size2;
	char	*str;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen(*s1);
	size2 = ft_strlen(s2);
	str = (char *)malloc(size1 + size2 + 1);
	if (str == NULL)
		return (NULL);
	while ((*s1)[i])
		str[count++] = (*s1)[i++];
	i = 0;
	while (s2[i])
		str[count++] = s2[i++];
	str[count] = '\0';
	free((*s1));
	free(s2);
	*s1 = str; 
	return (str);
}

char *ft_read(char *str, int *i, char *line1)
{
	int		j;
	char	*line;
	int	last_i;

	last_i = 0;
	j = *i;
	while (str[j] && str[j] != '\n')
		j++;
	if (str[j] == '\n')
		j++;
	line = (char *)malloc(j - *i + 1);
	if (line == NULL)
		{
			free(line1);
			return line;
		}
	while (*i != j)
	{
		line[last_i] = str[*i];
		(*i)++;
		last_i++;
	}
	line[last_i] = '\0';
	return (line);
}