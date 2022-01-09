/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:36:41 by cayesha           #+#    #+#             */
/*   Updated: 2022/01/09 15:41:02 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char **s1, char *s2);
char	*ft_read(char *str, int *i, char *line1);
char	*get_next_line(int fd);
char	*init_line(char **line);
int		part(int fd, char *str, char *line1, int *position);
int		find_me(const char *line);
#endif