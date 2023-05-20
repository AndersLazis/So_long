/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:28:55 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/20 13:15:18 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_game *game)
{	
	if (MAP[PPY][PPX + 1] == '0' && !prevent_double_key_press(game, KEY_D))
	{
		MAP[PPY][PPX + 1] = 'P';
		MAP[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			MAP[PPY][PPX] = 'E';
	}
	else if (MAP[PPY][PPX + 1] == 'C' && !prevent_double_key_press(game, KEY_D))
	{
		MAP[PPY][PPX + 1] = 'P';
		MAP[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			MAP[PPY][PPX] = 'E';
		player_reached_collectible(game);
	}
	else if (MAP[PPY][PPX + 1] == 'E' && !prevent_double_key_press(game, KEY_D))
	{
		MAP[PPY][PPX + 1] = 'P';
		MAP[PPY][PPX] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_left(t_game *game)
{	
	if (MAP[PPY][PPX - 1] == '0' && !prevent_double_key_press(game, KEY_A))
	{
		MAP[PPY][PPX - 1] = 'P';
		MAP[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			MAP[PPY][PPX] = 'E';
	}
	else if (MAP[PPY][PPX - 1] == 'C' && !prevent_double_key_press(game, KEY_A))
	{
		MAP[PPY][PPX - 1] = 'P';
		MAP[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			MAP[PPY][PPX] = 'E';
		player_reached_collectible(game);
	}
	else if (MAP[PPY][PPX - 1] == 'E' && !prevent_double_key_press(game, KEY_A))
	{
		MAP[PPY][PPX - 1] = 'P';
		MAP[PPY][PPX] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_up(t_game *game)
{	
	if (MAP[PPY - 1][PPX] == '0' && !prevent_double_key_press(game, KEY_W))
	{
		MAP[PPY - 1][PPX] = 'P';
		MAP[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			MAP[PPY][PPX] = 'E';
	}
	else if (MAP[PPY - 1][PPX] == 'C' && !prevent_double_key_press(game, KEY_W))
	{
		MAP[PPY - 1][PPX] = 'P';
		MAP[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			MAP[PPY][PPX] = 'E';
		player_reached_collectible(game);
	}
	else if (MAP[PPY - 1][PPX] == 'E' && !prevent_double_key_press(game, KEY_W))
	{
		MAP[PPY - 1][PPX] = 'P';
		MAP[PPY][PPX] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_down(t_game *game)
{	
	if (MAP[PPY + 1][PPX] == '0' && !prevent_double_key_press(game, KEY_S))
	{
		MAP[PPY + 1][PPX] = 'P';
		MAP[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			MAP[PPY][PPX] = 'E';
	}
	else if (MAP[PPY + 1][PPX] == 'C' && !prevent_double_key_press(game, KEY_S))
	{
		MAP[PPY + 1][PPX] = 'P';
		MAP[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			MAP[PPY][PPX] = 'E';
		player_reached_collectible(game);
	}
	else if (MAP[PPY + 1][PPX] == 'E' && !prevent_double_key_press(game, KEY_S))
	{
		MAP[PPY + 1][PPX] = 'P';
		MAP[PPY][PPX] = '0';
		if ((game->exit_pos_y == PPY) && (game->exit_pos_x == PPX))
			MAP[PPY][PPX] = 'E';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}
