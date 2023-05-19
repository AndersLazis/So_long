/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:37:31 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/19 19:38:05 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function counts rows in a map to find */
/* out how many memory we need to allocate */
int	count_map_rows(t_game	*game, char	*av)
{
	int		rows;
	char	*next_line;
	int		fd;

	rows = 0;
	if (!av)
		ft_printf("Error! Please, speicify the map: 'maps/map_name.ber'\n");
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error! Map hasn't been found!\n");
		exit(0);
	}
	while (1)
	{		
		next_line = get_next_line(fd);
		if (!next_line)
			break ;
		rows++;
	}
	close (fd);
	game->rows = rows;
	return (0);
}

/* Allocates map in memory as strings connected by string of pointers */
char	**create_map(t_game *game, char *av)
{
	int		fd;
	int		i;
	int		j;
	char	**map;
	char	*next_line;

	i = 0;
	j = 0;
	map = malloc((game->rows) * sizeof (char*));
	if (!map)
		exit(0);
	fd = open(av, O_RDONLY);
	while (1)
	{		
		next_line = get_next_line(fd);
		map[i] = malloc((string_len(next_line) + 1) * sizeof(char));
		while (next_line[j] != '\n' && next_line[j] != '\0')
		{
			map[i][j] = next_line[j];
			j++;
		}
		map[i][j] = '\0';
		i++;
		j = 0;
		if (i == game->rows)
			break;
	}
	close (fd);
	return (map);
}
