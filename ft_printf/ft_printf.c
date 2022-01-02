/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:16:02 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/30 18:27:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# include <stdarg.h>
# include <unistd.h>
int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_convert_arg(char c, va_list arg_ptr);
void	ft_print_s(char *s);
void	ft_print_d(long long nb, char *base, long long base_size);
void	ft_print_x(unsigned long long nb, char *base, unsigned long long base_size);
int		ft_arg_len(char c, va_list copy);
int		ft_strlen(char *s);
int		ft_len_signed(long long nb);
int		ft_len_unsigned(unsigned long long nb);

int		ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	va_list	copy;
	int		len = 0;

	va_start(arg_ptr, format);
	va_copy(copy, arg_ptr);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			len ++;
		}
		else
		{
			ft_convert_arg(*(format + 1), arg_ptr);
			len += ft_arg_len(*(format + 1), copy);
			format ++;
		}
		format ++;
	}
	va_end(arg_ptr);
	return (len);
}

void	ft_putchar(char c)
{	
	write (1, &c, 1);
}

void	ft_convert_arg(char c, va_list arg_ptr)
{
	if (c == 's')
		ft_print_s(va_arg(arg_ptr, char *));
	else if (c == 'd')
		ft_print_d(va_arg(arg_ptr, int), "0123456789", 10);
	else if (c == 'x')
		ft_print_x(va_arg(arg_ptr, unsigned int), "0123456789abcdef", 16);
}

void	ft_print_s(char *s)
{
	int	i;

	i = 0;
	if (!s)
		write(1, "(null)", 6);
	else
	{
		while (s[i])
			i ++;
		write (1, s, i);
	}
}

void	ft_print_d(long long nb, char *base, long long base_size)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base_size)
	{
		ft_print_d((nb / base_size), base, base_size);
		ft_print_d((nb % base_size), base, base_size);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_print_x(unsigned long long nb, char *base, unsigned long long base_size)
{
	if (nb >= base_size)
	{
		ft_print_x((nb / base_size), base, base_size);
		ft_print_x((nb % base_size), base, base_size);
	}
	else
		ft_putchar(base[nb]);
}

int		ft_arg_len(char c, va_list copy)
{
	char	*s;

	if (c == 's')
	{
		s = va_arg(copy, char *);
		if (!s)
			return (6);
		else
			return (ft_strlen(s));
	}
	else if (c == 'd')
		return (ft_len_signed(va_arg(copy, int)));
	else if (c == 'x')
		return (ft_len_unsigned(va_arg(copy, unsigned int)));
	return (1);
}

int		ft_strlen(char *s)
{
	int	i = 0;
	
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_len_signed(long long nb)
{
	int	len = 0;

	if (nb < 0)
	{
		nb = -nb;
		len ++;
	}
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		len ++;
	}
	return (len);
}

int		ft_len_unsigned(unsigned long long nb)
{
	int	len = 0;

	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb = nb / 16;
		len ++;
	}
	return (len);
}