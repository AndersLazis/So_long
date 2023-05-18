

NAME = 		so_long

INCLUDE = 	-I include

CC = 		cc

CFLAGS = 	-Wall -Wextra -Werror

RM = 		rm -rf

SRC =		main.c 

MOVEMENTS = movements.c

SRC_DIR = 	src/

OBJ =		main.o

OBJ_MOV =	movements.o

GNL = get_next_line.a

INCLUDE_DIR = includes/so_long.h

all: $(NAME)


# $(OBJ):
# 	$(CC) $(SRC_DIR)$(SRC) -Iincludes -Imlx -c $< -o $@

$(OBJ):
	$(CC) $(SRC_DIR)$(SRC) -Wall -Wextra -Werror -Iincludes -Imlx -c $< -o $@

$(OBJ_MOV):
	$(CC) $(SRC_DIR)$(MOVEMENTS) -Wall -Wextra -Werror -Iincludes -Imlx -c $< -o $(OBJ_MOV)


$(NAME): $(OBJ) $(OBJ_MOV)
	@make -C get_next_line
	@cp get_next_line/get_next_line.a .
	$(CC) $(OBJ) $(OBJ_MOV) $(INCLUDE) $(GNL) -Lmlx -lmlx -framework OpenGL -framework AppKit -fsanitize=address -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_MOV)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
