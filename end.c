/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:13:05 by yalp              #+#    #+#             */
/*   Updated: 2025/01/28 14:20:28 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeall(t_map *map1)
{
	mlx_clear_window(map1->mlx, map1->win);
	mlx_destroy_window(map1->mlx, map1->win);
	mlx_destroy_display(map1->mlx);
	free(map1->mlx);
	free(map1->map_layout[0]);
	free(map1->map_layout[1]);
	free(map1->map_layout[2]);
	free(map1->map_layout[3]);
	free(map1->map_layout[4]);
	free(map1->map_layout[5]);
	free(map1->map_layout[6]);
	free(map1->map_layout);
}
