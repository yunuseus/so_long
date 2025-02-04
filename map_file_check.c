/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:24 by yalp              #+#    #+#             */
/*   Updated: 2025/02/04 14:34:27 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>
#include "printf/ft_printf.h"

void	map_file_check(char *mapfile)
{
	int		fd;
	char	*check_null;

	fd = open(mapfile, O_RDONLY);
	check_null = get_next_line(fd);
	if (check_null == NULL)
	{
		free(check_null);
		ft_printf("ERROR\nEMPTY MAP FİLE");
		exit(1);
	}
}
