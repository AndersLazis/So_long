/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exit_finder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:29:49 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/20 17:41:56 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function searches for exit */
int	find_exit(t_game *test_game, int ppy, int ppx)
{	
	TEST_MAP[test_game->exit_pos_y][test_game->exit_pos_x] = 'E';
	if (test_game->exitz == 1)
		return (1);
	if (TEST_MAP[ppy][ppx] == 'E')
		test_game->exitz = 1;
	if (TEST_MAP[ppy][ppx] == 'A')
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
	if (TEST_MAP[ppy][ppx + 1] != '1' && TEST_MAP[ppy][ppx + 1] != 'A')
	{	
		TEST_MAP[ppy][ppx] = 'A';
		if (ppx < (test_game->columns - 2))
			find_exit(test_game, ppy, ppx + 1);
	}
	return (0);
}

int	check_left_cell_for_exit(t_game *test_game, int ppy, int ppx)
{
	if (TEST_MAP[ppy][ppx - 1] != '1' && TEST_MAP[ppy][ppx - 1] != 'A')
	{
		TEST_MAP[ppy][ppx] = 'A';
		if (ppx > 1)
			find_exit(test_game, ppy, ppx - 1);
	}
	return (0);
}

int	check_down_cell_for_exit(t_game *test_game, int ppy, int ppx)
{
	if (TEST_MAP[ppy + 1][ppx] != '1' && TEST_MAP[ppy + 1][ppx] != 'A')
	{
		TEST_MAP[ppy][ppx] = 'A';
		if (ppy < (test_game->rows - 1))
			find_exit(test_game, ppy + 1, ppx);
	}
	return (0);
}

int	check_up_cell_for_exit(t_game *test_game, int ppy, int ppx)
{
	if (TEST_MAP[ppy - 1][ppx] != '1' && TEST_MAP[ppy - 1][ppx] != 'A')
	{
		TEST_MAP[ppy][ppx] = 'A';
		if (ppy > 1)
			find_exit(test_game, ppy - 1, ppx);
	}
	return (0);
}
