/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:34:58 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/22 18:28:25 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Calculates length of string till \n sign */
int	string_len(char *str)
{	
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i + 1);
}

int	exit_point(t_game *game, t_game *test_game)
{
	int	rows;

	rows = 0;
	if(game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if(game->mlx)
	{
	mlx_destroy_image(game->mlx, game->img_grass);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	free(game->mlx);
	}
	while (rows < game->row - 1)
		free(game->map[rows++]);
	free(game->map);
	if(test_game)
	{
		while (rows < test_game->row - 1)
		free(test_game->map[rows++]);
		free(test_game->map);
	}
	exit(0);
}

int	free_test_game(t_game *test_game)
{
	int	rows;

	rows = 0;
	if(test_game)
	{
		while (rows < test_game->row - 1)
		free(test_game->map[rows++]);
		free(test_game->map);
	}
	return (0);
}


