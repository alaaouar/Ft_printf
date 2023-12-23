/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:17:58 by alaaouar          #+#    #+#             */
/*   Updated: 2023/12/16 15:17:09 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_workshop(va_list q, char c, int *i)
{
	int	var;

	var = 0;
	if (c == 'c')
		var += ft_putchar(va_arg(q, int));
	else if (c == 's')
		var += ft_putstr(va_arg(q, char *));
	else if (c == 'X')
		var += ft_putnbr_base(va_arg(q, unsigned int), HEX_UPPER);
	else if (c == 'x')
		var += ft_putnbr_base(va_arg(q, unsigned int), HEX_LOWER);
	else if (c == 'p')
		var += ft_putstr("0x") + ft_putnbr_base(va_arg(q, unsigned long),
				HEX_LOWER);
	else if (c == 'u')
		var += ft_putnbr(va_arg(q, unsigned int));
	else if (c == 'd' || c == 'i')
		var += ft_putnbr(va_arg(q, int));
	else if (c == '%')
		var += ft_putchar('%');
	else
		(*i)--;
	return (var);
}

int	ft_printf(const char *x, ...)
{
	va_list	z;
	int		nb;
	int		y;

	va_start(z, x);
	y = -1;
	nb = 0;
	while (x[++y])
	{
		if (x[y] == '%')
		{
			y++;
			if (!x[y])
				return (nb);
			nb += ft_workshop(z, x[y], &y);
		}
		else
			nb += ft_putchar(x[y]);
	}
	va_end(z);
	return (nb);
}
