/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:30:32 by aputiev           #+#    #+#             */
/*   Updated: 2023/05/23 16:09:49 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "../mlx/mlx.h"

# define BUFFER_SIZE 69

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_find_end(char *str);

typedef struct s_game
{	
	int		lock_button;
	int		row;
	int		col;
	void	*img_grass;
	void	*img_wall;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	void	*mlx;
	void	*win;
	int		ppx;
	int		ppy;
	int		exit_pos_x;
	int		exit_pos_y;
	int		items;
	int		players_count;
	int		exits_count;
	int		exitz;
	int		target_items;
	int		moves;
	char	**map;
	int		pres_but_a_count;
	int		pres_but_d_count;
	int		pres_but_w_count;
	int		pres_but_s_count;
	int		win_length;
	int		win_height;	
}				t_game;

int			ft_printf(const char *specifier, ...);
int			find_way(t_game *test_game, int ppy, int ppx);
int			find_exit(t_game *test_game, int ppy, int ppx);
int			check_map_valid_path(t_game *game);
int			string_len(char *str);
int			check_map(t_game *game, char *av);
char		**create_map(t_game *game, char *av);
int			count_map_rows(t_game *game, char *av);
int			main_loop(t_game *game);
int			check_map_name(char *av);
int			check_map_rectangular(t_game *game);
int			check_map_surrounded(t_game *game);
int			check_map_wrong_chars(t_game *game);
int			check_map_duplicated_chars(t_game *game);
int			move_right(t_game *game);
int			move_left(t_game *game);
int			move_up(t_game *game);
int			move_down(t_game *game);
int			deal_key(int key_code, t_game *game);
int			release_key(int key_code, t_game *game);
int			close_game(int key_code, t_game *game);
int			prev_2_key(t_game *game, int button_key);
int			player_reached_collectible(t_game *game);
int			player_reached_exit(t_game *game);
int			check_number_of_args(int ac);
int			data_initialization(t_game *game);
int			put_image(t_game *game, int row, int col, int coord_y);
char		**fill_map(int fd, char **map, int rows, t_game *game);
int			check_map_geometry(t_game *game);
int			check_map_surrounded_top(t_game *game);
int			check_map_surrounded_left_right_walls(t_game *game);
int			check_map_surrounded_bottom(t_game *game);
int			check_map_number_of_collectibles(t_game *game);
int			check_map_duplicated_players(t_game *game);
int			check_map_duplicated_exits(t_game *game);
int			test_data_initialization(t_game *test_game, t_game *game);
int			check_right_cell_for_exit(t_game *test_game, int ppy, int ppx);
int			check_left_cell_for_exit(t_game *test_game, int ppy, int ppx);
int			check_down_cell_for_exit(t_game *test_game, int ppy, int ppx);
int			check_up_cell_for_exit(t_game *test_game, int ppy, int ppx);
int			check_right_cell_for_way(t_game *test_game, int ppy, int ppx);
int			check_left_cell_for_way(t_game *test_game, int ppy, int ppx);
int			check_down_cell_for_way(t_game *test_game, int ppy, int ppx);
int			check_up_cell_for_way(t_game *test_game, int ppy, int ppx);
int			exit_point(t_game *game, t_game *test_game);
int			free_test_game(t_game *test_game);
size_t		ft_strlen(const char *s);
int			create_window(t_game *game);
int			load_xpm_image(t_game *game);

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17 //Exit program key code
# define KEY_ESC			53
# define W				13
# define A				0
# define S				1
# define D				2
# define ROWS			0	
# define COLS			0
# define EXIT			"images/wall_n.xpm"
# define GRASS			"images/grass.xpm"
# define WALL			"images/wall.xpm"
# define PLAYER			"images/cat.xpm"
# define ITEM			"images/collect.xpm"

#endif