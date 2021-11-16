NAME  								= solong

CC 											= cc
CFLAGS 							= -Wall -Wextra -Werror
FLAG_MLX 					= -framework OpenGL -framework AppKit

LIBFT_DIR 				= ./libft/
LIBFT_NAME				= libft.a
LIBMLX_DIR				= ./mlx/
LIBMLX_NAME			= libmlx.a
LIB											= $(LIBFT_DIR)$(LIBFT_NAME) $(LIBMLX_DIR)$(LIBMLX_NAME)

SRCS										= ./srcs/map.c ./srcs/draw.c \
																./srcs/event.c	./srcs/utils.c \
																./srcs/solong.c
GNL											= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

OBJ_SRCS						=	$(SRCS:.c=.o)
OBJ_GNL							=	$(GNL:.c=.o)
OBJ 										= $(OBJ_SRCS) $(OBJ_GNL)

all : MAKE_LIB $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(FLAG_MLX) $(LIB) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) clean

re : clean
	rm -f $(NAME)
	make -C . all

MAKE_LIB :
	make -C $(LIBFT_DIR) all
	make -C $(LIBMLX_DIR) all

.PHONY : all clean fclean re
