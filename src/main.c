/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:43:57 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/20 18:12:04 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Render function. Reads map and re-draws image */
int	main_loop(t_game *game)
{
	int	row;
	int	col;
	int	coord_y;

	row = 0;
	col = 0;
	Y = 0;
	while (row != game->rows)
	{
		while (col != game->columns)
		{
			put_image(game, row, col, coord_y);
			col++;
		}
		col = 0;
		row++;
		Y = Y + 32;
	}	
	return (0);
}

/* This function put image depends of a map sign: 0 or 1 or P ...etc.*/
int	put_image(t_game *game, int row, int col, int coord_y)
{
	if (MAP[row][col] == '0')
		mlx_put_image_to_window(MLX, WINDOW, game->img_grass, col * 32, Y);
	else if (MAP[row][col] == '1')
		mlx_put_image_to_window(MLX, WINDOW, game->img_wall, col * 32, Y);
	else if (MAP[row][col] == 'P')
	{
		mlx_put_image_to_window(MLX, WINDOW, game->img_player, col * 32, Y);
		PPX = col;
		PPY = row;
	}
	else if (MAP[row][col] == 'C')
		mlx_put_image_to_window(MLX, WINDOW, game->img_collect, col * 32, Y);
	else if (MAP[row][col] == 'E')
		mlx_put_image_to_window(MLX, WINDOW, game->img_exit, col * 32, Y);
	return (0);
}

/* Main function */
int	main(int ac, char	**av)
{		
	t_game	game;
	int		img_width;
	int		img_height;

	img_width = 32;
	img_height = 32;
	check_number_of_args(ac);
	data_initialization(&game);
	count_map_rows(&game, av[1]);
	game.map = create_map(&game, av[1]);
	check_map(&game, av[1]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_SIZE, "play_me!");
	GRASS = mlx_xpm_file_to_image(game.mlx, "images/grass.xpm", IMG_SIZE);
	WALL = mlx_xpm_file_to_image(game.mlx, "images/wall.xpm", IMG_SIZE);
	PLAYER = mlx_xpm_file_to_image(game.mlx, "images/cat.xpm", IMG_SIZE);
	ITEM = mlx_xpm_file_to_image(game.mlx, "images/collect.xpm", IMG_SIZE);
	EXIT = mlx_xpm_file_to_image(game.mlx, "images/wall_n.xpm", IMG_SIZE);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &release_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}

/* Checks number of entered arguments */
int	check_number_of_args(int ac)
{
	if (ac != 2)
	{
		ft_printf("Error! Please, specify the map path\n");
		exit(0);
	}	
	return (0);
}

/* Initializes data at start of program */
int	data_initialization(t_game *game)
{
	game->pres_but_a_count = 0;
	game->pres_but_d_count = 0;
	game->pres_but_w_count = 0;
	game->pres_but_s_count = 0;
	game->collectibles = 0;
	game->target_collectibles = 0;
	game->moves = 0;
	return (0);
}

int exit_point(t_game *game)
{
	int	rows;

	rows = 0;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	while (rows< game->rows - 1)
		free(game->map[rows++]);
	free(game->map);
	exit(0);
}

/*добавить:*/
/*1. разрушение окна*/
/*2. очистка памяти при выходе*/
/* Юонус?*/
