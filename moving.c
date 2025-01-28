/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:59:29 by yalp              #+#    #+#             */
/*   Updated: 2025/01/28 15:05:00 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_map *map1)
{
	if (map1->map_layout[map1->player_loc[0]][map1->player_loc[1] + 1] != '1')
	{
		if (map1->map_layout[map1->player_loc[0]] \
		[map1->player_loc[1] + 1] == 'E' && map1->coins != 0)
			return ;
		if (map1->map_layout[map1->player_loc[0]] \
		[map1->player_loc[1] + 1] == 'C')
			map1->coins--;
		map1->map_layout[map1->player_loc[0]][map1->player_loc[1]] = '0';
		map1->map_layout[map1->player_loc[0]][map1->player_loc[1] + 1] = 'P';
		map1->player_loc[1]++;
		map1->move++;
	}
}

void	move_up(t_map (*map1))
{
	if (map1->map_layout[map1->player_loc[0] - 1][map1->player_loc[1]] != '1')
	{
		if (map1->map_layout[map1->player_loc[0] - 1] \
		[map1->player_loc[1]] == 'E' && map1->coins != 0)
			return ;
		if (map1->map_layout[map1->player_loc[0] - 1] \
		[map1->player_loc[1]] == 'C')
			map1->coins--;
		map1->map_layout[map1->player_loc[0]][map1->player_loc[1]] = '0';
		map1->map_layout[map1->player_loc[0] - 1][map1->player_loc[1]] = 'P';
		map1->player_loc[0]--;
		map1->move++;
	}
}

void	move_left(t_map (*map1))
{
	if (map1->map_layout[map1->player_loc[0]][map1->player_loc[1] - 1] != '1')
	{
		if (map1->map_layout[map1->player_loc[0]] \
		[map1->player_loc[1] - 1] == 'E' && map1->coins != 0)
			return ;
		if (map1->map_layout[map1->player_loc[0]] \
		[map1->player_loc[1] - 1] == 'C')
			map1->coins--;
		map1->map_layout[map1->player_loc[0]][map1->player_loc[1]] = '0';
		map1->map_layout[map1->player_loc[0]][map1->player_loc[1] - 1] = 'P';
		map1->player_loc[1]--;
		map1->move++;
	}	
}

void	move_down(t_map (*map1))
{
	if (map1->map_layout[map1->player_loc[0] + 1][map1->player_loc[1]] != '1')
	{
		if (map1->map_layout[map1->player_loc[0] + 1] \
		[map1->player_loc[1]] == 'E' && map1->coins != 0)
			return ;
		if (map1->map_layout[map1->player_loc[0] + 1] \
		[map1->player_loc[1]] == 'C')
			map1->coins--;
		map1->map_layout[map1->player_loc[0]][map1->player_loc[1]] = '0';
		map1->map_layout[map1->player_loc[0] + 1][map1->player_loc[1]] = 'P';
		map1->player_loc[0]++;
		map1->move++;
	}
}
