/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_way_and_exit_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:04:48 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/19 17:07:24 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_way(t_game	*test_game, int ppy, int ppx)
{	
	if ((TEST_TARGET) == (test_game->collectibles))
		return (1);
	if (TEST_MAP[ppy][ppx] == 'C')
	{
		TEST_MAP[ppy][ppx] = '0';
		test_game->collectibles++;
	}
	if ((TEST_TARGET == test_game->collectibles) && (TEST_MAP[ppy][ppx] == '+'))
		return (0);
	if (TEST_MAP[ppy][ppx + 1] == '0' || TEST_MAP[ppy][ppx + 1] == 'C' || TEST_MAP[ppy][ppx + 1] == 'E')
	{	
		TEST_MAP[ppy][ppx] = '+';
		if (ppx < (test_game->columns - 2))
			find_way(test_game, ppy, ppx + 1);
	}
	if (TEST_MAP[ppy][ppx - 1] == '0' || TEST_MAP[ppy][ppx - 1] == 'C' || TEST_MAP[ppy][ppx - 1] == 'E')
	{
		TEST_MAP[ppy][ppx] = '+';
		if (ppx > 1)
			find_way(test_game, ppy, ppx - 1);
	}
	if (TEST_MAP[ppy + 1][ppx] == '0' || TEST_MAP[ppy + 1][ppx] == 'C' || TEST_MAP[ppy + 1][ppx] == 'E')
	{
		TEST_MAP[ppy][ppx] = '+';
		if (ppy < (test_game->rows - 1))
			find_way(test_game, ppy + 1, ppx);
	}
	if (TEST_MAP[ppy - 1][ppx] == '0' || TEST_MAP[ppy - 1][ppx] == 'C' || TEST_MAP[ppy - 1][ppx] == 'E')
	{
		TEST_MAP[ppy][ppx] = '+';
		if (ppy > 1)
			find_way(test_game, ppy - 1, ppx);
	}
	if ((TEST_TARGET) == (test_game->collectibles))
		return (1);
	return (0);
}

int	find_exit(t_game *test_game, int ppy, int ppx)
{	
	TEST_MAP[test_game->exit_pos_y][test_game->exit_pos_x] = 'E';
	if (test_game->exitz == 1)
		return (1);
	if (TEST_MAP[ppy][ppx] == 'E')
		test_game->exitz = 1;
	if (TEST_MAP[ppy][ppx] == 'A')
		return (0);
	if (TEST_MAP[ppy][ppx + 1] != '1' && TEST_MAP[ppy][ppx + 1] != 'A')
	{	
		TEST_MAP[ppy][ppx] = 'A';
		if (ppx < (test_game->columns - 2))
			find_exit(test_game, ppy, ppx + 1);
	}
	if (TEST_MAP[ppy][ppx - 1] != '1' && TEST_MAP[ppy][ppx - 1] != 'A')
	{
		TEST_MAP[ppy][ppx] = 'A';
		if (ppx > 1)
			find_exit(test_game, ppy, ppx - 1);
	}
	if (TEST_MAP[ppy + 1][ppx] != '1' && TEST_MAP[ppy + 1][ppx] != 'A')
	{
		TEST_MAP[ppy][ppx] = 'A';
		if (ppy < (test_game->rows - 1))
			find_exit(test_game, ppy + 1, ppx);
	}
	if (TEST_MAP[ppy - 1][ppx] != '1' && TEST_MAP[ppy - 1][ppx] != 'A')
	{
		TEST_MAP[ppy][ppx] = 'A';
		if (ppy > 1)
			find_exit(test_game, ppy - 1, ppx);
	}
	if (test_game->exitz == 1)
		return (1);
	return (0);
}

int	check_map_valid_path(t_game *game)
{
	int		y;
	int		x;
	t_game	test_game;

	x = 0;
	y = 0;
	test_game.rows = game->rows;
	test_game.columns = game->columns;
	test_game.pl_pos_x = PPX;
	test_game.pl_pos_y = PPY;
	test_game.exit_pos_x = game->exit_pos_x;
	test_game.exit_pos_y = game->exit_pos_y;
	test_game.target_collectibles = game->target_collectibles;
	test_game.collectibles = 0;
	test_game.exitz = 0;
	test_game.map = malloc((game->rows) * sizeof(char*));
	while (y < game->rows)
	{	
		test_game.map[y] = malloc((game->columns + 1) * sizeof(char));
		while (game->map[y][x] != '\0')
		{	
			test_game.map[y][x] = game->map[y][x];
			x++;
		}
		test_game.map[y][x] = '\0';
		y++;
		x = 0;
	}
	if ((find_way(&test_game, test_game.pl_pos_y, test_game.pl_pos_x) == 1) && (find_exit(&test_game, test_game.pl_pos_y, test_game.pl_pos_x) == 1))
	{	
		ft_printf("THE PATH IS VALID\n");
		return (1);
	}
	x = 0;
	y = 0;
	while (y < test_game.rows)
	{	
		while (test_game.map[y][x] != '\0')
		{	
			test_game.map[y][x] = test_game.map[y][x];
			x++;
		}
		test_game.map[y][x] = '\0';
		y++;
		x = 0;
	}	
	return (0);
}
