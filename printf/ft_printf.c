/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:32:55 by lduthill          #+#    #+#             */
/*   Updated: 2023/03/17 12:33:05 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s1, ...)
{
	int			i;
	int			j;
	va_list		ap;

	va_start(ap, s1);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '%')
		{
			j += ft_define(s1[i + 1], ap);
			i++;
		}
		else
		{
			ft_putchar(s1[i]);
			j++;
		}
		i++;
	}
	va_end(ap);
	return (j);
}
