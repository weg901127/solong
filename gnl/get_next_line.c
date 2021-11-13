/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:01:29 by gilee             #+#    #+#             */
/*   Updated: 2021/02/26 19:01:34 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_return(int fd, char **backup, char **cur)
{
	int		read_len;
	char	*tmp;
	char	*buf;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!(ft_strchr(*backup, '\n')))
	{
		if ((read_len = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			buf = 0;
			return (-1);
		}
		else if (read_len == 0)
			break ;
		*(buf + read_len) = '\0';
		tmp = ft_strjoin(*backup, buf);
		if (*backup)
			free(*backup);
		*backup = tmp;
	}
	*cur = ft_strchr(*backup, '\n');
	free(buf);
	return (1);
}

char	*set_after_nl(char **backup, int *flagcheck, char **cur)
{
	char *tmp;

	tmp = 0;
	if (*cur)
		tmp = ft_strdup(*cur + 1);
	else
		*flagcheck = 0;
	free(*backup);
	return (tmp);
}

char	*set_prev_nl(char **backup, char **cur)
{
	char			*tmp;
	unsigned int	pos_nl;

	tmp = ft_strdup(*backup);
	if (*cur)
	{
		pos_nl = *cur - *backup;
		*(tmp + pos_nl) = '\0';
	}
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	int			flagcheck;
	char		*cur;

	cur = 0;
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	if ((flagcheck = find_return(fd, &backup[fd], &cur)) == -1)
		return (-1);
	if (!(*line = set_prev_nl(&backup[fd], &cur)))
		return (0);
	if (!(backup[fd] = set_after_nl(&backup[fd], &flagcheck, &cur)))
		return (0);
	return (flagcheck);
}
