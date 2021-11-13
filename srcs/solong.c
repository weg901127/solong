# include "../header/solong.h"

void init_imgs(t_oneforall *all)
{
    int *img_w = &(all->img_width);
    int *img_h = &(all->img_height);

    all->imgs[0] = mlx_xpm_file_to_image(all->mlx, WALL_PATH, img_w, img_h);
    all->imgs[1] = mlx_xpm_file_to_image(all->mlx, GROUND_PATH, img_w, img_h);
    all->imgs[2] = mlx_xpm_file_to_image(all->mlx, EXIT_PATH, img_w, img_h);
    all->imgs[3] = mlx_xpm_file_to_image(all->mlx, PLAYER_PATH, img_w, img_h);
    all->imgs[4] = mlx_xpm_file_to_image(all->mlx, COLLECTABLE_PATH, img_w, img_h);
}

int				key_press(int keycode, t_oneforall *all)
{
    int cnt;

    cnt = 0;
    if (keycode == KEY_A)
        press_a(all);
    else if (keycode == KEY_D)
        press_d(all);
    else if (keycode == KEY_W)
        press_w(all);
    else if (keycode == KEY_S)
        press_s(all);
    else if (keycode == KEY_ESC)
        exit(0);
    //write(0, "1\n", 2);
    printf("%d", ++cnt);
    return (0);
}

int main()
{
    t_oneforall *all;

    all = (t_oneforall *)calloc(1, sizeof(t_oneforall));
    
    if (!validation(&all))
    {
        printf("ERROR\n");
        return 1;
    }
    all->mlx = mlx_init();
    all->win = mlx_new_window(all->mlx, TILE * all->char_cnt, TILE * all->line_cnt, "so_long");
    init_imgs(all);
    mlx_hook(all->win, X_EVENT_KEY_PRESS, 0, &key_press, all);
    mlx_loop_hook(all->mlx, draw, all);
    mlx_loop(all->mlx);
    
    return (0);
    
}

