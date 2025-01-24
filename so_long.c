/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:16:03 by yalp              #+#    #+#             */
/*   Updated: 2025/01/24 18:36:33 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_map *map1)
{
	if (keycode == 'a')  // Sol ok tuşu (yani 'left arrow')
        move_left(map1);   // Kareyi sola hareket ettir
    if (keycode == 'd')  // Sağ ok tuşu (yani 'right arrow')
        move_right(map1);     // Kareyi sağa hareket ettir
    if (keycode == 'w')  // Yukarı ok tuşu (yani 'up arrow')
        move_up(map1);     // Kareyi yukarı hareket ettir
    if (keycode == 's')  // Aşağı ok tuşu (yani 'down arrow')
        move_down(map1);
		put_player((*map1).win,(*map1).mlx,(*map1));
		put_wall((*map1).win,(*map1).mlx,(*map1));
		put_ground((*map1).win,(*map1).mlx,(*map1));
		put_coin((*map1).win,(*map1).mlx,(*map1));
	return (0);
}
void put_player(void *win, void *mlx, t_map map1)
{
	int x;
	int y;
	int w;
	y = 0;
	void *img = mlx_xpm_file_to_image(mlx, "player.xpm",&w, &w);
	while (map1.map_layout[y])
		{
			x = 0;
			while (map1.map_layout[y][x])
			{
				if (map1.map_layout[y][x] == 'P')
				{	
					mlx_put_image_to_window(mlx, win, img, x*32, y*32);
				}
				x++;
			}
				y++;

		}
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
	map_sets(&map1);
	int i = 0;
	int x = 0;
	int y = 0;
	int d = 0;
	int a = 0;
	int b = 0;
	int w;
	
	while(map1.map_layout[i])
		ft_printf("%s", map1.map_layout[i++]);
	

	map1.mlx = mlx_init();
	map1.win = mlx_new_window(map1.mlx, (map1.map_width -1)*32, map1.map_height*32, "dnme");
	ft_printf("%d", map1.coins);


		put_player(map1.win,map1.mlx,map1);
		put_wall(map1.win,map1.mlx,map1);
		put_ground(map1.win,map1.mlx,map1);
		put_coin(map1.win,map1.mlx,map1);
		sleep(1);
		mlx_key_hook(map1.win,key_hook,&map1);
	
	mlx_loop(map1.mlx);
    return (0);
}
