/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:36:14 by yalp              #+#    #+#             */
/*   Updated: 2025/01/28 16:20:16 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include <stdio.h>

typedef struct t_map
{
	int		map_width;
	int		map_height;
	int		player_loc[2];
	int		coins;
	char	**map_layout;
	int		player;
	int		exit;
	int		move;
	void	*mlx;
	void	*win;
}	t_map;

void	map(t_map *map);
int		check(t_map map1);
int		check_rectangle(t_map *map);
void	move_right(t_map *map1);
void	move_up(t_map *map1);
void	move_left(t_map *map1);
void	move_down(t_map *map1);
void	map_sets(t_map *map1);
int		count_coin(t_map *map1);
int		count_exit(t_map *map1);
int		count_player(t_map *map1);
void	put_wall(void *win, void *mlx, t_map map1);
void	put_ground(void *win, void *mlx, t_map map1);
void	put_coin(void *win, void *mlx, t_map map1);
void	put_player(void *win, void *mlx, t_map map1);
void	put_player(void *win, void *mlx, t_map map1);
void	put_wall(void *win, void *mlx, t_map map1);
void	put_ground(void *win, void *mlx, t_map map1);
void	put_coin(void *win, void *mlx, t_map map1);
void	put_exit(void *win, void *mlx, t_map map1);
void	put_exit_locked(void *win, void *mlx, t_map map1);
int		find_loc_y(t_map *map1, char a);
void	freeall(t_map *map1);
int		map_len(t_map *map);
int		find_loc_y(t_map *map1, char a);
int		find_loc_x(t_map *map1, char a);
void	error_put(t_map map1);

#endif