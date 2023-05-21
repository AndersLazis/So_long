/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game->map_check_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:34:46 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/20 14:38:55 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks whether game->map has .ber format or not*/
int	check_map_name(char	*av)
{	
	char	right_name[5];
	int		i;
	int		j;

	right_name[0] = '.';
	right_name[1] = 'b';
	right_name[2] = 'e';
	right_name[3] = 'r';
	right_name[4] = '\0';
	i = 3;
	j = strlen(av)-1;
	while (i >= 0)
	{
		if (right_name[i] != av[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

/* This function checks whether the game->map is surrounded (top wall) */
int	check_map_surrounded_top(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[0][x] != '\n' && game->map[0][x] != '\0')
	{
		if (game->map[0][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

/* This function checks whether the game->map is surrounded (from sides) */
int	check_map_surrounded_left_right_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->rows - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][game->columns - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

/* This function checks whether the game->map is surrounded (bottom wall) */
int	check_map_surrounded_bottom(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[game->rows - 1][x] != '\n' && game->map[game->rows - 1][x] != '\0')
	{
		if (game->map[game->rows - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}
