/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:34:14 by lduthill          #+#    #+#             */
/*   Updated: 2023/03/17 15:12:56 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(unsigned char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n, int i);
int		ft_convert(unsigned int n, char *base, int i);
int		ft_convert_ptr(void *ptr, char *base, int i);
int		ft_define(char s1, va_list ap);
int		ft_printf(const char *s1, ...);
size_t	ft_strlen(const char *str);

#endif
