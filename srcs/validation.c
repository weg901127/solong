/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:03:12 by gilee             #+#    #+#             */
/*   Updated: 2021/11/16 18:21:46 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

static void	set_obj(t_oneforall *all, int *cnt, int tmp_char, int tmp_line)
{
	tmp_char = all->char_cnt - 1;
	tmp_line = all->line_cnt;
	while (tmp_line--)
	{
		while (tmp_char != -1)
		{
			if (all->map[tmp_line][tmp_char] == 'C')
				cnt[0]++;
			else if (all->map[tmp_line][tmp_char] == 'E')
			{
				all->exit_x = tmp_char;
				all->exit_y = tmp_line;
				cnt[1]++;
			}
			else if (all->map[tmp_line][tmp_char] == 'P')
			{
				all->player_x = tmp_char;
				all->player_y = tmp_line;
				cnt[2]++;
			}
			tmp_char--;
		}
		tmp_char = all->char_cnt - 1;
	}
}

int	vali_map_inner(t_oneforall **all)
{
	int	cnt[3];

	ft_memset(cnt, 0, sizeof(int) * 3);
	set_obj(*all, cnt, 0, 0);
	if (!cnt[0] || cnt[1] != 1 || cnt[2] != 1)
		return (FALSE);
	(*all)->collectable_cnt = cnt[0];
	return (TRUE);
}

int	vali_map_outter(t_oneforall **all)
{
	int	tmp_char;
	int	tmp_line;

	if (!set_map((*all)->line_cnt, &(*all)->map, (*all)->argv))
		return (FALSE);
	tmp_char = (*all)->char_cnt;
	tmp_line = (*all)->line_cnt;
	while (tmp_line)
	{
		tmp_line--;
		while (tmp_char)
		{
			tmp_char--;
			if (tmp_line == (*all)->line_cnt - 1
				&& (*all)->map[tmp_line][tmp_char] != '1')
				return (FALSE);
			else if (tmp_line == 0 && (*all)->map[tmp_line][tmp_char] != '1')
				return (FALSE);
			else if ((tmp_char == 0 || tmp_char == (*all)->char_cnt - 1)
				&& (*all)->map[tmp_line][tmp_char] != '1')
				return (FALSE);
		}
		tmp_char = (*all)->char_cnt;
	}
	return (TRUE);
}

int	vali_map_shape(t_oneforall **all)
{
	int		fd;
	char	*buf;

	(*all)->line_cnt = 0;
	(*all)->char_cnt = 0;
	fd = open((*all)->argv, O_RDONLY);
	while (get_next_line(fd, &buf))
	{
		if (!(*all)->line_cnt)
			(*all)->char_cnt = ft_strlen(buf);
		if ((*all)->line_cnt && (*all)->char_cnt != (int)ft_strlen(buf))
			return (FALSE);
		((*all)->line_cnt)++;
		if (buf)
			free(buf);
	}
	close(fd);
	return (TRUE);
}

int	validation(t_oneforall **all, int argc, char **argv)
{
	int	res;

	if (argc < 2 || argc > 2)
		return (FALSE);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		return (FALSE);
	(*all)->argv = ft_strdup(argv[1]);
	res = open((*all)->argv, O_RDONLY);
	close(res);
	if (res == -1)
		return (FALSE);
	res = vali_map_shape(all);
	res &= vali_map_outter(all);
	res &= vali_map_inner(all);
	return (res);
}
