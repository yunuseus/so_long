/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:50:10 by yalp              #+#    #+#             */
/*   Updated: 2024/11/09 13:49:10 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}

int	ft_strchr_gnl(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (c);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ret;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	ret = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!ret)
		return (NULL);
	while (s1[a])
	{
		ret[a] = s1[a];
		a ++;
	}
	while (s2[b])
	{
		ret[a + b] = s2[b];
		b ++;
	}
	ret[a + b] = '\0';
	return (free(s1), ret);
}
