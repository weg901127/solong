/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:54:21 by gilee             #+#    #+#             */
/*   Updated: 2021/11/16 15:59:03 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	press_a(t_oneforall *all)
{
	if (all->player_x != 0 && all->map[all->player_y][all->player_x - 1] != '1')
	{
		if (all->map[all->player_y][all->player_x] != 'E')
			all->map[all->player_y][all->player_x] = '0';
		if (all->map[all->player_y][all->player_x - 1] == 'C')
			(all->collectable_cnt)--;
		all->map[all->player_y][--(all->player_x)] = 'P';
	}
}

void	press_d(t_oneforall *all)
{
	if (all->player_x != all->char_cnt - 1
		&& all->map[all->player_y][all->player_x + 1] != '1')
	{
		if (all->map[all->player_y][all->player_x] != 'E')
			all->map[all->player_y][all->player_x] = '0';
		if (all->map[all->player_y][all->player_x + 1] == 'C')
			(all->collectable_cnt)--;
		all->map[all->player_y][++(all->player_x)] = 'P';
	}
}

void	press_w(t_oneforall *all)
{
	if (all->player_y != 0
		&& all->map[all->player_y - 1][all->player_x] != '1')
	{
		if (all->map[all->player_y][all->player_x] != 'E')
			all->map[all->player_y][all->player_x] = '0';
		if (all->map[all->player_y - 1][all->player_x] == 'C')
			(all->collectable_cnt)--;
		all->map[--(all->player_y)][all->player_x] = 'P';
	}
}

void	press_s(t_oneforall *all)
{
	if (all->player_y != all->line_cnt - 1
		&& all->map[all->player_y + 1][all->player_x] != '1')
	{
		if (all->map[all->player_y][all->player_x] != 'E')
			all->map[all->player_y][all->player_x] = '0';
		if (all->map[all->player_y + 1][all->player_x] == 'C')
			(all->collectable_cnt)--;
		all->map[++(all->player_y)][all->player_x] = 'P';
	}
}

void	put_event(t_oneforall *all, void (*func)(t_oneforall *))
{
	func(all);
	all->map[all->exit_y][all->exit_x] = 'E';
	if (all->collectable_cnt == 0 && all->exit_x == all->player_x
		&& all->exit_y == all->player_y)
		exit(0);
}
