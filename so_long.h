typedef struct s_map
{
	int map_width;
	int map_height;
	int exit_loc[2];
	int player_loc[2];
	int coins;
	char **map_layout;
}
t_map;

#include "get_next_line.h"
#include <fcntl.h>
#include "minilibx/mlx.h"
#include <stdio.h>
void  map(t_map *map);
int ft_strlen(char *str);
int check_rectangle(t_map *map);