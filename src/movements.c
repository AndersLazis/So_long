#include "so_long.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../mlx/mlx.h"

int move_right(t_game *game)
{	
	// printf("y = %d, x = %d\n", game->exit_pos_y, game->exit_pos_x);
	if(game->my_map[game->player_pos_y][game->player_pos_x+1] == '0' && !prevent_double_press(game, KEY_D))
	{
		game->my_map[game->player_pos_y][game->player_pos_x+1] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		if((game->exit_pos_y == game->player_pos_y) && (game->exit_pos_x == game->player_pos_x))
		{
			game->my_map[game->player_pos_y][game->player_pos_x] = 'E';
		}
		
	}

	else if(game->my_map[game->player_pos_y][game->player_pos_x+1] == 'C' && !prevent_double_press(game, KEY_D))
		{
		game->my_map[game->player_pos_y][game->player_pos_x+1] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		if((game->exit_pos_y == game->player_pos_y) && (game->exit_pos_x == game->player_pos_x))
		{
			game->my_map[game->player_pos_y][game->player_pos_x] = 'E';
		}
		player_reached_collectible(game);
		}

	else if(game->my_map[game->player_pos_y][game->player_pos_x+1] == 'E' && !prevent_double_press(game, KEY_D))
	 	{
		game->my_map[game->player_pos_y][game->player_pos_x+1] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		player_reached_exit(game);
		}
	printf("MOVES: %d\n", ++game->moves);
	return(0);
}

int move_left(t_game *game)
{	
	if(game->my_map[game->player_pos_y][game->player_pos_x-1] == '0' && !prevent_double_press(game, KEY_A))
	{
		game->my_map[game->player_pos_y][game->player_pos_x-1] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		if((game->exit_pos_y == game->player_pos_y) && (game->exit_pos_x == game->player_pos_x))
		{
			game->my_map[game->player_pos_y][game->player_pos_x] = 'E';
		}
		//printf("MOVES: %d\n", ++game->moves);
	}
	else if(game->my_map[game->player_pos_y][game->player_pos_x-1] == 'C' && !prevent_double_press(game, KEY_A))
	{
		game->my_map[game->player_pos_y][game->player_pos_x-1] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		if((game->exit_pos_y == game->player_pos_y) && (game->exit_pos_x == game->player_pos_x))
		{
			game->my_map[game->player_pos_y][game->player_pos_x] = 'E';
		}
		player_reached_collectible(game);
	}
	else if(game->my_map[game->player_pos_y][game->player_pos_x-1] == 'E' && !prevent_double_press(game, KEY_A))
	{
		game->my_map[game->player_pos_y][game->player_pos_x-1] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';		
		player_reached_exit(game);
	}
	printf("MOVES: %d\n", ++game->moves);
	return(0);
}

int move_up(t_game *game)
{	
	if(game->my_map[game->player_pos_y-1][game->player_pos_x] == '0' && !prevent_double_press(game, KEY_W))
	{
		game->my_map[game->player_pos_y-1][game->player_pos_x] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		if((game->exit_pos_y == game->player_pos_y) && (game->exit_pos_x == game->player_pos_x))
		{
			game->my_map[game->player_pos_y][game->player_pos_x] = 'E';
		}
		//printf("MOVES: %d\n", ++game->moves);
	}
	else if(game->my_map[game->player_pos_y-1][game->player_pos_x] == 'C' && !prevent_double_press(game, KEY_W))
	{
		game->my_map[game->player_pos_y-1][game->player_pos_x] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		if((game->exit_pos_y == game->player_pos_y) && (game->exit_pos_x == game->player_pos_x))
		{
			game->my_map[game->player_pos_y][game->player_pos_x] = 'E';
		}
		player_reached_collectible(game);
	}
	else if(game->my_map[game->player_pos_y-1][game->player_pos_x] == 'E' && !prevent_double_press(game, KEY_W))
	{
		game->my_map[game->player_pos_y-1][game->player_pos_x] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		player_reached_exit(game);
	}
	printf("MOVES: %d\n", ++game->moves);
	return(0);
}

int move_down(t_game *game)
{	
	if(game->my_map[game->player_pos_y+1][game->player_pos_x] == '0' && !prevent_double_press(game, KEY_S))
	{
		game->my_map[game->player_pos_y+1][game->player_pos_x] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		if((game->exit_pos_y == game->player_pos_y) && (game->exit_pos_x == game->player_pos_x))
		{
			game->my_map[game->player_pos_y][game->player_pos_x] = 'E';
		}
		//printf("MOVES: %d\n", ++game->moves);
	}
	else if(game->my_map[game->player_pos_y+1][game->player_pos_x] == 'C' && !prevent_double_press(game, KEY_S))
	{
		game->my_map[game->player_pos_y+1][game->player_pos_x] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		if((game->exit_pos_y == game->player_pos_y) && (game->exit_pos_x == game->player_pos_x))
		{
			game->my_map[game->player_pos_y][game->player_pos_x] = 'E';
		}
		player_reached_collectible(game);
	}
	else if(game->my_map[game->player_pos_y+1][game->player_pos_x] == 'E' && !prevent_double_press(game, KEY_S))
	{
		game->my_map[game->player_pos_y+1][game->player_pos_x] = 'P';
		game->my_map[game->player_pos_y][game->player_pos_x] = '0';
		if((game->exit_pos_y == game->player_pos_y) && (game->exit_pos_x == game->player_pos_x))
		{
			game->my_map[game->player_pos_y][game->player_pos_x] = 'E';
		}
		player_reached_exit(game);
	}
	printf("MOVES: %d\n", ++game->moves);
	return(0);
}

int		deal_key(int key_code, t_game *game)
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

	int release_key(int key_code, t_game *game)
	{
		game->lock_button = 0;
		game->pres_but_a_count = 0;
		game->pres_but_d_count = 0;
		game->pres_but_w_count = 0;
		game->pres_but_s_count = 0;
		(void)key_code;
		return(0);
	}


	int 	close_game(int key_code, t_game *game)
	{
		(void)key_code;
		(void)game;
			exit(0);
	}

	int prevent_double_press(t_game *game, int button_key)
	{
		if (button_key == KEY_D)
		{
			if(game->pres_but_a_count == 0 && game->pres_but_w_count == 0 && game->pres_but_s_count == 0)
				return(0);
			//return(1);
		}

		else if (button_key == KEY_A)
		{
			if(game->pres_but_d_count == 0 && game->pres_but_w_count == 0 && game->pres_but_s_count == 0)
				return(0);
			//return(1);
		}

		else if (button_key == KEY_W)
		{
			if(game->pres_but_a_count == 0 && game->pres_but_s_count == 0 && game->pres_but_d_count == 0)
				return(0);
			//return(1);
		}

		else if (button_key == KEY_S)
		{
			if(game->pres_but_a_count == 0 && game->pres_but_w_count == 0 && game->pres_but_d_count == 0)
				return(0);
			//return(1);
		}
		return(1);
	}

	int player_reached_collectible (t_game *game)
	{		
		printf("Collected items: %d\n", ++game->collectibles);
		printf("target items: %d\n", game->target_collectibles);
			
		return(0);
	}

	int player_reached_exit (t_game *game)
	{	
		if(game->target_collectibles == game->collectibles)
			{
				printf("YOU WIN!");	
				exit(0);
			}

		return(0);
	}


