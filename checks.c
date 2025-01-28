/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:27:32 by yalp              #+#    #+#             */
/*   Updated: 2025/01/28 17:21:00 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	f_fill(t_map *map1)
{
	int i;
	i = 1;
	return i;
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
	if (f_fill(&map1) != 1)
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
	if (i == -6)
		ft_printf("%s\n%s", "ERROR", "IMPOSSIBLE TO COMPLATE THE MAP");
	exit(check(map1));
}
