/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game->map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:37:31 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/20 18:49:55 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/* This function counts rows in a game->map to find */
/* out how many memory we need to allocate */
int	count_map_rows(t_game	*game, char	*av)
{
	int		rows;
	char	*next_line;
	int		fd;

	rows = 0;
	if (!av)
		ft_printf("Error! Please, speicify the game->map: 'game->maps/game->map_name.ber'\n");
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error! game->map hasn't been found!\n");
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

/* Allocates game->map in memory as strings connected by string of pointers */
char	**create_map(t_game *game, char *av)
{
	int		fd;
	char	**map;

	map = malloc((game->rows) * sizeof(char *));
	if (!map)
		exit(0);
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error! game->map hasn't been found!\n");
		exit(0);
	}
	fill_map(fd, map, game->rows);
	close (fd);
	return (map);
}

/* This function writes the game->map from the file to allocated memory*/
char	**fill_map(int fd, char **map, int rows)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	j = 0;
	while (1)
	{		
		next_line = get_next_line(fd);
		map[i] = malloc((string_len(next_line) + 1) * sizeof(char));
		if (!map[i])
			exit(0);
		while (next_line[j] != '\n' && next_line[j] != '\0')
		{
			map[i][j] = next_line[j];
			j++;
		}
		map[i][j] = '\0';
		i++;
		j = 0;
		if (i == rows)
			break ;
	}
	return (map);
}
