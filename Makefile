NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
RM			= /bin/rm -f

GNL_DIR		= get_next_line
PRINTF_DIR	= ft_printf

INCLUDE_DIR	= includes
MLX_DIR		= mlx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx \
			-framework OpenGL \
			-framework AppKit 
INCLUDES	= -I$(INCLUDE_DIR) \
			-I$(MLX_DIR)

LIBS		= $(GNL_DIR)/get_next_line.a \
			-L$(PRINTF_DIR) -lftprintf

BUILD_DIR	= build
SRC_DIR		= ./src
SRCS		=	main.c \
				movements.c \
				map_check.c \
				map_way_finder.c \
				key_handling.c \
				events.c \
				utils.c \
				create_map.c \
				map_check_utils.c \
				map_check_utils_2.c \
				map_exit_finder.c \
				map_check_valid_path.c

GNL 		=get_next_line.a
PRINTF		=libftprintf.a

INCLUDE_DIR = includes
BUILD_DIR = build
SRC_DIR = src

OBJS =	$(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)
	./so_long maps/simple.ber

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

libs:
	@make -C $(MLX_DIR)
	@make -C $(GNL_DIR)
	@make -C $(PRINTF_DIR)

re: fclean all

cbuild:
	-$(RM) -r $(BUILD_DIR)

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(GNL_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(MLX_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(GNL_DIR)
	$(RM) $(NAME)
	
.PHONY:	all clean fclean re