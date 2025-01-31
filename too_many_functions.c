/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   too_many_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:07:15 by yalp              #+#    #+#             */
/*   Updated: 2025/01/31 18:41:47 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_exit_locked(void *win, void *mlx, t_map map1)
{
	int		x;
	int		y;
	int		w;
	void	*exit;

	y = 0;
	exit = mlx_xpm_file_to_image(mlx, "photos/exit_locked.xpm", &w, &w);
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

int	find_loc_y(t_map *map1, char a)
{
	int	i;
	int	j;

	i = 0;
	while ((*map1).map_layout[i])
	{
		j = 0;
		while ((*map1).map_layout[i][j])
		{
			if ((*map1).map_layout[i][j] == a)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	find_loc_x(t_map *map1, char a)
{
	int	i;
	int	j;

	i = 0;
	while (map1->map_layout[i])
	{
		j = 0;
		while (map1->map_layout[i][j])
		{
			if (map1->map_layout[i][j] == a)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	count_exit(t_map *map1)
{
	int	x;
	int	y;
	int	exit;

	exit = 0;
	x = 0;
	while (map1->map_layout[x])
	{
		y = 0;
		while (map1->map_layout[x][y])
		{
			if (map1->map_layout[x][y] == 'E')
				exit++;
			y++;
		}
		x++;
	}
	return (exit);
}

int	count_coin(t_map *map1)
{
	int	x;
	int	y;
	int	coin;

	coin = 0;
	x = 0;
	while (map1->map_layout[x])
	{
		y = 0;
		while (map1->map_layout[x][y])
		{
			if (map1->map_layout[x][y] == 'C')
				coin++;
			y++;
		}
		x++;
	}
	if (coin == 0)
		return (0);
	return (coin);
}
