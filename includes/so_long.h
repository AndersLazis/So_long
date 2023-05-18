
#ifndef SO_LONG_H
# define SO_LONG_H

#include<stdio.h>
#include<mlx.h>


#define DEFAULT_MAP			"/maps/simple.ber"

#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>

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
	int		player_pos_x;
	int		player_pos_y;
	int		exit_pos_x;
	int		exit_pos_y;
	int		collectibles;
	int		players_count;
	int		exits_count;
	int		exitz;
	int		target_collectibles;
	int		moves;
	char	**my_map;
	int 	pres_but_a_count;
	int 	pres_but_d_count;
	int 	pres_but_w_count;
	int 	pres_but_s_count;
	int		win_length;
	int		win_height;
	
	
	
}				t_game;




int		deal_key(int key_code, t_game *game);
int		release_key(int key_code, t_game *game);
int 	close_game(int key_code, t_game *game);
int prevent_double_press(t_game *game, int button_key);
int player_reached_collectible (t_game *game);
int player_reached_exit (t_game *game);
int	check_map_rectangular(t_game *game);
int check_map (t_game *game, char*	av);
int check_map_surrounded(t_game *game);
int	string_len(char * str);

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3
#define X_EVENT_KEY_EXIT		17 //Exit program key code

#define KEY_ESC			53

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define ROWS 0
# define COLS 0
 