/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:27:32 by yalp              #+#    #+#             */
/*   Updated: 2025/01/31 19:30:12 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(t_map map1)
{
	int		i;
	int		j;
	char	*chars;

	i = 0;
	chars = "01CEP";
	while (i < map1.map_height)
	{
		j = 0;
		while (j < map1.map_width)
		{
			if (!ft_strchr_gnl(chars, map1.map_layout[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	flood_fill(t_map *map1)
{
	t_map	map2;
	int		i;
	int		x;
	int		y;

	x = find_loc_y(map1, 'P');
	y = find_loc_x(map1, 'P');
	map2.map_layout = malloc(mapsize(map1) + 1);
	if (!map2.map_layout)
		return (0);
	mapcpy(map1, &map2);
	real_fill(&map2, y, x);
	if (count_coin(&map2) == 0 && check_exit_around(map2))
		return (1);
	return (0);
}

int	check(t_map map1)
{
	if (check_rectangle(&map1) != 0)
		return (-4);
	if (count_player(&map1) != 1)
		return (-2);
	if (count_coin(&map1) < 1)
		return (-5);
	if (count_exit(&map1) != 1)
		return (-3);
	if (check_chars(map1) != 0)
		return (-7);
	if (flood_fill(&map1) != 1)
		return (-6);
	return (0);
}

void	error_put(t_map map1)
{
	int	i;

	i = check(map1);
	if (i == 0)
		return ;
	if (i == -2)
		ft_printf("%s\n%s", "ERROR", "WRONG NUMBER OF PLAYER");
	if (i == -3)
		ft_printf("%s\n%s", "ERROR", "WRONG NUMBER OF EXIT");
	if (i == -4)
		ft_printf("%s\n%s", "ERROR", "BAD MAP LAYOUT");
	if (i == -5)
		ft_printf("%s\n%s", "ERROR", "NO COINS ON MAP");
	if (i == -7)
		ft_printf("%s\n%s", "ERROR", "UNDEFINED CHAR IN MAP");
	if (i == -6)
		ft_printf("%s\n%s", "ERROR", "IMPOSSIBLE TO COMPLATE THE MAP");
	exit(check(map1));
}
