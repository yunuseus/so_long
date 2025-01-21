/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:50:15 by yalp              #+#    #+#             */
/*   Updated: 2024/11/09 13:47:03 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *dst)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!*dst)
		return (NULL);
	while (dst[i] && dst[i] != '\n')
		i++;
	if (dst[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (dst[++i] && dst[i] != '\n')
		ret[i] = dst[i];
	if (dst[i] == '\n')
	{
		ret[i] = '\n';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_get_left_line(char *buff)
{
	char	*ret;
	size_t	i;
	size_t	j;	

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
		return (free(buff), NULL);
	if (buff[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (ft_strlen_gnl(buff) - i + 1));
	if (!ret)
		return (free(buff), NULL);
	j = 0;
	while (buff[i])
		ret[j++] = buff[i++];
	ret[j] = '\0';
	free(buff);
	return (ret);
}

char	*ft_read_line(char *dst, int fd)
{
	char	*buff;
	int		reads;

	reads = 1;
	if (!dst)
	{
		dst = malloc(sizeof(char) * 1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
	}
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr_gnl(dst, '\n') && reads != 0)
	{
		reads = read(fd, buff, BUFFER_SIZE);
		if (reads == -1)
			return (free(dst), free(buff), NULL);
		buff[reads] = '\0';
		dst = ft_strjoin_gnl(dst, buff);
	}
	free(buff);
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read_line(buff, fd);
	if (!buff)
		return (NULL);
	ret = ft_get_line(buff);
	buff = ft_get_left_line(buff);
	return (ret);
}
