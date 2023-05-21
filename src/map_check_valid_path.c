/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:47:17 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/21 16:07:38 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks if there’s a valid path in the game->map. */
int	check_map_valid_path(t_game *game)
{
	int		y;
	int		x;
	t_game	test_game;

	x = 0;
	y = 0;
	test_data_initialization(&test_game, game);
	test_game.map = malloc((game->row) * sizeof(char *));
	while (y < game->row)
	{	
		test_game.map[y] = malloc((game->col + 1) * sizeof(char));
		while (game->map[y][x] != '\0')
		{	
			test_game.map[y][x] = game->map[y][x];
			x++;
		}
		test_game.map[y][x] = '\0';
		y++;
		x = 0;
	}
	if ((find_way(&test_game, test_game.ppy, test_game.ppx) == 1)
		&& (find_exit(&test_game, test_game.ppy, test_game.ppx) == 1))
		return (1);
	return (0);
}

/* Initializes data of test structure test_game
at start of find-way-algorithm */
int	test_data_initialization(t_game *test_game, t_game *game)
{
	test_game->row = game->row;
	test_game->col = game->col;
	test_game->ppx = game->ppx;
	test_game->ppy = game->ppy;
	test_game->exit_pos_x = game->exit_pos_x;
	test_game->exit_pos_y = game->exit_pos_y;
	test_game->target_items = game->target_items;
	test_game->items = 0;
	test_game->exitz = 0;
	return (0);
}
