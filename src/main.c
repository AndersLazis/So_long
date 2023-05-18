#include "so_long.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <stdio.h>
#include "../mlx/mlx.h"


int check_map_name(char*	av)
{	
	//printf("+++++++++++++++++\n");
	char* right_name = ".ber";
	int i = 3;
	int j;

	j = strlen(av)-1;

	while (i>=0)
	{
		if(right_name[i] != av[j])
			return(1);
		i--;
		j--;
	}
	return(0);
}

int	check_map_rectangular(t_game *game)
{	
	int	columns;
	int rows;

	columns = 0;
	rows = 0;
	game->columns = strlen(game->my_map[0]);
	while(rows < game->rows)
	{
		while(game->my_map[rows][columns] != '\0' && game->my_map[rows][columns] != '\n')	
			{
				columns++;				
				// printf("x:%d\n", x);			
			}
		// printf("y:%d\n", y);
		// printf("x:%d\n", x);
		if (columns != (game->columns))
			return(1);		
		rows++;
		columns = 0;
	}
	return(0);
}

int check_map_surrounded(t_game *game)
{
	int	x;
	int y;
	// int first_column;
	// int last_column;

	x = 0;
	y = 0;
		// printf("mapstr:!%s!\n", game->my_map[0]);
		// printf("mapstr:!%s!\n", game->my_map[1]);
		// printf("mapstr:!%s!\n", game->my_map[2]);
		// printf("mapstr:!%s!\n", game->my_map[3]);

		while(game->my_map[0][x] != '\n' && game->my_map[0][x] != '\0')
		{
			if (game->my_map[0][x] != '1')
				{		
					//printf("signalnok:%d!\n", x);
					return(1);
				}
			x++;
		} 
		x = 0;
		// printf("colonny:%d\n", game->columns-1);
		// printf("symbol:%c\n", game->my_map[y][game->columns-1]);
		while(y < game->rows-1)
		{
			// printf("y:%d\n", y);
			if (game->my_map[y][0] != '1' || game->my_map[y][game->columns-1] != '1' )
				{	//printf("signalnok2:%d!\n", game->columns);
					return(1);
				}
			y++;
		}
		x = 0;
		// printf("y:%d\n", y);
		while(game->my_map[y][x] != '\n' && game->my_map[y][x] != '\0')
		{
			if (game->my_map[y][x] != '1')
				{	//printf("signalnok3:%d!\n", x);
					return(1);}
			x++;
		}
	return(0);
}


int check_map_wrong_chars(t_game *game)
{	
	int i;
 	i = 0;

	int x = 0;
	int y = 0;

	while(y < game->rows)
	{
		while (game->my_map[y][x] != '\0')
		{
			// printf("y:%d\n", y);
			if (game->my_map[y][x] != '1' && game->my_map[y][x] != '0' && game->my_map[y][x] != 'C' && game->my_map[y][x] != 'C'&& game->my_map[y][x] != 'E' && game->my_map[y][x] != 'P')
				{	
					//printf("NOK, y:%d, x:%d!\n", y, x);
					return(1);
				}
			x++;
		}
		x = 0;
		y++;
		
	}
	return(0);
}

int check_map_duplicated_chars(t_game *game)
{	
	int i;
 	i = 0;
	int x = 0;
	int y = 0;
	int exit = 0;
	int player = 0;
	int collectible = 0;

	while(y < game->rows)
	{
		while (game->my_map[y][x] != '\0')
		{
			if (game->my_map[y][x] == 'C')
				collectible++;
			else if (game->my_map[y][x] == 'P')
				{
					player++;
					game->player_pos_x = x;
					game->player_pos_y = y;


				}
			else if (game->my_map[y][x] == 'E')
			{
				exit++;	
				game->exit_pos_x = x;
  				game->exit_pos_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	
	}
	game->target_collectibles = collectible;
	if (exit != 1)
		{printf("Error: number of exit must be 1\n");
		return(1);}
	else if (player != 1)
		{printf("Error: number of players must be 1\n");
		return(1);}
	else if (collectible < 1)
		{printf("Error: number of collectibles must be at least 1\n");
		return(1);}
	return(0);
}





//****************************************FIND WAY *******************************************************


int find_way(t_game *test_game, int ppy, int ppx)
{	

	printf("entere in find_way with coords:\n");
	//return(1);
	printf("%d,%d\n", ppy, ppx);
	printf("%c\n", test_game->my_map[ppy][ppx]);
	printf("test_game->target_collectibles:%d\n", test_game->target_collectibles);
	printf("test_game->collectibles:%d\n", test_game->collectibles);
	// printf("test_game->exit_reachable :%d\n", test_game->exit_reachable);

	//usleep(200000);
	if ((test_game->target_collectibles) == (test_game->collectibles))
		{	
			printf("ALL COLLECT'S HAVE BEEN FOUND!\n");
			return(1);
		}	

	if(test_game->my_map[ppy][ppx] == 'C')
		{
			test_game->my_map[ppy][ppx] = '0';
			test_game->collectibles++;			
		}	
	
	if ((test_game->target_collectibles == test_game->collectibles) && (test_game->my_map[ppy][ppx] = '+'))			
		return(0);
		
	if(test_game->my_map[ppy][ppx+1] == '0' || test_game->my_map[ppy][ppx+1] == 'C' || test_game->my_map[ppy][ppx+1] == 'E') //RIGHT
	{	
		test_game->my_map[ppy][ppx] ='+';
		if (ppx < (test_game->columns - 2))
			{
				find_way(test_game, ppy, ppx+1);
			}
	}
	if(test_game->my_map[ppy][ppx-1] == '0' || test_game->my_map[ppy][ppx-1] == 'C' || test_game->my_map[ppy][ppx-1] == 'E') //LEFT
	{
		test_game->my_map[ppy][ppx] = '+';
		if (ppx > 1)
			{
				find_way(test_game, ppy, ppx-1);
			}
	}
	if(test_game->my_map[ppy+1][ppx] == '0' || test_game->my_map[ppy+1][ppx] == 'C' || test_game->my_map[ppy+1][ppx] == 'E') //DOWN
	{
		 test_game->my_map[ppy][ppx] = '+';
		if (ppy < (test_game->rows-1)) 
			{
				find_way(test_game, ppy+1, ppx);
			}
			
	}
	if(test_game->my_map[ppy-1][ppx] == '0' || test_game->my_map[ppy-1][ppx] == 'C' || test_game->my_map[ppy-1][ppx] == 'E')	//UP
	{
		 test_game->my_map[ppy][ppx] = '+';
		if (ppy > 1)
			{	
				find_way(test_game, ppy-1, ppx);
			}
	}

	if ((test_game->target_collectibles) == (test_game->collectibles))
		{	
			printf("ALL collectibles HAS BEEN FOUND!\n");
			return(1);
		}

	return(0);
}

//*****************************************EXIT***********************************************************
int find_exit(t_game *test_game, int ppy, int ppx)
{	
	printf("entere in find_exit with coords:\n");
	printf("%d,%d\n", ppy, ppx);
	printf("%c\n", test_game->my_map[ppy][ppx]);
	printf("test_game->exit_reachable :%d\n", test_game->exitz);

	test_game->my_map[test_game->exit_pos_y][test_game->exit_pos_x] = 'E';

	if (test_game->exitz == 1)
		{	
			printf("EXIT HAS BEEN FOUND!\n");
			return(1);
		}	

	if (test_game->my_map[ppy][ppx] == 'E')
		{
			test_game->exitz = 1;			
		}	
	
	if (test_game->my_map[ppy][ppx] == 'A')			
		return(0);
		
	if(test_game->my_map[ppy][ppx+1] != '1' && test_game->my_map[ppy][ppx+1] != 'A') //RIGHT
	{	
		test_game->my_map[ppy][ppx] ='A';
		if (ppx < (test_game->columns - 2))
			{
				find_exit(test_game, ppy, ppx+1);
			}
	}
	if(test_game->my_map[ppy][ppx-1] != '1' && test_game->my_map[ppy][ppx-1] != 'A') //LEFT
	{
		test_game->my_map[ppy][ppx] = 'A';
		if (ppx > 1)
			{
				find_exit(test_game, ppy, ppx-1);
			}
	}
	if(test_game->my_map[ppy+1][ppx] != '1' &&  test_game->my_map[ppy+1][ppx] != 'A') //DOWN
	{
		test_game->my_map[ppy][ppx] = 'A';
		if (ppy < (test_game->rows-1)) 
			{
				find_exit(test_game, ppy+1, ppx);
			}
			
	}
	if(test_game->my_map[ppy-1][ppx] != '1' &&  test_game->my_map[ppy-1][ppx] != 'A')	//UP
	{
		 test_game->my_map[ppy][ppx] = 'A';
		if (ppy > 1)
			{	
				find_exit(test_game, ppy-1, ppx);
			}
	}

	if (test_game->exitz == 1)
		{	
			printf("EXITT HAS BEEN FOUND!\n");
			return(1);
		}

	return(0);
}



//*****************************************/*****************************************/*****************************************
//*****************************************/*****************************************/*****************************************

























int check_map_valid_path(t_game *game)
{	
	int y = 0;
	int x = 0;
	t_game test_game;




	test_game.rows = game->rows;
	test_game.columns = game->columns;
	printf("test_game.rows = %d\n", test_game.rows);
	printf("test_game.columns = %d\n", test_game.columns);

	test_game.player_pos_x = game->player_pos_x;
  	test_game.player_pos_y = game->player_pos_y;
	test_game.exit_pos_x = game->exit_pos_x;
  	test_game.exit_pos_y = game->exit_pos_y;


	test_game.target_collectibles = game->target_collectibles;
	test_game.collectibles = 0;
	test_game.exitz = 0;

	// int collected_items = 0;
	
	test_game.my_map = malloc((game->rows)*sizeof(char*));
	while(y<game->rows)
	{	
		test_game.my_map[y] = malloc((game->columns+1)*sizeof(char));	
		while(game->my_map[y][x] != '\0')
		{	
			test_game.my_map[y][x] = game->my_map[y][x];
			printf("%c", test_game.my_map[y][x]);
			x++;	
		}
		test_game.my_map[y][x] = '\0';
		y++;
		x = 0;
		printf("\n");	
	}
			//printf("GAMeppy:%d, GAMe ppx:%d\n", (game->player_pos_y), (game->player_pos_x));	
	// test_game.player_pos_y = game->player_pos_y;
	// test_game.player_pos_x = game->player_pos_y;

	// printf("find_way=%d\n", find_way(&test_game, test_game.player_pos_y, test_game.player_pos_x));
	// printf("find_exit=%d\n", find_exit(&test_game, test_game.player_pos_y, test_game.player_pos_x));



	if((find_way(&test_game, test_game.player_pos_y, test_game.player_pos_x) == 1) && (find_exit(&test_game, test_game.player_pos_y, test_game.player_pos_x) == 1))
	{	
		printf("THE PATH IS VALID\n");
		return(1);
	}
	x = 0;
	y = 0;
	printf("test map:\n");
	while(y<test_game.rows)
	{	
		while(test_game.my_map[y][x] != '\0')
		{	
			test_game.my_map[y][x] = test_game.my_map[y][x];
			printf("%c", test_game.my_map[y][x]);
			x++;	
		}
		test_game.my_map[y][x] = '\0';
		y++;
		x = 0;
		printf("\n");	
	}
	
	return(0);
}





int	string_len(char *str)
{	int i;
 	i = 0;
	// printf("STR=%s\n", str);
	while(str[i]!='\n' && str[i]!='\0') 
	{		
		i++;			
	}
	return(i+1);
}

//==============================================MAP===CHECK====================================================
//=============================================================================================================

// The map must contain 1 exit, at least 1 collectible, and 1 starting position to
// be valid.
// If the map contains a duplicates characters (exit/start), you should
// display an error message.
// • The map must be rectangular.
// • The map must be closed/surrounded by walls. If it’s not, the program must return
// an error.
// • You have to check if there’s a valid path in the map.
// • You must be able to parse any kind of map, as long as it respects the above rules.
// • If any misconfiguration of any kind is encountered in the file, the program must
// exit in a clean way, and return "Error\n" followed by an explicit error message of
// your choice.


int check_map (t_game *game, char*	av)
{	
	if(check_map_name(av) == 1)
	{
		printf("Error: map file must have be the '.ber' format\n");
		exit(0);
	}	
	game->moves = 0;
	if(check_map_rectangular(game) == 1)
	{
		printf("Invalid map. Map is not rectangular. Please, check the map.\n");
		exit(0);
	}
	else if(check_map_surrounded(game) == 1)
	{
		printf("Invalid map. Map isn't surrounded by walls. Please, check the map.\n");
		exit(0);
	}
	else if(check_map_wrong_chars(game) == 1)
	{
		printf("Invalid map. Map has invalid characters. Please, check the map.\n");
		exit(0);
	}
	else if(check_map_duplicated_chars(game) == 1)
	{
		exit(0);
	}
		else if(check_map_valid_path(game) == 0)
	{
		printf("Invalid map. Map hasn't a valid path. Please, check the map.\n");
		exit(0);
	}

	return(0);
}






// //=====================================================MAP=====================================================
// //=============================================================================================================
char** create_map(t_game *game, char *av)
{
int fd;
int i = 0;
int j = 0;
int k = 0;
char **map;
char* next_line;

map = malloc((game->rows)*sizeof(char*));

if (!av)
	printf("no map");

	// av[1] = "maps/simple.ber";
fd = open(av, O_RDONLY);


while(1)
{		
    next_line = get_next_line(fd);
	// if(is_string_valid(next_line)>0 || is_string_inside(next_line) == 0)
	// {
		

		map[i] = malloc((string_len(next_line)+1)*sizeof(char));	
		// printf("I==%d", i);
		while(next_line[j] != '\n' && next_line[j] != '\0')
		{	
			map[i][k] = next_line[j];
			k++;
			j++;			
		}	
		map[i][k]='\0';

	i++;
	j = 0;
	k = 0;

	// printf("game->rows:%d\n", game->rows);
	// printf("i:%d\n", i);
		
	if(i == game->rows)
		break;


}
	// else
	// {
	// 	printf("Error: Map has wrong symbols\n");
	// 	exit(0);
	// }

	close (fd);
	return (map);
}




// //--------------COUNT MAP ROWS-----------------------------

int count_map_rows(t_game *game, char* av)
{
int rows = 0;
char *next_line;
int fd;

if (!av)
	printf("no map");
	// av = "maps/simple.ber";

fd = open(av, O_RDONLY);	
   
if(fd == -1)
{
	printf("Error! Map hasn't been found!\n");
	exit(0);
}

while(1)
{		
    next_line = get_next_line(fd);
	
	if(!next_line )
		break;
	rows++;
}

// columns--;
close (fd);

game->rows = rows;

// game->columns = columns;

// game->my_map = create_map(rows, game, av);

return(0);
}

//==============================LOOP=================================

int		main_loop(t_game *game)
{
	int row= 0;
	int col = 0;
	int coord_y = 0;
	int coord_x = 0;
	
	while (row != game->rows)
	{
		while (col != game->columns)
		{
			if (game->my_map[row][col] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_grass, coord_x, coord_y);
			else if (game->my_map[row][col] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, coord_x, coord_y);
			else if (game->my_map[row][col] == 'P')
				{
					mlx_put_image_to_window(game->mlx, game->win, game->img_player, coord_x, coord_y);
					game->player_pos_x = col;
					game->player_pos_y = row;
								
				}
			else if (game->my_map[row][col] == 'C')
				{
					mlx_put_image_to_window(game->mlx, game->win, game->img_collect, coord_x, coord_y);
				}
			else if (game->my_map[row][col] == 'E')
				{
					mlx_put_image_to_window(game->mlx, game->win, game->img_exit, coord_x, coord_y);
				}
			col++;
			coord_x = coord_x+32;

		}
		col = 0;
		coord_x = 0;
		row++;
		coord_y = coord_y+32;		
	}	

	return (0);
}

//=====================================MAIN===============================

int main(int ac, char**	av)
{		
	t_game game;

		game.pres_but_a_count = 0;
		game.pres_but_d_count = 0;
		game.pres_but_w_count = 0;
		game.pres_but_s_count = 0;
		game.collectibles = 0;
		game.target_collectibles = 0;
		game.moves = 0;

		int		img_width = 32;
		int 	img_height = 32;

	if (ac !=1 && ac != 2)
	{
		printf("Error! Map path is invalid");
		exit(0);
	}			
		count_map_rows(&game, av[1]);
		game.my_map = create_map(&game, av[1]);
		
		if (!av[1])
			printf("no map");
			// av[1] = "maps/simple.ber";
		check_map(&game, av[1]);
		// for(int i = 0; i< game.rows; i++)
		// {
		// printf("map_line:%s\n", game.my_map[i]);
		// }

		printf("game->rows: %d\n", game.rows);
		printf("game->colu: %d\n", game.columns);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, (game.columns*32), (game.rows*32), "my_mlx");

		game.img_grass = mlx_xpm_file_to_image(game.mlx, "images/grass.xpm", &img_width, &img_height);
		game.img_wall = mlx_xpm_file_to_image(game.mlx, "images/wall.xpm", &img_width, &img_height);
		game.img_wall = mlx_xpm_file_to_image(game.mlx, "images/wall.xpm", &img_width, &img_height);
		game.img_player = mlx_xpm_file_to_image(game.mlx, "images/cat.xpm", &img_width, &img_height);
		game.img_collect = mlx_xpm_file_to_image(game.mlx, "images/collect.xpm", &img_width, &img_height);
		game.img_exit = mlx_xpm_file_to_image(game.mlx, "images/wall_n.xpm", &img_width, &img_height);


		mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
		mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &release_key, &game);
		mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);

		mlx_loop_hook(game.mlx, &main_loop, &game);
		mlx_loop(game.mlx);
		
		return (0);
}
