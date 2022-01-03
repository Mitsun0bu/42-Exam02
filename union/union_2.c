/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <llethuil@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:16:42 by lucas             #+#    #+#             */
/*   Updated: 2022/01/02 14:24:22 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char	tab[256];
	char	c;
	int		i;

	if (argc == 3)
	{
		i = -1;
		while (++i < 256)
			tab[i] = 0;
		i = -1;
		while (argv[1][++i])
		{
			c = argv[1][i];
			if (tab[(unsigned char)c] == 0)
			{
				write(1, &c, 1);
				tab[(unsigned char)c] = 1;
			}
		}
		i = -1;
		while (argv[2][++i])
		{
			c = argv[2][i];
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

