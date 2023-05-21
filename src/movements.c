/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:28:55 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/21 14:20:51 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_game *game)
{	
	if (game->map[game->pl_pos_y][game->pl_pos_x + 1] == '0' && !prevent_double_key_press(game, KEY_D))
	{
		game->map[game->pl_pos_y][game->pl_pos_x + 1] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		if ((game->exit_pos_y == game->pl_pos_y) && (game->exit_pos_x == game->pl_pos_x))
			game->map[game->pl_pos_y][game->pl_pos_x] = 'E';
	}
	else if (game->map[game->pl_pos_y][game->pl_pos_x + 1] == 'C' && !prevent_double_key_press(game, KEY_D))
	{
		game->map[game->pl_pos_y][game->pl_pos_x + 1] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		if ((game->exit_pos_y == game->pl_pos_y) && (game->exit_pos_x == game->pl_pos_x))
			game->map[game->pl_pos_y][game->pl_pos_x] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[game->pl_pos_y][game->pl_pos_x + 1] == 'E' && !prevent_double_key_press(game, KEY_D))
	{
		game->map[game->pl_pos_y][game->pl_pos_x + 1] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_left(t_game *game)
{	
	if (game->map[game->pl_pos_y][game->pl_pos_x - 1] == '0' && !prevent_double_key_press(game, KEY_A))
	{
		game->map[game->pl_pos_y][game->pl_pos_x - 1] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		if ((game->exit_pos_y == game->pl_pos_y) && (game->exit_pos_x == game->pl_pos_x))
			game->map[game->pl_pos_y][game->pl_pos_x] = 'E';
	}
	else if (game->map[game->pl_pos_y][game->pl_pos_x - 1] == 'C' && !prevent_double_key_press(game, KEY_A))
	{
		game->map[game->pl_pos_y][game->pl_pos_x - 1] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		if ((game->exit_pos_y == game->pl_pos_y) && (game->exit_pos_x == game->pl_pos_x))
			game->map[game->pl_pos_y][game->pl_pos_x] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[game->pl_pos_y][game->pl_pos_x - 1] == 'E' && !prevent_double_key_press(game, KEY_A))
	{
		game->map[game->pl_pos_y][game->pl_pos_x - 1] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_up(t_game *game)
{	
	if (game->map[game->pl_pos_y - 1][game->pl_pos_x] == '0' && !prevent_double_key_press(game, KEY_W))
	{
		game->map[game->pl_pos_y - 1][game->pl_pos_x] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		if ((game->exit_pos_y == game->pl_pos_y) && (game->exit_pos_x == game->pl_pos_x))
			game->map[game->pl_pos_y][game->pl_pos_x] = 'E';
	}
	else if (game->map[game->pl_pos_y - 1][game->pl_pos_x] == 'C' && !prevent_double_key_press(game, KEY_W))
	{
		game->map[game->pl_pos_y - 1][game->pl_pos_x] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		if ((game->exit_pos_y == game->pl_pos_y) && (game->exit_pos_x == game->pl_pos_x))
			game->map[game->pl_pos_y][game->pl_pos_x] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[game->pl_pos_y - 1][game->pl_pos_x] == 'E' && !prevent_double_key_press(game, KEY_W))
	{
		game->map[game->pl_pos_y - 1][game->pl_pos_x] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_down(t_game *game)
{	
	if (game->map[game->pl_pos_y + 1][game->pl_pos_x] == '0' && !prevent_double_key_press(game, KEY_S))
	{
		game->map[game->pl_pos_y + 1][game->pl_pos_x] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		if ((game->exit_pos_y == game->pl_pos_y) && (game->exit_pos_x == game->pl_pos_x))
			game->map[game->pl_pos_y][game->pl_pos_x] = 'E';
	}
	else if (game->map[game->pl_pos_y + 1][game->pl_pos_x] == 'C' && !prevent_double_key_press(game, KEY_S))
	{
		game->map[game->pl_pos_y + 1][game->pl_pos_x] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		if ((game->exit_pos_y == game->pl_pos_y) && (game->exit_pos_x == game->pl_pos_x))
			game->map[game->pl_pos_y][game->pl_pos_x] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[game->pl_pos_y + 1][game->pl_pos_x] == 'E' && !prevent_double_key_press(game, KEY_S))
	{
		game->map[game->pl_pos_y + 1][game->pl_pos_x] = 'P';
		game->map[game->pl_pos_y][game->pl_pos_x] = '0';
		if ((game->exit_pos_y == game->pl_pos_y) && (game->exit_pos_x == game->pl_pos_x))
			game->map[game->pl_pos_y][game->pl_pos_x] = 'E';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}
