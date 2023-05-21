/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game->map_exit_finder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:29:49 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/21 14:20:19 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function searches for exit */
int	find_exit(t_game *test_game, int ppy, int ppx)
{	
	test_game->map[test_game->exit_pos_y][test_game->exit_pos_x] = 'E';
	if (test_game->exitz == 1)
		return (1);
	if (test_game->map[ppy][ppx] == 'E')
		test_game->exitz = 1;
	if (test_game->map[ppy][ppx] == 'A')
		return (0);
	check_right_cell_for_exit(test_game, ppy, ppx);
	check_left_cell_for_exit(test_game, ppy, ppx);
	check_down_cell_for_exit(test_game, ppy, ppx);
	check_up_cell_for_exit(test_game, ppy, ppx);
	if (test_game->exitz == 1)
		return (1);
	return (0);
}

/***********************************************************************/
/* These functions checks next to plyer cells for exit */
int	check_right_cell_for_exit(t_game *test_game, int ppy, int ppx)
{
	if (test_game->map[ppy][ppx + 1] != '1' && test_game->map[ppy][ppx + 1] != 'A')
	{	
		test_game->map[ppy][ppx] = 'A';
		if (ppx < (test_game->columns - 2))
			find_exit(test_game, ppy, ppx + 1);
	}
	return (0);
}

int	check_left_cell_for_exit(t_game *test_game, int ppy, int ppx)
{
	if (test_game->map[ppy][ppx - 1] != '1' && test_game->map[ppy][ppx - 1] != 'A')
	{
		test_game->map[ppy][ppx] = 'A';
		if (ppx > 1)
			find_exit(test_game, ppy, ppx - 1);
	}
	return (0);
}

int	check_down_cell_for_exit(t_game *test_game, int ppy, int ppx)
{
	if (test_game->map[ppy + 1][ppx] != '1' && test_game->map[ppy + 1][ppx] != 'A')
	{
		test_game->map[ppy][ppx] = 'A';
		if (ppy < (test_game->rows - 1))
			find_exit(test_game, ppy + 1, ppx);
	}
	return (0);
}

int	check_up_cell_for_exit(t_game *test_game, int ppy, int ppx)
{
	if (test_game->map[ppy - 1][ppx] != '1' && test_game->map[ppy - 1][ppx] != 'A')
	{
		test_game->map[ppy][ppx] = 'A';
		if (ppy > 1)
			find_exit(test_game, ppy - 1, ppx);
	}
	return (0);
}
