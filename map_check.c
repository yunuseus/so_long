#include "so_long.h"

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
		map->map_width = map_len(map);
}
