/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:08:17 by aeloyan           #+#    #+#             */
/*   Updated: 2022/06/20 15:30:38 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (start >= (unsigned int)my_strlen(s))
		return (0);
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (0);
	my_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		bufer[BUFFER_SIZE + 1];
	int			i;

	if (my_strchr(line, '\n'))
		return (my_strcut(&line));
	while (!my_strchr(line, '\n'))
	{
		i = read(fd, bufer, BUFFER_SIZE);
		if (i < 0)
			return (0);
		if (i == 0)
			return (my_strcut(&line));
		bufer[i] = '\0';
		line = my_strjoin(line, bufer);
	}
	return (my_strcut(&line));
}
