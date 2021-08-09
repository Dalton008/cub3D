NAME = cub3D

HEADER = includes/cub3D.h

LIST = cub3D.c

LIST_UTILS = $(shell find ./utils -name "*.c")

LIST_MAP = $(shell find ./raycasting -name "*.c")

LIST_PARSER = $(shell find ./parser -name "*.c")

LIST_MOVES = $(shell find ./moves -name "*.c")

FLAGS = -Wall -Wextra -Werror

FLAGS_MLX = libmlx.dylib -lmlx -framework OpenGL -framework AppKit

OBJ = $(LIST:.c=.o)

OBJ_UTILS = $(LIST_UTILS:.c=.o)

OBJ_MAP = $(LIST_MAP:.c=.o)

OBJ_PARSER = $(LIST_PARSER:.c=.o)

OBJ_MOVES = $(LIST_MOVES:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

%.o : %.c $(HEADER)
	gcc -g $(FLAGS) -I $(HEADER) -c $< -o $@

${NAME} : $(OBJ) $(OBJ_UTILS) $(OBJ_MAP) $(OBJ_PARSER) $(OBJ_MOVES) $(HEADER)
	gcc $(FLAGS) $(FLAGS_MLX) $(OBJ) $(OBJ_UTILS) $(OBJ_MAP) $(OBJ_PARSER) $(OBJ_MOVES) -o $(NAME)

clean :
	$(RM) $(OBJ) $(OBJ_UTILS) $(OBJ_MAP) $(OBJ_PARSER) $(OBJ_MOVES)

fclean : clean
	$(RM) $(NAME)

re : fclean all