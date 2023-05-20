/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_way_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:04:48 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/20 17:49:24 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks if all aollectibles are reacheable or not */
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
	check_right_cell_for_way(test_game, ppy, ppx);
	check_left_cell_for_way(test_game, ppy, ppx);
	check_down_cell_for_way(test_game, ppy, ppx);
	check_up_cell_for_way(test_game, ppy, ppx);
	if ((TEST_TARGET) == (test_game->collectibles))
		return (1);
	return (0);
}

/***********************************************************************/
/* These functions checks if it's possible to move to next cell */
int	check_right_cell_for_way(t_game *test_game, int ppy, int ppx)
{
	if (TEST_MAP[ppy][ppx + 1] == '0' || TEST_MAP[ppy][ppx + 1] == 'C'
	|| TEST_MAP[ppy][ppx + 1] == 'E')
	{	
		TEST_MAP[ppy][ppx] = '+';
		if (ppx < (test_game->columns - 2))
			find_way(test_game, ppy, ppx + 1);
	}
	return (0);
}

int	check_left_cell_for_way(t_game *test_game, int ppy, int ppx)
{
	if (TEST_MAP[ppy][ppx - 1] == '0' || TEST_MAP[ppy][ppx - 1] == 'C'
	|| TEST_MAP[ppy][ppx - 1] == 'E')
	{
		TEST_MAP[ppy][ppx] = '+';
		if (ppx > 1)
			find_way(test_game, ppy, ppx - 1);
	}
	return (0);
}

int	check_down_cell_for_way(t_game *test_game, int ppy, int ppx)
{
	if (TEST_MAP[ppy + 1][ppx] == '0' || TEST_MAP[ppy + 1][ppx] == 'C'
	|| TEST_MAP[ppy + 1][ppx] == 'E')
	{
		TEST_MAP[ppy][ppx] = '+';
		if (ppy < (test_game->rows - 1))
			find_way(test_game, ppy + 1, ppx);
	}
	return (0);
}

int	check_up_cell_for_way(t_game *test_game, int ppy, int ppx)
{
	if (TEST_MAP[ppy - 1][ppx] == '0' || TEST_MAP[ppy - 1][ppx] == 'C'
	|| TEST_MAP[ppy - 1][ppx] == 'E')
	{
		TEST_MAP[ppy][ppx] = '+';
		if (ppy > 1)
			find_way(test_game, ppy - 1, ppx);
	}
	return (0);
}
