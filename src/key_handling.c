/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:17:54 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/23 15:34:32 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* This function is called every time the button is pressed */
int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_point(game, NULL);
	else if (key_code == D)
	{	
		game->pres_but_d_count++;
		move_right(game);
	}
	else if (key_code == A)
	{	
		game->pres_but_a_count++;
		move_left(game);
	}
	else if (key_code == W && game->lock_button == 0)
	{
		game->pres_but_w_count++;
		move_up(game);
	}
	else if (key_code == S && game->lock_button == 0)
	{	
		game->pres_but_s_count++;
		move_down(game);
	}		
	return (0);
}

/* This function is called every time the button is released */
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

/* This function closes game */
int	close_game(int key_code, t_game *game)
{
	(void)key_code;
	(void)game;
	exit(0);
}

/* This function prevents wrong behaviour when two or more buttons */
/* pressed simultaneously */
int	prev_2_key(t_game *game, int button_key)
{
	if (button_key == D)
	{
		if (game->pres_but_a_count == 0 && game->pres_but_w_count == 0
			&& game->pres_but_s_count == 0)
			return (0);
	}
	else if (button_key == A)
	{
		if (game->pres_but_d_count == 0 && game->pres_but_w_count == 0
			&& game->pres_but_s_count == 0)
			return (0);
	}
	else if (button_key == W)
	{
		if (game->pres_but_a_count == 0 && game->pres_but_s_count == 0
			&& game->pres_but_d_count == 0)
			return (0);
	}
	else if (button_key == S)
	{
		if (game->pres_but_a_count == 0 && game->pres_but_w_count == 0
			&& game->pres_but_d_count == 0)
			return (0);
	}
	return (1);
}
