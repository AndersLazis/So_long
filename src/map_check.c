/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:11:51 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/22 17:01:44 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function runs various checks for game->map validity */
int	check_map(t_game	*game, char	*av)
{	
	if (check_map_name(av) == 1)
	{
		ft_printf("Error: game->map file must have '.ber' format\n");
		exit(0);
	}
	if (check_map_geometry(game) == 1)
		exit(0);
	if (check_map_wrong_chars(game) == 1)
	{
		ft_printf("Error: game->map has invalid characters.\n");
		exit(0);
	}
	if (check_map_duplicated_chars(game) == 1)
	{
		ft_printf("Error: check number of characters.\n");
		exit(0);
	}
	if (check_map_valid_path(game) == 0)
	{
		ft_printf("Error. game->map hasn't a valid path or exit.\n");
		exit_point(game, NULL);
	}
	return (0);
}

/* This function run game->map two game->map checks:
1. whether game->map is rectangular or not
2. whether game->map is surrounded by walls or not*/

int	check_map_geometry(t_game *game)
{
	if (check_map_rectangular(game) == 1)
	{
		ft_printf("Error: game->map is not rectangular.\n");
		return (1);
	}
	else if (check_map_surrounded(game) == 1)
	{
		ft_printf("Error: game->map isn't surrounded.\n");
		return (1);
	}
	return (0);
}

/* This function checks whether game->map has wrong characters or not */
int	check_map_wrong_chars(t_game *game)
{	
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (y < game->row)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' &&
				game->map[y][x] != 'C' && game->map[y][x] != 'C' &&
					game->map[y][x] != 'E' && game->map[y][x] != 'P')
			{	
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/* This function runs several check for number of collectibles, player, exits */
int	check_map_duplicated_chars(t_game *game)
{	
	if (check_map_number_of_collectibles(game) == 1)
	{	
		ft_printf("Error: number of collectibles must be at least 1\n");
		return (1);
	}
	else if (check_map_duplicated_players(game) == 1)
	{
		ft_printf("Error: number of players must be 1\n");
		return (1);
	}
	else if (check_map_duplicated_exits(game) == 1)
	{
		ft_printf("Error: number of exits must be 1\n");
		return (1);
	}
	return (0);
}
