/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_way_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:04:48 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/21 16:07:38 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks if all aollectibles are reacheable or not */
int	find_way(t_game	*test_game, int ppy, int ppx)
{	
	if ((test_game->target_items) == (test_game->items))
		return (1);
	if (test_game->map[ppy][ppx] == 'C')
	{
		test_game->map[ppy][ppx] = '0';
		test_game->items++;
	}
	if ((test_game->target_items == test_game->items)
		&& (test_game->map[ppy][ppx] == '+'))
		return (0);
	check_right_cell_for_way(test_game, ppy, ppx);
	check_left_cell_for_way(test_game, ppy, ppx);
	check_down_cell_for_way(test_game, ppy, ppx);
	check_up_cell_for_way(test_game, ppy, ppx);
	if ((test_game->target_items) == (test_game->items))
		return (1);
	return (0);
}

/***********************************************************************/
/* These functions checks if it's possible to move to next cell */
int	check_right_cell_for_way(t_game *test_game, int ppy, int ppx)
{
	if (test_game->map[ppy][ppx + 1] == '0'
		|| test_game->map[ppy][ppx + 1] == 'C'
		|| test_game->map[ppy][ppx + 1] == 'E')
	{	
		test_game->map[ppy][ppx] = '+';
		if (ppx < (test_game->col - 2))
			find_way(test_game, ppy, ppx + 1);
	}
	return (0);
}

int	check_left_cell_for_way(t_game *test_game, int ppy, int ppx)
{
	if (test_game->map[ppy][ppx - 1] == '0'
		|| test_game->map[ppy][ppx - 1] == 'C'
		|| test_game->map[ppy][ppx - 1] == 'E')
	{
		test_game->map[ppy][ppx] = '+';
		if (ppx > 1)
			find_way(test_game, ppy, ppx - 1);
	}
	return (0);
}

int	check_down_cell_for_way(t_game *test_game, int ppy, int ppx)
{
	if (test_game->map[ppy + 1][ppx] == '0'
		|| test_game->map[ppy + 1][ppx] == 'C'
		|| test_game->map[ppy + 1][ppx] == 'E')
	{
		test_game->map[ppy][ppx] = '+';
		if (ppy < (test_game->row - 1))
			find_way(test_game, ppy + 1, ppx);
	}
	return (0);
}

int	check_up_cell_for_way(t_game *test_game, int ppy, int ppx)
{
	if (test_game->map[ppy - 1][ppx] == '0'
		|| test_game->map[ppy - 1][ppx] == 'C'
		|| test_game->map[ppy - 1][ppx] == 'E')
	{
		test_game->map[ppy][ppx] = '+';
		if (ppy > 1)
			find_way(test_game, ppy - 1, ppx);
	}
	return (0);
}
