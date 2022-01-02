/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:17:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/01 22:32:32 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char	tab[256];
	int		i;
	char	c;

	if (ac != 3)
		return (0);

	// Init all tab cells to '0'.
	i = -1;
	while (i < 256)
		tab[++i] = 0;

	// Read the 2nd word char by char.
	// Once a char is read, c takes its value.
	// If tab[c] = '0', set tab[c] to '1'.
	i = -1;
	while (av[2][++i])
	{
		c = av[2][i];
		if (tab[(unsigned char)c] == 0)
			tab[(unsigned char)c] = 1;
	}

	// Read the 1st word char by char.
	// Once a char is read, c takes its value.
	// If tab[c] = 1, c is written and tab[c] is set to '0'.
	i = -1;
	while (av[1][++i])
	{
		c = av[1][i];
		if (tab[(unsigned char)c] == 1)
		{
			write(1, &c, 1);
			tab[(unsigned char)c] = 0;
		}
	}
	return (0);
}
