/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:13:05 by yalp              #+#    #+#             */
/*   Updated: 2025/02/01 15:01:16 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ffill(t_map *map2, t_map *map1)
{
	int	i;

	i = 0;
	while (i < map1->map_height)
		free(map2->map_layout[i++]);
	free(map2->map_layout);
}

void	free_map(t_map *map1)
{
	int	i;

	i = 0;
	while (i < map1->map_height)
		free(map1->map_layout[i++]);
	free(map1->map_layout);
}

void	freeall(t_map *map1)
{
	mlx_clear_window(map1->mlx, map1->win);
	mlx_destroy_window(map1->mlx, map1->win);
	mlx_destroy_display(map1->mlx);
	free(map1->mlx);
	free_map(map1);
}
