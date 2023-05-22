/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:00:04 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/22 18:25:57 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Prints collected items and target */
int	player_reached_collectible(t_game *game)
{		
	ft_printf("Collected items: %d\n", ++game->items);
	ft_printf("Target: %d items\n", game->target_items);
	return (0);
}

/* Checks if all items are collected and finishes game */
int	player_reached_exit(t_game *game)
{	
	if (game->target_items == game->items)
	{
		ft_printf("YOU WIN!");
		exit_point(game, NULL);
	}
	return (0);
}
