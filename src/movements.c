/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:28:55 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/21 15:10:41 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_game *game)
{	
	if (game->map[game->ppy][game->ppx + 1] == '0' && !prev_2_key(game, D))
	{
		game->map[game->ppy][game->ppx + 1] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		if ((game->exit_pos_y == game->ppy) && (game->exit_pos_x == game->ppx))
			game->map[game->ppy][game->ppx] = 'E';
	}
	else if (game->map[game->ppy][game->ppx + 1] == 'C' && !prev_2_key(game, D))
	{
		game->map[game->ppy][game->ppx + 1] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		if ((game->exit_pos_y == game->ppy) && (game->exit_pos_x == game->ppx))
			game->map[game->ppy][game->ppx] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[game->ppy][game->ppx + 1] == 'E' && !prev_2_key(game, D))
	{
		game->map[game->ppy][game->ppx + 1] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_left(t_game *game)
{	
	if (game->map[game->ppy][game->ppx - 1] == '0' && !prev_2_key(game, A))
	{
		game->map[game->ppy][game->ppx - 1] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		if ((game->exit_pos_y == game->ppy) && (game->exit_pos_x == game->ppx))
			game->map[game->ppy][game->ppx] = 'E';
	}
	else if (game->map[game->ppy][game->ppx - 1] == 'C' && !prev_2_key(game, A))
	{
		game->map[game->ppy][game->ppx - 1] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		if ((game->exit_pos_y == game->ppy) && (game->exit_pos_x == game->ppx))
			game->map[game->ppy][game->ppx] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[game->ppy][game->ppx - 1] == 'E' && !prev_2_key(game, A))
	{
		game->map[game->ppy][game->ppx - 1] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_up(t_game *game)
{	
	if (game->map[game->ppy - 1][game->ppx] == '0' && !prev_2_key(game, W))
	{
		game->map[game->ppy - 1][game->ppx] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		if ((game->exit_pos_y == game->ppy) && (game->exit_pos_x == game->ppx))
			game->map[game->ppy][game->ppx] = 'E';
	}
	else if (game->map[game->ppy - 1][game->ppx] == 'C' && !prev_2_key(game, W))
	{
		game->map[game->ppy - 1][game->ppx] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		if ((game->exit_pos_y == game->ppy) && (game->exit_pos_x == game->ppx))
			game->map[game->ppy][game->ppx] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[game->ppy - 1][game->ppx] == 'E' && !prev_2_key(game, W))
	{
		game->map[game->ppy - 1][game->ppx] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}

int	move_down(t_game *game)
{	
	if (game->map[game->ppy + 1][game->ppx] == '0' && !prev_2_key(game, S))
	{
		game->map[game->ppy + 1][game->ppx] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		if ((game->exit_pos_y == game->ppy) && (game->exit_pos_x == game->ppx))
			game->map[game->ppy][game->ppx] = 'E';
	}
	else if (game->map[game->ppy + 1][game->ppx] == 'C' && !prev_2_key(game, S))
	{
		game->map[game->ppy + 1][game->ppx] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		if ((game->exit_pos_y == game->ppy) && (game->exit_pos_x == game->ppx))
			game->map[game->ppy][game->ppx] = 'E';
		player_reached_collectible(game);
	}
	else if (game->map[game->ppy + 1][game->ppx] == 'E' && !prev_2_key(game, S))
	{
		game->map[game->ppy + 1][game->ppx] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		if ((game->exit_pos_y == game->ppy) && (game->exit_pos_x == game->ppx))
			game->map[game->ppy][game->ppx] = 'E';
		player_reached_exit(game);
	}
	ft_printf("MOVES: %d\n", ++game->moves);
	return (0);
}
