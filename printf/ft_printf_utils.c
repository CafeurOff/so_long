/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:33:17 by lduthill          #+#    #+#             */
/*   Updated: 2023/03/17 12:33:28 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(unsigned int n, char *base, int i)
{
	if (n >= ft_strlen(base))
	{
		i = ft_convert(n / ft_strlen(base), base, i + 1);
		ft_convert(n % ft_strlen(base), base, i);
	}
	if (n < ft_strlen(base))
	{
		ft_putchar(base[n]);
		i++;
	}
	return (i);
}

int	ft_convertptr(size_t n, char *base, int i)
{
	if (i == 0)
		i = ft_putstr("0x");
	if (n >= ft_strlen(base))
	{
		i = ft_convertptr(n / ft_strlen(base), base, i + 1);
		ft_convertptr(n % ft_strlen(base), base, i);
	}
	if (n < ft_strlen(base))
	{
		ft_putchar(base[n]);
		i++;
	}
	return (i);
}

int	ft_define(char s1, va_list ap)
{
	size_t	i;

	if (s1 == 'c')
		i = (ft_putchar((char)va_arg(ap, int)));
	if (s1 == 's')
		i = (ft_putstr(va_arg(ap, char *)));
	if (s1 == 'p')
	{
		i = va_arg(ap, size_t);
		if (i == 0)
			i = ft_putstr("(nil)");
		else
			i = (ft_convertptr(i, "0123456789abcdef", 0));
	}
	if (s1 == 'd' || s1 == 'i')
		i = (ft_putnbr(va_arg(ap, int), 0));
	if (s1 == 'u')
		i = (ft_convert(va_arg(ap, unsigned int), "0123456789", 0));
	if (s1 == 'x')
		i = (ft_convert(va_arg(ap, unsigned int), "0123456789abcdef", 0));
	if (s1 == 'X')
		i = (ft_convert(va_arg(ap, unsigned int), "0123456789ABCDEF", 0));
	if (s1 == '%')
		i = (ft_putchar('%'));
	return (i);
}
