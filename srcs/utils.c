#include "../header/solong.h"

void	put_step(t_oneforall *all)
{
	char	*tmp;

	tmp = ft_itoa(++(all->move_cnt));
	ft_putstr_fd(tmp, 0);
	write(0, "\n", 1);
}
