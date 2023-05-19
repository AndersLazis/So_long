/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:11:51 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/19 16:44:36 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game	*game, char	*av)
{
	if (check_map_name(av) == 1)
	{
		ft_printf("Error: map file must have be the '.ber' format\n");
		exit(0);
	}	
	game->moves = 0;
	if (check_map_rectangular(game) == 1)
	{
		ft_printf("Error: map is not rectangular.\n");
		exit(0);
	}
	else if (check_map_surrounded(game) == 1)
	{
		ft_printf("Error: map isn't surrounded.\n");
		exit(0);
	}
	else if (check_map_wrong_chars(game) == 1)
	{
		ft_printf("Error: map has invalid characters.\n");
		exit(0);
	}
	else if (check_map_duplicated_chars(game) == 1)
	{
		ft_printf("Error: check number of characters.\n");
		exit(0);
	}
	else if (check_map_valid_path(game) == 0)
	{
		ft_printf("Error. Map hasn't a valid path or exit.\n");
		exit(0);
	}
	return (0);
}

int	check_map_name(char	*av)
{	
	char	*right_name = ".ber";
	int		i;
	int		j;

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

int	check_map_rectangular(t_game *game)
{	
	int	columns;
	int	rows;

	columns = 0;
	rows = 0;
	game->columns = strlen(game->map[0]);
	while (rows < game->rows)
	{
		while (game->map[rows][columns] != '\0' && game->map[rows][columns] != '\n')
			columns++;
		if (columns != (game->columns))
			return (1);
		rows++;
		columns = 0;
	}
	return (0);
}

int	check_map_surrounded(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[0][x] != '\n' && game->map[0][x] != '\0')
	{
		if (game->map[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (y < game->rows - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][game->columns - 1] != '1')
			return (1);
		y++;
	}
	x = 0;
	while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
	{
		if (game->map[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

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
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' && game->map[y][x] != 'C' && game->map[y][x] != 'C'&& game->map[y][x] != 'E' && game->map[y][x] != 'P')
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

int	check_map_duplicated_chars(t_game *game)
{	
	int	i;
	int	x;
	int	y;
	int	exit;
	int	player;
	int	collectible;

	i = 0;
	x = 0;
	y = 0;
	exit = 0;
	player = 0;
	collectible = 0;
	while (y < game->rows)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'C')
				collectible++;
			else if (game->map[y][x] == 'P')
			{
				player++;
				PPX = x;
				PPY = y;
			}
			else if (game->map[y][x] == 'E')
			{
				exit++;
				game->exit_pos_x = x;
				game->exit_pos_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	game->target_collectibles = collectible;
	if (exit != 1)
	{
		ft_printf("Error: number of exit must be 1\n");
		return (1);
	}
	else if (player != 1)
	{
		ft_printf("Error: number of players must be 1\n");
		return (1);
	}
	else if (collectible < 1)
	{
		ft_printf("Error: number of collectibles must be at least 1\n");
		return (1);
	}
	return (0);
}
