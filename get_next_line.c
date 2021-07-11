/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel- <ldaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:04:43 by ldaniel-          #+#    #+#             */
/*   Updated: 2021/07/10 18:55:27 by ldaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	return_line(int n, char **keeper, char **line)
{
	char	*tmp;

	if (n < 0)
	{
		free(*keeper);
		return (ERROR);
	}
	*line = ft_substr(*keeper, 0, ft_strclen(*keeper, '\n'));
	if (!line)
		return (ERROR);
	if (ft_strchr(*keeper, '\n'))
	{
		tmp = ft_strdup(ft_strchr(*keeper, '\n') + 1);
		free(*keeper);
		*keeper = tmp;
		return (L_READ);
	}
	free(*keeper);
	*keeper = NULL;
	return (END_OF_FILE);
}

int	get_next_line(int fd, char **line)
{
	static char	*keeper;
	char		*buffer;
	int			rdnumber;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (ERROR);
	if (!keeper)
		keeper = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ERROR);
	rdnumber = read(fd, buffer, BUFFER_SIZE);
	while (rdnumber > 0)
	{
		buffer[rdnumber] = '\0';
		keeper = ft_strjoin(keeper, buffer);
		if (ft_strchr(keeper, '\n'))
			break ;
		rdnumber = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (return_line(rdnumber, &keeper, line));
}
