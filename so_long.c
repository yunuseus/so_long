#include "so_long.h"

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
	while(map1.map_layout[i])
		printf("%s", map1.map_layout[i++]);
	
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "dnme");

	while (map1.map_layout[y])
	{
		x = 0;
		while (map1.map_layout[y][x])
		{
			if (map1.map_layout[y][x] == '1')
			{	a = 0;
				while (a < 32)
				{
					b = 0;
					while (b < 32)
					{
						mlx_pixel_put(mlx,win,x*32+a,y*32+b, 0x00FF00);
						b++;
					}
					a++;
				}
			}
			x++;
		}
			y++;
			
	}
	y = 0;
	while (map1.map_layout[y])
	{
		x = 0;
		while (map1.map_layout[y][x])
		{
			if (map1.map_layout[y][x] == '0')
			{	a = 0;
				while (a < 32)
				{
					b = 0;
					while (b < 32)
					{
						mlx_pixel_put(mlx,win,x*32+a,y*32+b, 0xFF0000);
						b++;
					}
					a++;
				}
			}
			x++;
		}
			y++;
			
	}

	mlx_loop(mlx);
	
	
    return (0);
}
