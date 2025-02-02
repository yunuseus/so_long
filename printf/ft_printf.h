/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:49:58 by yalp              #+#    #+#             */
/*   Updated: 2025/02/02 13:59:00 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

int	ft_prntchar(int c);
int	ft_prntstr(char *str);
int	ft_prntnbr(int nb);
int	ft_prnthex(unsigned int n, char b);
int	ft_prntunbr(unsigned int nb);
int	ft_prntptr(unsigned long a, int c);
int	ft_printf(const char *format, ...);

#endif