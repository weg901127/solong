/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:54:50 by gilee             #+#    #+#             */
/*   Updated: 2021/11/16 19:13:31 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "../mlx/mlx.h"
# include <stdio.h>
# include <sys/fcntl.h>
# include "get_next_line.h"
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define TILE 				32
# define WALL_PATH "./image/wall.xpm"
# define GROUND_PATH "./image/dadak.xpm"
# define EXIT_PATH "./image/enemy.xpm"
# define PLAYER_PATH "./image/player.xpm"
# define COLLECTABLE_PATH "./image/collectable.xpm"
# ifndef TRUE
#  define TRUE 	1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_oneforall
{
	char	**map;
	int		line_cnt;
	int		char_cnt;
	int		player_x;
	int		player_y;
	int		move_cnt;
	int		collectable_cnt;
	int		exit_x;
	int		exit_y;
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
void	my_exit(t_oneforall **all);
/* map.c */
int		set_map(int line_cnt, char ***map, char *argv);
/* validation.c */
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
void	put_event(t_oneforall *all, void (*func)(t_oneforall *));

#endif
