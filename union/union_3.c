/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:02:35 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/05 17:07:36 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char	tab[256];
	int		i;
	char	c;

	if (ac == 3)
	{
		i = -1;
		while (++i < 256)
			tab[i] = 0;
		i = -1;
		while(av[1][++i])
		{
			c = av[1][i];
			if (tab[(unsigned char)c] == 0)
			{
				write(1, &c, 1);
				tab[(unsigned char)c] = 1;
			}
		}
		i = -1;
		while(av[2][++i])
		{
			c = av[2][i];
			if (tab[(unsigned char)c] == 0)
			{
				write(1, &c, 1);
				tab[(unsigned char)c] = 1;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
