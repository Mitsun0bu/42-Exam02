/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:52:58 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/23 11:22:07 by llethuil         ###   ########.fr       */
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
	i = 0;
	while (i < 256)
		tab[i ++] = 0;

	// Read and write 1st word char by char.
	// Once a char is written, corresponding cell tab is set to '1'.
	i = 0;
	while (av[1][i])
	{
		c = av[1][i];
		if (tab[(unsigned char)c] == 0)
		{
			write(1, &av[1][i], 1);
			t[(unsigned char)c] = 1;
		}
		i ++;
	}

	// Read 2nd word char by char.
	// If corresponding cell tab is '0', char is written and cell is set to  '1'.
	i = 0;
	while (av[2][i])
	{
		c = av[2][i];
		if (tab[(unsigned char)c] == 0)
		{
			write(1, &av[2][i], 1);
			t[(unsigned char)c] = 1;
		}
		i ++;
	}
	return (0);
}
