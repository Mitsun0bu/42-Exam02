/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <llethuil@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 00:30:01 by lucas             #+#    #+#             */
/*   Updated: 2022/01/04 01:19:10 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int		ft_printf(char *format, ...);
void	ft_putchar(char c);
void	ft_convert_arg(char c, va_list args_lst);
void	ft_print_s(char *s);
void	ft_print_nb(long long nb, char *base, long long base_size);
int		ft_arg_len(char c, va_list args_copy);
int		ft_strlen(char *s);
int		ft_nb_len(long long nb, long long base_size);

int		ft_printf(char *format, ...)
{
	int		len;
	va_list args_lst;
	va_list args_copy;

	len = 0;
	va_start(args_lst, format);
	va_copy(args_copy, args_lst);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			len ++;
		}
		else
		{
			ft_convert_arg(*(format + 1), args_lst);
			len += ft_arg_len(*(format + 1), args_copy);
			format ++;
		}
		format ++;
	}
	va_end(args_lst);
	return (len);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_convert_arg(char c, va_list args_lst)
{
	if (c == 's')
		ft_print_s(va_arg(args_lst, char *));
	else if (c == 'd')
		ft_print_nb(va_arg(args_lst, int), "0123456789", 10);
	else if (c == 'x')
		ft_print_nb(va_arg(args_lst, unsigned int), "0123456789abcdef", 16);
	return ;
}

void	ft_print_s(char *s)
{
	int	i;

	if(!s)
	{
		write (1, "(null)", 6);
		return ;
	}
	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
	return ;
}

void	ft_print_nb(long long nb, char *base, long long base_size)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base_size)
		ft_print_nb((nb / base_size), base, base_size); // SI MARCHE PAS METTRE UN WHILE
	ft_putchar(base[nb % base_size]);
	return ;
}

int		ft_arg_len(char c, va_list args_copy)
{
	if(c == 's')
		return (ft_strlen(va_arg(args_copy, char *)));
	else if (c == 'd')
		return (ft_nb_len(va_arg(args_copy, int), 10));
	else if (c == 'x')
		return (ft_nb_len(va_arg(args_copy, unsigned int), 16));
	return (1);
}

int		ft_strlen(char *s)
{
	int i;

	if (!s)
		return (6);
	i = 0;
	while (s[i])
		i ++;
	return (i);
}

int		ft_nb_len(long long nb, long long base_size)
{
	int len;

	len = 0;
	if (nb < 0)
	{
		len ++;
		nb = -nb;
	}
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb = nb / base_size;
		len ++;
	}
	return (len);
}

