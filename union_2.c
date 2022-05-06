/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:28:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/06 15:40:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i = 0;
	char	c = 0;
	int		tab[256];

	if (ac == 3)
	{
		i = -1;
		while (++i < 256)
			tab[i] = 0;
		i = -1;
		while (av[1][++i])
		{
			c = av[1][i];
			if (tab[(unsigned char)c] == 0)
			{
				write(1, &c, 1);
				tab[(unsigned char)c] = 1;
			}
		}
		i = -1;
		while (av[2][++i])
		{
			c = av[2][i];
			if (tab[(unsigned char)c] == 0)
			{
				write(1, &c, 1);
				tab[(unsigned char)c] = 1;
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}
