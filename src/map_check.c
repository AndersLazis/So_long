/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:11:51 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/20 17:51:19 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function runs various checks for map validity */
int	check_map(t_game	*game, char	*av)
{	
	if (check_map_name(av) == 1)
	{
		ft_printf("Error: map file must have '.ber' format\n");
		exit(0);
	}
	if (check_map_geometry(game) == 1)
		exit(0);
	if (check_map_wrong_chars(game) == 1)
	{
		ft_printf("Error: map has invalid characters.\n");
		exit(0);
	}
	if (check_map_duplicated_chars(game) == 1)
	{
		ft_printf("Error: check number of characters.\n");
		exit(0);
	}
	if (check_map_valid_path(game) == 0)
	{
		ft_printf("Error. Map hasn't a valid path or exit.\n");
		exit(0);
	}
	return (0);
}

/* This function run map two map checks:
1. whether map is rectangular or not
2. whether map is surrounded by walls or not*/

int	check_map_geometry(t_game *game)
{
	if (check_map_rectangular(game) == 1)
	{
		ft_printf("Error: map is not rectangular.\n");
		return (1);
	}
	else if (check_map_surrounded(game) == 1)
	{
		ft_printf("Error: map isn't surrounded.\n");
		return (1);
	}
	return (0);
}

/* This function checks whether map has wrong characters or not */
int	check_map_wrong_chars(t_game *game)
{	
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (y < game->rows)
	{
		while (MAP[y][x] != '\0')
		{
			if (MAP[y][x] != '1' && MAP[y][x] != '0' &&
				MAP[y][x] != 'C' && MAP[y][x] != 'C' &&
					MAP[y][x] != 'E' && MAP[y][x] != 'P')
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
