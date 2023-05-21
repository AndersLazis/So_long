/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:43:57 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/21 16:05:17 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Render function. Reads game->map and re-draws image */
int	main_loop(t_game *game)
{
	int	row;
	int	col;
	int	coord_y;

	row = 0;
	col = 0;
	coord_y = 0;
	while (row != game->rows)
	{
		while (col != game->columns)
		{
			put_image(game, row, col, coord_y);
			col++;
		}
		col = 0;
		row++;
		coord_y = coord_y + 32;
	}	
	return (0);
}

/* This function put image depends of a game->map sign: 0 or 1 or P ...etc.*/
int	put_image(t_game *game, int row, int col, int coord_y)
{
	if (game->map[row][col] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_grass, col * 32, coord_y);
	else if (game->map[row][col] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, col * 32, coord_y);
	else if (game->map[row][col] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, col * 32, coord_y);
		game->ppx = col;
		game->ppy = row;
	}
	else if (game->map[row][col] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect, col * 32, coord_y);
	else if (game->map[row][col] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, col * 32, coord_y);
	return (0);
}

/* Main function */
int	main(int ac, char	**av)
{		
	t_game	game;
	int		img_w;
	int		img_h;

	img_w = 32;
	img_h = 32;
	check_number_of_args(ac);
	data_initialization(&game);
	count_map_rows(&game, av[1]);
	game.map = create_map(&game, av[1]);
	check_map(&game, av[1]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.columns * 32), (game.rows * 32), "play_me!");
	game.img_grass = mlx_xpm_file_to_image(game.mlx, GRASS, &img_w, &img_h);
	game.img_wall = mlx_xpm_file_to_image(game.mlx, WALL, &img_w, &img_h);
	game.img_player = mlx_xpm_file_to_image(game.mlx, PLAYER, &img_w, &img_h);
	game.img_collect = mlx_xpm_file_to_image(game.mlx, ITEM, &img_w, &img_h);
	game.img_exit = mlx_xpm_file_to_image(game.mlx, EXIT, &img_w, &img_h);
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
		ft_printf("Error! Please, specify the game->map path\n");
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
	game->items = 0;
	game->target_items = 0;
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
	while (rows < game->rows - 1)
		free(game->map[rows++]);
	free(game->map);
	exit(0);
}

/*добавить:*/
/*1. разрушение окна*/
/* Убрать  strlen!!!*/
/*2. очистка памяти при выходе*/
/* Юонус?*/
