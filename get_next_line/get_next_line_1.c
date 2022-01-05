/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:54:43 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/05 14:29:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*get_line(char *line, char *buff, int fd);
int		ft_strlen(char *s);
int		ft_position_nl(char *s);
char	*ft_strjoin(char *line, char *buff);

char	*get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1] = {};
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line [0] = 0;
	line = get_line(line, buff, fd);
	if (line && ft_strlen(line))
		return (line);
	free(line);
	return (NULL);
}

char	*get_line(char *line, char *buff, int fd)
{
	int	read_ret;
	char *buff_rest;

	read_ret = 1;
	while(read_ret > 0)
	{
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
		if (ft_position_nl(buff) != -1)
		{
			buff_rest = &buff[ft_position_nl(buff) + 1];
			while (*buff_rest)
				*buff++ = *buff_rest++;
			*buff = '\0';
			return (line);
		}
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free (line);
			return (NULL);
		}
		buff[read_ret] = '\0';
	}
	return (line);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		ft_position_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (-1);
}

char	*ft_strjoin(char *line, char *buff)
{
	char *joined;
	int buff_size;
	int	i_l;
	int	i_b;

	if (ft_position_nl(buff) != -1)
		buff_size = ft_position_nl(buff) + 1;
	else
		buff_size = ft_strlen(buff);
	joined = malloc(sizeof(char) * (ft_strlen(line) + buff_size + 1));
	if (!joined)
		return (NULL);
	i_l = -1;
	while (line[++i_l])
		joined[i_l] = line[i_l];
	free(line);
	i_b = -1;
	while (buff[++i_b])
	{
		joined[i_l++] = buff[i_b];
		if (buff[i_b] == '\n')
			break;
	}
	joined[i_l] = '\0';
	return (joined);
}
