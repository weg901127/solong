#include "../header/solong.h"

int	draw(t_oneforall *all)
{
	void	*img;
	int		tmp_char;
	int		tmp_line;

	tmp_char = all->char_cnt;
	tmp_line = all->line_cnt;
	while (tmp_line--)
	{
		while (tmp_char--)
		{
			if (all->map[tmp_line][tmp_char] == '1')
				img = all->imgs[WALL];
			if (all->map[tmp_line][tmp_char] == '0')
				img = all->imgs[GROUND];
			if (all->map[tmp_line][tmp_char] == 'E')
				img = all->imgs[EXIT];
			if (all->map[tmp_line][tmp_char] == 'P')
				img = all->imgs[PLAYER];
			if (all->map[tmp_line][tmp_char] == 'C')
				img = all->imgs[COLLECTABLE];
			mlx_put_image_to_window
				(all->mlx, all->win, img, tmp_char * TILE, tmp_line * TILE);
		}
		tmp_char = all->char_cnt;
	}
	return (0);
}
