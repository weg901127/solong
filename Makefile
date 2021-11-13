NAME  		= solong

CC 			= cc -v
CFLAGS 		= -Wall -Wextra -Werror -L ./libft -lft -L ./mlx -lmlx -framework OpenGL -framework AppKit
INCLUDE 	= -I./header/solong.h
LIB_DIR 	= ./libft/
LIB_NAME	= ft
LIB			= $(LIB_DIR)lib$(LIB_NAME).a

SRCS					= ./srcs/map.c ./srcs/draw.c \
											./srcs/event.c	./srcs/utils.c \
											./srcs/solong.c
GNL						= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

OBJ_SRCS		=	$(SRCS:.c=.o)
OBJ_GNL		=	$(GNL:.c=.o)
all : MAKE_LIB $(NAME)

clean :
	make -C $(LIB_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIB_DIR) fclean

re : fclean all

MAKE_LIB :
	make -C $(LIB_DIR) all

.c.o: $(SRCS) $(GNL)
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

$(NAME) : $(OBJ_SRCS) $(OBJ_GNL)
	$(CC) $(CFLAGS) -o solong $@

.PHONY : all clean fclean re
