/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:27:32 by yalp              #+#    #+#             */
/*   Updated: 2025/01/27 18:27:05 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check(t_map map1)
{
	if (check_rectangle(&map1) != 1);
		return (-4);
	if (count_player(&map1) == 0)
		return (-2);
	if (count_coin(&map1) == 0)
		return (-5);
	if (count_exit(&map1) == 0)
		return (-3);
	if (flood_fill(&map1) != 1)
		return (-6);
	return (0);
}