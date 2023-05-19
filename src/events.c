/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:00:04 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/19 17:17:01 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Prints collected items and target */
int	player_reached_collectible(t_game *game)
{		
	ft_printf("Collected items: %d\n", ++game->collectibles);
	ft_printf("Target: %d items\n", game->target_collectibles);
	return (0);
}

/* Checks if all items are collected and finishes game */
int	player_reached_exit(t_game *game)
{	
	if (game->target_collectibles == game->collectibles)
	{
		ft_printf("YOU WIN!");
		exit(0);
	}
	return (0);
}
