#include "../header/solong.h"
#include <sys/fcntl.h>

static int	set_map(int line_cnt, char ***map, char *argv)
{
	int		fd;
	int		cnt;
	char	*buf;

	cnt = 0;
	fd = open(argv, O_RDONLY);
	*map = (char **)calloc(line_cnt, sizeof(char *));
	while(cnt < line_cnt)
	{
		get_next_line(fd, &buf);
		(*map)[cnt++] = buf;
	}
	close(fd);
	return (TRUE);
}

int	vali_map_inner(t_oneforall **all)
{
	int cnt[3];
	int tmp_char;
	int tmp_line;

	tmp_char = (*all)->char_cnt - 1;
	tmp_line = (*all)->line_cnt;
	cnt[0] = 0;
	cnt[1] = 0;
	cnt[2] = 0;
	while (tmp_line--)
	{
		while (tmp_char != -1)
		{
			if ((*all)->map[tmp_line][tmp_char] == 'C')
				cnt[0]++;
			else if ((*all)->map[tmp_line][tmp_char] == 'E')
				cnt[1]++;
			else if ((*all)->map[tmp_line][tmp_char] == 'P')
			{
				(*all)->player_x = tmp_char;
				(*all)->player_y = tmp_line;
				cnt[2]++;
			}
			tmp_char--;
		}
		tmp_char = (*all)->char_cnt - 1;
	}
	if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)
		return (FALSE);
	return (TRUE);
}

int vali_map_outter(t_oneforall **all)
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
			if (tmp_line == (*all)->line_cnt - 1 && (*all)->map[tmp_line][tmp_char] != '1')
				return (FALSE);
			else if (tmp_line == 0 && (*all)->map[tmp_line][tmp_char] != '1')
				return (FALSE);
			else if ((tmp_char == 0 || tmp_char == (*all)->char_cnt - 1) && (*all)->map[tmp_line][tmp_char] != '1')
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
	while(get_next_line(fd, &buf))
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

