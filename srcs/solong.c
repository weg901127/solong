/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:54:32 by gilee             #+#    #+#             */
/*   Updated: 2021/11/16 20:19:13 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"
#include <sys/fcntl.h>
#include <unistd.h>

int	check_imgs(void)
{
	int	fd;

	fd = open(WALL_PATH, O_RDONLY) == -1;
	close(fd);
	fd |= open(GROUND_PATH, O_RDONLY) == -1;
	close(fd);
	fd |= open(EXIT_PATH, O_RDONLY) == -1;
	close(fd);
	fd |= open(PLAYER_PATH, O_RDONLY) == -1;
	close(fd);
	fd |= open(COLLECTABLE_PATH, O_RDONLY) == -1;
	close(fd);
	return (fd);
}

void	init_imgs(t_oneforall *all)
{
	int	*img_w;
	int	*img_h;
	int	tmp;

	tmp = 0;
	img_w = &(all->img_width);
	img_h = &(all->img_height);
	all->imgs[0] = mlx_xpm_file_to_image
		(all->mlx, WALL_PATH, img_w, img_h);
	all->imgs[1] = mlx_xpm_file_to_image
		(all->mlx, GROUND_PATH, img_w, img_h);
	all->imgs[2] = mlx_xpm_file_to_image
		(all->mlx, EXIT_PATH, img_w, img_h);
	all->imgs[3] = mlx_xpm_file_to_image
		(all->mlx, PLAYER_PATH, img_w, img_h);
	all->imgs[4] = mlx_xpm_file_to_image
		(all->mlx, COLLECTABLE_PATH, img_w, img_h);
}

int	key_press(int keycode, t_oneforall *all)
{
	if (keycode == KEY_A)
		put_event(all, press_a);
	else if (keycode == KEY_D)
		put_event(all, press_d);
	else if (keycode == KEY_W)
		put_event(all, press_w);
	else if (keycode == KEY_S)
		put_event(all, press_s);
	else if (keycode == KEY_ESC)
		my_exit(&all);
	put_step(all);
	return (0);
}

int	close_win(t_oneforall *all)
{
	my_exit(&all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_oneforall	*all;

	all = (t_oneforall *)calloc(1, sizeof(t_oneforall));
	if (!validation(&all, argc, argv) || check_imgs())
	{
		write(0, "ERROR\n", 6);
		my_exit(&all);
	}
	all->mlx = mlx_init();
	all->win = mlx_new_window
		(all->mlx, TILE * all->char_cnt, TILE * all->line_cnt, "so_long");
	init_imgs(all);
	mlx_hook(all->win, X_EVENT_KEY_EXIT, 0, &close_win, all);
	mlx_hook(all->win, X_EVENT_KEY_PRESS, 0, &key_press, all);
	mlx_loop_hook(all->mlx, draw, all);
	mlx_loop(all->mlx);
	return (0);
}
