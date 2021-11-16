/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:54:15 by gilee             #+#    #+#             */
/*   Updated: 2021/11/16 20:27:50 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

static void	*put_img(t_oneforall *all, int tmp_char, int tmp_line)
{
	void	*img;

	img = NULL;
	if (all->map[tmp_line][tmp_char] == '1')
		img = all->imgs[WALL];
	else if (all->map[tmp_line][tmp_char] == '0')
		img = all->imgs[GROUND];
	else if (all->map[tmp_line][tmp_char] == 'E')
		img = all->imgs[EXIT];
	else if (all->map[tmp_line][tmp_char] == 'P')
		img = all->imgs[PLAYER];
	else if (all->map[tmp_line][tmp_char] == 'C')
		img = all->imgs[COLLECTABLE];
	return (img);
}

int	draw(t_oneforall *all)
{
	int		tmp_char;
	int		tmp_line;

	tmp_char = all->char_cnt;
	tmp_line = all->line_cnt;
	while (tmp_line--)
	{
		while (tmp_char--)
		{
			mlx_put_image_to_window(all->mlx, all->win,
				put_img(all, tmp_char, tmp_line),
				tmp_char * TILE, tmp_line * TILE);
		}
		tmp_char = all->char_cnt;
	}
	return (0);
}
