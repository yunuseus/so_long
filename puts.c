/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:41:12 by yalp              #+#    #+#             */
/*   Updated: 2025/01/28 15:10:02 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*player;

	y = 0;
	player = mlx_xpm_file_to_image(mlx, "photos/player.xpm", &w, &w);
	while (map1.map_layout[y])
	{
		x = 0;
		while (map1.map_layout[y][x])
		{
			if (map1.map_layout[y][x] == 'P')
			{	
				mlx_put_image_to_window(mlx, win, player, x * 32, y * 32);
				mlx_destroy_image(mlx, player);
			}
			x++;
		}
		y++;
	}
	free(player);
}

void	put_wall(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*wall;

	y = 0;
	wall = mlx_xpm_file_to_image(mlx, "photos/barrier_open.xpm", &w, &w);
	while (map1.map_layout[y])
	{
		x = 0;
		while (map1.map_layout[y][x])
		{
			if (map1.map_layout[y][x] == '1')
				mlx_put_image_to_window(mlx, win, wall, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_destroy_image(mlx, wall);
	free(wall);
}

void	put_ground(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*ground;

	y = 0;
	ground = mlx_xpm_file_to_image(mlx, "photos/ground.xpm", &w, &w);
	while (map1.map_layout[y])
	{
		x = 0;
		while (map1.map_layout[y][x])
		{
			if (map1.map_layout[y][x] == '0')
				mlx_put_image_to_window(mlx, win, ground, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_destroy_image(mlx, ground);
	free(ground);
}

void	put_coin(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*coin;

	y = 0;
	coin = mlx_xpm_file_to_image(mlx, "photos/coin.xpm", &w, &w);
	while (map1.map_layout[y])
	{
		x = 0;
		while (map1.map_layout[y][x])
		{
			if (map1.map_layout[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, coin, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_destroy_image(mlx, coin);
	free(coin);
}

void	put_exit(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*exit;

	y = 0;
	exit = mlx_xpm_file_to_image(mlx, "photos/exit.xpm", &w, &w);
	while (map1.map_layout[y])
	{
		x = 0;
		while (map1.map_layout[y][x])
		{
			if (map1.map_layout[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_destroy_image(mlx, exit);
}
