/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:54:37 by gilee             #+#    #+#             */
/*   Updated: 2021/11/16 20:30:16 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	put_step(t_oneforall *all)
{
	printf("%d\n", ++(all->move_cnt));
}

void	my_exit(t_oneforall **all)
{
	int	tmp;

	tmp = 0;
	while (tmp < (*all)->line_cnt)
		free((*all)->map[tmp++]);
	free((*all)->map);
	if ((*all)->mlx)
		mlx_destroy_window((*all)->mlx, (*all)->win);
	tmp = 0;
	if ((*all)->imgs[0])
		while (tmp < 5)
			mlx_destroy_image((*all)->mlx, (*all)->imgs[tmp++]);
	free((*all)->argv);
	free(*all);
	exit(0);
}
