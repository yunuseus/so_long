/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:13:05 by yalp              #+#    #+#             */
/*   Updated: 2025/01/31 16:14:21 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
