/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:16:03 by yalp              #+#    #+#             */
/*   Updated: 2025/01/31 16:14:03 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keys(t_map *map1)
{
	put_player(map1->win, map1->mlx, *map1);
	put_wall(map1->win, map1->mlx, *map1);
	put_ground(map1->win, map1->mlx, *map1);
	put_coin(map1->win, map1->mlx, *map1);
	ft_printf("\ncoins:%d  move:%d", map1->coins, map1->move);
}

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
	if (keycode == 'a' || keycode == 's' || keycode == 'w' || keycode == 'd')
		keys(map1);
	if (map1->coins != 0)
		put_exit_locked(map1->win, map1->mlx, *map1);
	else
		put_exit(map1->win, map1->mlx, *map1);
	if (find_loc_y(map1, 'E') == -1 || keycode == 65307)
	{
		freeall(map1);
		exit(1);
	}
	return (0);
}

int	close_window(t_map *map1)
{
	key_hook(65307, map1);
	return (0);
}

void	arg_check(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	if (argc != 2)
	{
		ft_printf("%s", "BAD ARGUMENTS");
		exit(1);
	}
	while (argv[1][i])
		i++;
	if (!(argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e' &&
		argv[1][i - 3] == 'b' && argv[1][i - 4] == '.') || i < 5)
	{
		ft_printf("%s", "MAP FILE IS NOT A .ber FILE");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s", "MAP FILE CAN NOT OPEN");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_map	map1;
	int		i;

	i = 0;
	arg_check(argc, argv);
	map(&map1, argv[1]);
	map_sets(&map1);
	error_put(map1);
	ft_printf("coins:%d move:%d", map1.coins, map1.move);
	map1.mlx = mlx_init();
	map1.win = mlx_new_window(map1.mlx, (map1.map_width) * 32, \
	map1.map_height * 32, "game");
	put_player(map1.win, map1.mlx, map1);
	put_exit_locked(map1.win, map1.mlx, map1);
	put_wall(map1.win, map1.mlx, map1);
	put_ground(map1.win, map1.mlx, map1);
	put_coin(map1.win, map1.mlx, map1);
	mlx_key_hook(map1.win, key_hook, &map1);
	mlx_hook(map1.win, 17, 0, close_window, &map1);
	mlx_loop(map1.mlx);
	return (0);
}
