typedef struct s_map
{
	int map_width;
	int map_height;
	int exit_loc[2];
	int player_loc[2];
	int coins;
	char **map_layout;
	int player;
	int exit;
	int move;
	void *mlx;
	void *win;

}
t_map;

#include "get_next_line.h"
#include <fcntl.h>
#include "minilibx/mlx.h"
#include "printf/ft_printf.h"
#include <stdio.h>
void  map(t_map *map);
int ft_strlen(char *str);
int check_rectangle(t_map *map);
void move_right(t_map *map1);
void move_up(t_map *map1);
void move_left(t_map *map1);
void move_down(t_map *map1);
void map_sets(t_map *map1);
int count_coin(t_map *map1);
int count_exit (t_map *map1);
int count_player (t_map *map1);
void put_wall(void *win, void *mlx, t_map map1);
void put_ground(void *win, void *mlx, t_map map1);
void put_coin(void *win, void *mlx, t_map map1);
void put_player(void *win, void *mlx, t_map map1);
void put_player(void *win, void *mlx, t_map map1);
void put_wall(void *win, void *mlx, t_map map1);
void put_ground(void *win, void *mlx, t_map map1);
void put_coin(void *win, void *mlx, t_map map1);
void put_exit(void *win, void *mlx, t_map map1);
void put_exit_locked(void *win, void *mlx, t_map map1);
int find_loc_y(t_map *map1, char a);