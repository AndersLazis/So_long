/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:47:17 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/20 17:47:34 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/***********************************************************************/
/* This function checks if there’s a valid path in the map. */
int	check_map_valid_path(t_game *game)
{
	int		y;
	int		x;
	t_game	test_game;

	x = 0;
	y = 0;
	test_data_initialization(&test_game, game);
	test_game.map = malloc((game->rows) * sizeof(char *));
	while (y < game->rows)
	{	
		test_game.map[y] = malloc((game->columns + 1) * sizeof(char));
		while (MAP[y][x] != '\0')
		{	
			test_game.map[y][x] = MAP[y][x];
			x++;
		}
		test_game.map[y][x] = '\0';
		y++;
		x = 0;
	}
	if ((find_way(&test_game, test_game.pl_pos_y, test_game.pl_pos_x) == 1)
		&& (find_exit(&test_game, test_game.pl_pos_y, test_game.pl_pos_x) == 1))
		return (1);
	return (0);
}

/* Initializes data of test structure test_game
at start of find-way-algorithm */
int	test_data_initialization(t_game *test_game, t_game *game)
{
	test_game->rows = game->rows;
	test_game->columns = game->columns;
	test_game->pl_pos_x = PPX;
	test_game->pl_pos_y = PPY;
	test_game->exit_pos_x = game->exit_pos_x;
	test_game->exit_pos_y = game->exit_pos_y;
	test_game->target_collectibles = game->target_collectibles;
	test_game->collectibles = 0;
	test_game->exitz = 0;
	return (0);
}
