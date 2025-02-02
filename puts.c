/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:41:12 by yalp              #+#    #+#             */
/*   Updated: 2025/02/02 14:06:29 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	put_player(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*player;

	y = 0;
	player = mlx_xpm_file_to_image(mlx, "textures/player.xpm", &w, &w);
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
}

void	put_wall(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*wall;

	y = 0;
	wall = mlx_xpm_file_to_image(mlx, "textures/barrier_open.xpm", &w, &w);
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
}

void	put_ground(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*ground;

	y = 0;
	ground = mlx_xpm_file_to_image(mlx, "textures/ground.xpm", &w, &w);
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
}

void	put_coin(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*coin;

	y = 0;
	coin = mlx_xpm_file_to_image(mlx, "textures/coin.xpm", &w, &w);
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
}

void	put_exit(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*exit;

	y = 0;
	exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &w, &w);
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
