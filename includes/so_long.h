
#ifndef SO_LONG_H
# define SO_LONG_H

#include<mlx.h>

#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_find_end(char *str);
size_t		ft_strlen(char *str);

#endif
 
typedef struct	s_game
{	
	int 	lock_button;
	int 	rows;
	int 	columns;
	void	*img_grass;
	void	*img_wall;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	void	*mlx;
	void	*win;
	int		pl_pos_x;
	int		pl_pos_y;
	int		exit_pos_x;
	int		exit_pos_y;
	int		collectibles;
	int		players_count;
	int		exits_count;
	int		exitz;
	int		target_collectibles;
	int		moves;
	char	**map;
	int 	pres_but_a_count;
	int 	pres_but_d_count;
	int 	pres_but_w_count;
	int 	pres_but_s_count;
	int		win_length;
	int		win_height;	
}				t_game;

int	ft_printf(const char *specifier, ...);
int find_way(t_game *test_game, int ppy, int ppx);
int find_exit(t_game *test_game, int ppy, int ppx);
int check_map_valid_path(t_game *game);
int	string_len(char *str);
int check_map (t_game *game, char*	av);
char** create_map(t_game *game, char *av);
int count_map_rows(t_game *game, char* av);
int	main_loop(t_game *game);
int check_map_name(char*	av);
int	check_map_rectangular(t_game *game);
int check_map_surrounded(t_game *game);
int check_map_wrong_chars(t_game *game);
int check_map_duplicated_chars(t_game *game);
int move_right(t_game *game);
int move_left(t_game *game);
int move_up(t_game *game);
int move_down(t_game *game);
int	deal_key(int key_code, t_game *game);
int release_key(int key_code, t_game *game);
int close_game(int key_code, t_game *game);
int prevent_double_key_press(t_game *game, int button_key);
int player_reached_collectible (t_game *game);
int player_reached_exit (t_game *game);
int check_number_of_args(int ac);
int	data_initialization(t_game *game);
int put_image(t_game *game, int row, int col, int coord_y);
char	**fill_map(int fd, char **map, int rows);
int check_map_geometry(t_game *game);
int	check_map_surrounded_top(t_game *game);
int	check_map_surrounded_left_right_walls(t_game *game);
int	check_map_surrounded_bottom(t_game *game);
int	check_map_number_of_collectibles(t_game *game);
int	check_map_duplicated_players(t_game *game);
int	check_map_duplicated_exits(t_game *game);
int	test_data_initialization(t_game *test_game, t_game *game);
int check_right_cell_for_exit(t_game *test_game, int ppy, int ppx);
int check_left_cell_for_exit(t_game *test_game, int ppy, int ppx);
int check_down_cell_for_exit(t_game *test_game, int ppy, int ppx);
int check_up_cell_for_exit(t_game *test_game, int ppy, int ppx);
int	check_right_cell_for_way(t_game *test_game, int ppy, int ppx);
int	check_left_cell_for_way(t_game *test_game, int ppy, int ppx);
int	check_down_cell_for_way(t_game *test_game, int ppy, int ppx);
int	check_up_cell_for_way(t_game *test_game, int ppy, int ppx);
int exit_point(t_game *game);

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3
#define X_EVENT_KEY_EXIT		17 //Exit program key code

#define KEY_ESC			53

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define PPY			game->pl_pos_y
# define PPX			game->pl_pos_x

# define TEST_TARGET	test_game->target_collectibles
# define TEST_MAP		test_game->map
# define MAP			game->map

# define GRASS			game.img_grass
# define WALL			game.img_wall
# define PLAYER			game.img_player
# define ITEM			game.img_collect
# define EXIT			game.img_exit

# define IMG_SIZE		&img_width, &img_height
# define WINDOW_SIZE	(game.columns * 32), (game.rows * 32)
# define X				coord_x
# define Y				coord_y
# define WINDOW			game->win
# define MLX			game->mlx
// # define
// # define
// # define
// # define

# define ROWS 0
# define COLS 0
 