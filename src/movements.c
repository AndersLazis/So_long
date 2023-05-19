/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:28:55 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/19 17:12:28 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_game *game)
{	
	if (game->map[PPY][PPX + 1] == '0' && !prevent_double_key_press(game, KEY_D))
	{
		game->map[PPY][PPX + 1] = 'P';
		game->map[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			game->map[PPY][PPX] = 'E';
	}
	else if (game->map[PPY][PPX + 1] == 'C' && !prevent_double_key_press(game, KEY_D))
	{
		game->map[PPY][PPX + 1] = 'P';
		game->map[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			game->map[PPY][PPX] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[PPY][PPX + 1] == 'E' && !prevent_double_key_press(game, KEY_D))
	{
		game->map[PPY][PPX + 1] = 'P';
		game->map[PPY][PPX] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_left(t_game *game)
{	
	if (game->map[PPY][PPX - 1] == '0' && !prevent_double_key_press(game, KEY_A))
	{
		game->map[PPY][PPX - 1] = 'P';
		game->map[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			game->map[PPY][PPX] = 'E';
	}
	else if (game->map[PPY][PPX - 1] == 'C' && !prevent_double_key_press(game, KEY_A))
	{
		game->map[PPY][PPX - 1] = 'P';
		game->map[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			game->map[PPY][PPX] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[PPY][PPX - 1] == 'E' && !prevent_double_key_press(game, KEY_A))
	{
		game->map[PPY][PPX - 1] = 'P';
		game->map[PPY][PPX] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_up(t_game *game)
{	
	if (game->map[PPY - 1][PPX] == '0' && !prevent_double_key_press(game, KEY_W))
	{
		game->map[PPY - 1][PPX] = 'P';
		game->map[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			game->map[PPY][PPX] = 'E';
	}
	else if (game->map[PPY - 1][PPX] == 'C' && !prevent_double_key_press(game, KEY_W))
	{
		game->map[PPY - 1][PPX] = 'P';
		game->map[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			game->map[PPY][PPX] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[PPY - 1][PPX] == 'E' && !prevent_double_key_press(game, KEY_W))
	{
		game->map[PPY - 1][PPX] = 'P';
		game->map[PPY][PPX] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_down(t_game *game)
{	
	if (game->map[PPY + 1][PPX] == '0' && !prevent_double_key_press(game, KEY_S))
	{
		game->map[PPY + 1][PPX] = 'P';
		game->map[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			game->map[PPY][PPX] = 'E';
	}
	else if (game->map[PPY + 1][PPX] == 'C' && !prevent_double_key_press(game, KEY_S))
	{
		game->map[PPY + 1][PPX] = 'P';
		game->map[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			game->map[PPY][PPX] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[PPY + 1][PPX] == 'E' && !prevent_double_key_press(game, KEY_S))
	{
		game->map[PPY + 1][PPX] = 'P';
		game->map[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			game->map[PPY][PPX] = 'E';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}
