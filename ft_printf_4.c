/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:55:54 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/06 18:00:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(char *format, ...);
int	ft_putchar (char c);
int	ft_convert_arg(char c, va_list arg_lst);
int	ft_print_s(char *s);
int	ft_print_nb(long long nb, char *base, long long base_size);





