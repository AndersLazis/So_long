/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:43:57 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/23 19:21:13 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Render function. Reads game->map and re-draws image */
int	main_loop(t_game *game)
{
	int	row;
	int	col;
	int	coord_y;

	row = 0;
	col = 0;
	coord_y = 0;
	while (row != game->row)
	{
		while (col != game->col)
		{
			put_image(game, row, col, coord_y);
			col++;
		}
		col = 0;
		row++;
		coord_y = coord_y + 50;
	}	
	return (0);
}

/* Main function */
int	main(int ac, char	**av)
{		
	t_game	game;

	check_number_of_args(ac);
	data_initialization(&game);
	count_map_rows(&game, av[1]);
	game.map = create_map(&game, av[1]);
	check_map(&game, av[1]);
	create_window(&game);
	load_xpm_image(&game);
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
	game->mlx = NULL;
	return (0);
}
