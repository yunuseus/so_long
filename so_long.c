/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:16:03 by yalp              #+#    #+#             */
/*   Updated: 2025/01/28 16:08:06 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_map *map1)
{
	if (keycode == 'a')
		move_left(map1);
	if (keycode == 'd')
		move_right(map1);
	if (keycode == 'w')
		move_up(map1);
	if (keycode == 's')
		move_down(map1);
	put_player(map1->win, map1->mlx, *map1);
	put_wall(map1->win, map1->mlx, *map1);
	put_ground(map1->win, map1->mlx, *map1);
	put_coin(map1->win, map1->mlx, *map1);
	ft_printf("\ncoins:%d  move:%d", map1->coins, map1->move);
	if (map1->coins != 0)
		put_exit_locked(map1->win, map1->mlx, *map1);
	else
		put_exit(map1->win, map1->mlx, *map1);
	if (find_loc_y(map1, 'E') == -1)
	{
		freeall(map1);
		exit(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map1;
	int		i;

	i = 0;
	map(&map1);
	map_sets(&map1);
	while (map1.map_layout[i])
		ft_printf("%s", map1.map_layout[i++]);
	map1.mlx = mlx_init();
	map1.win = mlx_new_window(map1.mlx, (map1.map_width) * 32, \
	map1.map_height * 32, "game");
	put_player(map1.win, map1.mlx, map1);
	put_exit_locked(map1.win, map1.mlx, map1);
	put_wall(map1.win, map1.mlx, map1);
	put_ground(map1.win, map1.mlx, map1);
	put_coin(map1.win, map1.mlx, map1);
	mlx_key_hook(map1.win, key_hook, &map1);
	mlx_loop(map1.mlx);
	return (0);
}
