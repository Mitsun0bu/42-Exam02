/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:56:21 by lucas             #+#    #+#             */
/*   Updated: 2022/01/05 12:19:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(char *format, ...);
int	ft_convert_arg(char c, va_list args_lst);
int ft_putchar(char c);
int	ft_print_s(char *s);
int	ft_print_nb(long long nb, char *base, long long base_size);

int		ft_printf(char *format, ...)
{
	int		len;
	va_list	args_lst;

	va_start(args_lst, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar(*format);
		else if (*format == '%')
		{
			len += ft_convert_arg(*(format + 1), args_lst);
			format ++;
		}
		format ++;
	}
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_convert_arg(char c, va_list args_lst)
{
	if (c == 's')
		return(ft_print_s(va_arg(args_lst, char *)));
	else if (c == 'd')
		return (ft_print_nb(va_arg(args_lst, int), "0123456789", 10));
	else if (c == 'x')
		return(ft_print_nb(va_arg(args_lst, unsigned int), "0123456789abcdef", 16));
	else
		return (0);
}

int		ft_print_s(char *s)
{
	int	i = -1;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while(s[++i])
		ft_putchar(s[i]);
	return (i);
}

int	ft_print_nb(long long nb, char *base, long long base_size)
{
	int			len = 0;
	long long	nbr = nb;

	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
		nbr = -nbr;
	}
	if (nbr == 0)
		len = 1;
	while (nbr > 0)
	{
		nbr = nbr / base_size;
		len ++;
	}
	if (nb >= base_size)
		ft_print_nb((nb / base_size), base, base_size);
	ft_putchar(base[nb % base_size]);
	return (len);
}
