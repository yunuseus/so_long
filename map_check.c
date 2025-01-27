/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:16:16 by yalp              #+#    #+#             */
/*   Updated: 2025/01/27 16:53:52 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int find_loc_y(t_map *map1, char a)
{
	int i = 0;
	int j;

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
int find_loc_x(t_map *map1, char a)
{
	int i = 0;
	int j;

	while ((*map1).map_layout[i])
	{
		j = 0;
		while ((*map1).map_layout[i][j])
		{
			if ((*map1).map_layout[i][j] == a)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

void map_sets(t_map *map1)
{
	if (count_player(map1) == 1)
	{
		map1->player = 1;
		(*map1).player_loc[0] = find_loc_y(map1, 'P');
		(*map1).player_loc[1] = find_loc_x(map1, 'P');
	}
	if (count_exit(map1) == 1)
	{
		map1->coins = 1;
		(*map1).exit_loc[0] = find_loc_x(map1, 'E');
		(*map1).exit_loc[1] = find_loc_y(map1, 'E');
	}
	(*map1).coins = count_coin(map1);
	(*map1).move = 0;
}

int check_rectangle(t_map *map)
{
	int	i;
	int	j;
	i = 0;
	while (map->map_layout[i] && i < map->map_height)
	{
		j = 0;
		while (map->map_layout[i][j] && j < map->map_width -1 )
		{
			if (map->map_layout[0][j] != '1')
				return (-1);
			if (map->map_layout[map->map_height -1][j] != '1')
				return (-1);
			j++;
		}
		if (map->map_layout[i][0] != '1')
			return (-1);
		if (map->map_layout[i][map->map_width -2] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int map_len(t_map *map)
{
	int len;
	int b;
	b = 1;
	len = ft_strlen(map->map_layout[0]);
	while (b < map->map_height -1)
	{
		if (ft_strlen(map->map_layout[b]) != len)
			return (-1);
		b ++;
	}
	if (ft_strlen(map->map_layout[map->map_height -1]) + 1 != len)
		return (-1);
	return (len);
}

void  map(t_map *map)
{
	int x;
	int y;
	int fd;
	int i;
	char *lines;

	i = 0;
	x = 0;
	y = 0;
	fd = open("map", O_RDONLY);
	while(get_next_line(fd) != NULL) // leak
		y++;
	close(fd);
	map->map_height = y;
	map->map_layout = malloc(sizeof(char *) * (y + 1));
	fd = open("map", O_RDONLY);
	map->map_layout[y] = NULL;
	while (y > 0)
	{
		map->map_layout[i] = get_next_line(fd);
		y--;
		i++;
	}
	if (map_len(map) != -1)
		map->map_width = map_len(map) - 1;
}
int count_player (t_map *map1)
{
	int x;
	int y;
	int player;

	player = 0;
	x = 0;
	while ((*map1).map_layout[x])
	{
		y = 0;
		while ((*map1).map_layout[x][y])
		{
			if ((*map1).map_layout[x][y] == 'P')
				player++;
			y++;
		}
		x++;
	}
	return (player);
}
int count_exit (t_map *map1)
{
	int x;
	int y;
	int exit;

	exit = 0;
	x = 0;
	while ((*map1).map_layout[x])
	{
		y = 0;
		while ((*map1).map_layout[x][y])
		{
			if ((*map1).map_layout[x][y] == 'E')
				exit++;
			y++;
		}
		x++;
	}
	return (exit);
}
int count_coin(t_map *map1)
{
	int x;
	int y;
	int coin;

	coin = 0;
	x = 0;
	while ((*map1).map_layout[x])
	{
		y = 0;
		while ((*map1).map_layout[x][y])
		{
			if ((*map1).map_layout[x][y] == 'C')
				coin++;
			y++;
		}
		x++;
	}
	return (coin);
}
