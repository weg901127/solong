#include "../header/solong.h"

void press_a(t_oneforall *all)
{
    if (all->player_x != 0 && all->map[all->player_y][all->player_x - 1] != '1')
    {
        all->map[all->player_y][all->player_x] = '0';
        all->map[all->player_y][--(all->player_x)] = 'P';
    }
}

void press_d(t_oneforall *all)
{
    if (all->player_x != all->char_cnt - 1 && all->map[all->player_y][all->player_x + 1] != '1')
    {
        all->map[all->player_y][all->player_x] = '0';
        all->map[all->player_y][++(all->player_x)] = 'P';
    }
}

void press_w(t_oneforall *all)
{
    if (all->player_y != 0 && all->map[all->player_y - 1][all->player_x] != '1')
    {
        all->map[all->player_y][all->player_x] = '0';
        all->map[--(all->player_y)][all->player_x] = 'P';
    }
}

void press_s(t_oneforall *all)
{
    if (all->player_y != all->line_cnt - 1 && all->map[all->player_y + 1][all->player_x] != '1')
    {
        all->map[all->player_y][all->player_x] = '0';
        all->map[++(all->player_y)][all->player_x] = 'P';
    }
}

