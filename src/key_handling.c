/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:17:54 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/19 17:18:17 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_D)
	{	
		game->pres_but_d_count++;
		move_right(game);
	}
	else if (key_code == KEY_A)
	{	
		game->pres_but_a_count++;
		move_left(game);
	}
	else if (key_code == KEY_W && game->lock_button == 0)
	{
		game->pres_but_w_count++;
		move_up(game);
	}
	else if (key_code == KEY_S && game->lock_button == 0)
	{	
		game->pres_but_s_count++;
		move_down(game);
	}		
	return (0);
}

int	release_key(int key_code, t_game *game)
{
	game->lock_button = 0;
	game->pres_but_a_count = 0;
	game->pres_but_d_count = 0;
	game->pres_but_w_count = 0;
	game->pres_but_s_count = 0;
	(void)key_code;
	return (0);
}

int	close_game(int key_code, t_game *game)
{
	(void)key_code;
	(void)game;
	exit(0);
}

int	prevent_double_key_press(t_game *game, int button_key)
{
	if (button_key == KEY_D)
	{
		if (game->pres_but_a_count == 0 && game->pres_but_w_count == 0 && game->pres_but_s_count == 0)
			return (0);
	}
	else if (button_key == KEY_A)
	{
		if (game->pres_but_d_count == 0 && game->pres_but_w_count == 0 && game->pres_but_s_count == 0)
			return (0);
	}
	else if (button_key == KEY_W)
	{
		if (game->pres_but_a_count == 0 && game->pres_but_s_count == 0 && game->pres_but_d_count == 0)
			return (0);
	}
	else if (button_key == KEY_S)
	{
		if (game->pres_but_a_count == 0 && game->pres_but_w_count == 0 && game->pres_but_d_count == 0)
			return (0);
	}
	return (1);
}
