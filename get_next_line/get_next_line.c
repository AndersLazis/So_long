/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:12:41 by aputiev           #+#    #+#             */
/*   Updated: 2023/01/10 21:18:38 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *remainder);
char	*ft_get_line(char *remainder);
char	*ft_resize(char *remainder);

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remainder = ft_read(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_get_line(remainder);
	remainder = ft_resize(remainder);
	return (line);
}

char	*ft_read(int fd, char *remainder)
{
	char		*buf;
	int			bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(remainder, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			free(remainder);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buf);
	}
	free(buf);
	return (remainder);
}

char	*ft_get_line(char *remainder)
{
	char	*line;
	int		i;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] != '\n' && remainder[i])
		i++;
	if (remainder[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] != '\n' && remainder[i])
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_resize(char *remainder)
{
	char	*tmp;
	int		start;
	int		i;

	i = 0;
	start = 0;
	while (remainder[start] != '\n' && remainder[start])
		start++;
	if (!remainder[start])
	{
		free (remainder);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(remainder) - start));
	if (!tmp)
		return (NULL);
	start++;
	while (remainder[start])
	{
		tmp[i++] = remainder[start++];
	}
	tmp[i] = '\0';
	free(remainder);
	return (tmp);
}