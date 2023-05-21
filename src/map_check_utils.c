/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:26:55 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/21 15:56:51 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks whether game->map is rectangular or not */
int	check_map_rectangular(t_game *game)
{	
	int	columns;
	int	rows;

	columns = 0;
	rows = 0;
	game->columns = strlen(game->map[0]);
	while (rows < game->rows)
	{
		while (game->map[rows][columns] != '\0'
		&& game->map[rows][columns] != '\n')
			columns++;
		if (columns != (game->columns))
			return (1);
		rows++;
		columns = 0;
	}
	return (0);
}

/* This function checks whether game->map is surrounded by walls or not */
int	check_map_surrounded(t_game *game)
{
	if (check_map_surrounded_top(game) == 1
		|| check_map_surrounded_left_right_walls(game) == 1
		|| check_map_surrounded_bottom(game) == 1)
		return (1);
	return (0);
}

/* This function checks if number of collectibles at least 1 */
int	check_map_number_of_collectibles(t_game *game)
{	
	int	i;
	int	x;
	int	y;
	int	collectible;

	i = 0;
	x = 0;
	y = 0;
	collectible = 0;
	while (y < game->rows)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'C')
				collectible++;
			x++;
		}
		x = 0;
		y++;
	}
	game->target_items = collectible;
	if (collectible < 1)
		return (1);
	return (0);
}

/* This function checks if number of players is 1 */
int	check_map_duplicated_players(t_game *game)
{	
	int	x;
	int	y;
	int	player;

	x = 0;
	y = 0;
	player = 0;
	while (y < game->rows)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
			{
				player++;
				game->ppx = x;
				game->ppy = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (player != 1)
		return (1);
	return (0);
}

/* This function checks if number of exits is 1 */
int	check_map_duplicated_exits(t_game *game)
{	
	int	x;
	int	y;
	int	exit;

	x = 0;
	y = 0;
	exit = 0;
	while (y < game->rows)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'E')
			{
				exit++;
				game->exit_pos_x = x;
				game->exit_pos_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (exit != 1)
		return (1);
	return (0);
}
