/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:54:27 by gilee             #+#    #+#             */
/*   Updated: 2021/11/16 18:05:21 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

int	set_map(int line_cnt, char ***map, char *argv)
{
	int		fd;
	int		cnt;
	char	*buf;

	cnt = 0;
	fd = open(argv, O_RDONLY);
	*map = (char **)calloc(line_cnt, sizeof(char *));
	while (cnt < line_cnt)
	{
		get_next_line(fd, &buf);
		(*map)[cnt++] = buf;
	}
	close(fd);
	return (TRUE);
}
