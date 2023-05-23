/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:46:29 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/23 19:56:31 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	create_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_point(game, NULL);
	game->win = mlx_new_window(game->mlx, (game->col * 50),
			(game->row * 50), "GAME");
	if (!game->win)
		exit_point(game, NULL);
	return (0);
}

int	load_xpm_image(t_game *game)
{
	int		img_w;
	int		img_h;

	img_w = 50;
	img_h = 50;
	game->img_grass = mlx_xpm_file_to_image(game->mlx, GRASS, &img_w, &img_h);
	if (!game->img_grass)
		exit (0);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL, &img_w, &img_h);
	if (!game->img_wall)
		exit (0);
	game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER, &img_w, &img_h);
	if (!game->img_player)
		exit (0);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, ITEM, &img_w, &img_h);
	if (!game->img_collect)
		exit (0);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT, &img_w, &img_h);
	if (!game->img_exit)
		exit (0);
	return (0);
}

/* This function put image depends of a game->map sign: 0 or 1 or P ...etc.*/
int	put_image(t_game *game, int row, int col, int coord_y)
{
	if (game->map[row][col] == '0')
	{
		if (!mlx_put_image_to_window(game->mlx, game->win, game->img_grass,
				col * 50, coord_y))
			exit(0);
	}
	else if (game->map[row][col] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			col * 50, coord_y);
	else if (game->map[row][col] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			col * 50, coord_y);
		game->ppx = col;
		game->ppy = row;
	}
	else if (game->map[row][col] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect,
			col * 50, coord_y);
	else if (game->map[row][col] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			col * 50, coord_y);
	return (0);
}
