/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:12:13 by aputiev           #+#    #+#             */
/*   Updated: 2023/01/10 21:17:58 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	uc;

	if (!s)
		return (NULL);
	str = (char *) s;
	i = 0;
	uc = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == uc)
			return (str + i);
		i++;
	}
	if (uc == '\0')
		return (str + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*jstring;
	size_t		i;
	size_t		j;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	jstring = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!jstring)
		return (NULL);
	i = -1;
	while (s1[++i])
		jstring[i] = s1[i];
	j = 0;
	while (i < ft_strlen(s1) + ft_strlen(s2) && s2[j])
		jstring[i++] = s2[j++];
	jstring[i] = '\0';
	free(s1);
	return (jstring);
}
