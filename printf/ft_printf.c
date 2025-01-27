/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:50:04 by yalp              #+#    #+#             */
/*   Updated: 2024/10/30 16:42:53 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prntchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_ctrl(char a)
{
	char	*b;
	int		i;

	b = "cspdiuxX%";
	i = 0;
	while (b[i] != '\0' )
	{
		if (a == b[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_prntsend(char b, va_list a)
{
	if (b == 'c')
		return (ft_prntchar(va_arg(a, int)));
	else if (b == 's')
		return (ft_prntstr(va_arg(a, char *)));
	else if (b == 'p')
		return (ft_prntptr(va_arg(a, unsigned long), 1));
	else if (b == 'd' || b == 'i')
		return (ft_prntnbr(va_arg(a, int)));
	else if (b == 'u')
		return (ft_prntunbr(va_arg(a, unsigned int)));
	else if (b == 'x' || b == 'X')
		return (ft_prnthex(va_arg(a, unsigned int), b));
	else if (b == '%')
		return (ft_prntchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(a, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_ctrl(format[i + 1]))
				j += ft_prntsend(format[i++ + 1], a);
			i++;
		}
		else
		{
			j += ft_prntchar(format[i]);
			i++;
		}
	}
	va_end(a);
	return (j);
}
