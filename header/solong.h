#ifndef SOLONG_H
# define SOLONG_H
# include "../mlx/mlx.h"
# include <stdio.h>
# include <sys/fcntl.h>
# include "get_next_line.h"
# ifndef X_EVENT_KEY_PRESS
#  define X_EVENT_KEY_PRESS		2
# endif
# ifndef KEY_ESC
#  define KEY_ESC			53
# endif
# ifndef KEY_W
#  define KEY_W			13
# endif
# ifndef KEY_A
#  define KEY_A			0
# endif
# ifndef KEY_S
#  define KEY_S			1
# endif
# ifndef KEY_D
#  define KEY_D			2
# endif
# ifndef TILE
#  define TILE 32
# endif
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# ifndef WALL_PATH
#  define WALL_PATH "./image/wall.xpm"
# endif
# ifndef GROUND_PATH
#  define GROUND_PATH "./image/dadak.xpm"
# endif
# ifndef EXIT_PATH
#  define EXIT_PATH "./image/enemy.xpm"
# endif
# ifndef PLAYER_PATH
#  define PLAYER_PATH "./image/player.xpm"
# endif
# ifndef COLLECTABLE_PATH
#  define COLLECTABLE_PATH "./image/collectable.xpm"
# endif

typedef struct s_oneforall
{
	char	**map;
	int		line_cnt;
	int		char_cnt;
	int		player_x;
	int		player_y;
	int		move_cnt;
	void	*mlx;
	void	*win;
	void	*imgs[5];
	char	*argv;
	int		img_width;
	int		img_height;
}	t_oneforall;

typedef enum e_objs
{
	WALL,
	GROUND,
	EXIT,
	PLAYER,
	COLLECTABLE
}	t_objs;

/* utils.c */
void	put_step(t_oneforall *all);
/* map.c */
int		vali_map_inner(t_oneforall **all);
int		vali_map_outter(t_oneforall **all);
int		vali_map_shape(t_oneforall **all);
int		validation(t_oneforall **all, int argc, char **argv);
/* draw.c */
int		draw(t_oneforall *all);
int		key_press(int keycode, t_oneforall *all);
/* event.c */
void	press_a(t_oneforall *all);
void	press_s(t_oneforall *all);
void	press_d(t_oneforall *all);
void	press_w(t_oneforall *all);

#endif
