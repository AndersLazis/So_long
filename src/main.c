/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:43:57 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/19 19:39:20 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Render function. Reads map and re-draws image */
int	main_loop(t_game *game)
{
	int	row;
	int	col;
	int	coord_y;
	int	coord_x;

	row = 0;
	col = 0;
	coord_y = 0;
	coord_x = 0;
	while (row != game->rows)
	{
		while (col != game->columns)
		{
			if (game->map[row][col] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_grass, coord_x, coord_y);
			else if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, coord_x, coord_y);
			else if (game->map[row][col] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, coord_x, coord_y);
				PPX = col;
				PPY = row;
			}
			else if (game->map[row][col] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect, coord_x, coord_y);
			else if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, coord_x, coord_y);
			col++;
			coord_x = coord_x + 32;
		}
		col = 0;
		coord_x = 0;
		row++;
		coord_y = coord_y + 32;
	}	
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

/*добавить:*/
/*1. разрушение окна*/
/*2. очистка памяти при выходе*/
/* Юонус?*/
