/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:32:38 by yalp              #+#    #+#             */
/*   Updated: 2024/10/30 14:50:14 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prntnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (ft_prntstr("-2147483648"));
	if (nb < 0)
	{
		nb = -nb;
		i += ft_prntchar('-');
	}
	if (nb > 9)
	{
		i += ft_prntnbr(nb / 10);
		i += ft_prntchar((nb % 10) + 48);
	}
	else
		i += ft_prntchar(nb + 48);
	return (i);
}

int	ft_prnthex(unsigned int n, char b)
{
	int		i;

	i = 0;
	if (n >= 16)
	{
		i += ft_prnthex(n / 16, b);
	}
	if (b == 'x')
		i += ft_prntchar("0123456789abcdef"[n % 16]);
	else if (b == 'X')
		i += ft_prntchar("0123456789ABCDEF"[n % 16]);
	return (i);
}

int	ft_prntstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_prntstr("(null)"));
	while (str[i] != '\0')
	{
		ft_prntchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_prntptr(unsigned long a, int c)
{
	int				i;

	i = 0;
	if (c == 1)
		i += ft_prntstr("0x");
	if (a >= 16)
		i += ft_prntptr(a / 16, 0);
	i += ft_prntchar("0123456789abcdef"[a % 16]);
	return (i);
}

int	ft_prntunbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_prntunbr(nb / 10);
		i += ft_prntunbr(nb % 10);
	}
	else
		i += ft_prntchar(nb + 48);
	return (i);
}
