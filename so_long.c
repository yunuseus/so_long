#include "so_long.h"

void swap_loc(t_map map1, int x1, int y1, int x2, int y2)
{
	char tmp = map1.map_layout[x1][x2];
	map1.map_layout[x1][x2] = map1.map_layout[x2][y2];
	map1.map_layout[x2][y2]= tmp;
}
void put_wall(void *win, void *mlx, t_map map1)
{
	int x;
	int y;
	int w;
	y = 0;
	void *img = mlx_xpm_file_to_image(mlx, "barrier_open.xpm",&w, &w);
	while (map1.map_layout[y])
		{
			x = 0;
			while (map1.map_layout[y][x])
			{
				if (map1.map_layout[y][x] == '1')
				{	
					mlx_put_image_to_window(mlx, win, img, x*32, y*32);
				}
				x++;
			}
				y++;

		}
}
void put_ground(void *win, void *mlx, t_map map1)
{
	int x;
	int y;
	int w;
	y = 0;
	void *ground = mlx_xpm_file_to_image(mlx, "ground.xpm", &w, &w);
	while (map1.map_layout[y])
	{
		x = 0;
		while (map1.map_layout[y][x])
		{
			if (map1.map_layout[y][x] == '0')
			{
				mlx_put_image_to_window(mlx,win,ground,x*32,y*32);
			}
			x++;
		}
			y++;
			
	}
}
void put_coin(void *win, void *mlx, t_map map1)
{
	int x;
	int y;
	int w;
	y = 0;
	void *coin = mlx_xpm_file_to_image(mlx, "coin.xpm", &w, &w);
	while (map1.map_layout[y])
	{
		x = 0;
		while (map1.map_layout[y][x])
		{
			if (map1.map_layout[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx,win,coin,x*32,y*32);
			}
			x++;
		}
			y++;
	}
}

int main()
{
	t_map map1;
	map(&map1);
	int i = 0;
	int x = 0;
	int y = 0;
	int d = 0;
	int a = 0;
	int b = 0;
	int w;
	while(map1.map_layout[i])
		printf("%s", map1.map_layout[i++]);
	
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, (map1.map_width -1)*32, map1.map_height*32, "dnme");

	while (1)
	{
	put_wall(win,mlx,map1);
	put_ground(win,mlx,map1);
	put_coin(win,mlx,map1);
	swap_loc(map1, 2,3,2,4);
	sleep(1);
	swap_loc(map1, 2,4,2,3);

	}
	mlx_loop(mlx);
	
	
    return (0);
}
