/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:50:17 by yalp              #+#    #+#             */
/*   Updated: 2024/12/31 13:51:46 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen_gnl(char *str);
int		ft_strchr_gnl(char *str, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_get_line(char *dst);
char	*ft_get_left_line(char *buff);
char	*ft_read_line(char *dst, int fd);
char	*get_next_line(int fd);

#endif