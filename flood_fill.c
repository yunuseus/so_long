/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:18:31 by yalp              #+#    #+#             */
/*   Updated: 2025/02/01 15:01:27 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*tmp;

	i = 0;
	len = ft_strlen(s1);
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[len] = '\0';
	return (tmp);
}

int	check_exit_around(t_map map2)
{
	int	x;
	int	y;

	x = find_loc_x(&map2, 'E');
	y = find_loc_y(&map2, 'E');
	if (map2.map_layout[y][x + 1] == 'Y' || map2.map_layout[y][x - 1] == 'Y' ||
		map2.map_layout[y + 1][x] == 'Y' || map2.map_layout[y - 1][x] == 'Y')
		return (1);
	return (0);
}

void	mapcpy(t_map *map1, t_map *map2)
{
	int	i;

	i = 0;
	while (i < map1->map_height)
	{
		map2->map_layout[i] = ft_strdup(map1->map_layout[i]);
		i++;
	}
	map2->map_layout[i] = NULL;
}

void	real_fill(t_map *map2, int x, int y)
{
	if (map2->map_layout[x][y] == '1' || map2->map_layout[x][y] == 'E'
		|| map2->map_layout[x][y] == 'Y')
		return ;
	map2->map_layout[x][y] = 'Y';
	real_fill(map2, x, y + 1);
	real_fill(map2, x, y - 1);
	real_fill(map2, x + 1, y);
	real_fill(map2, x - 1, y);
}
