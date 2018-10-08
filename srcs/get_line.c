/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:53:26 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/01 21:05:56 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_line(int fd)
{
	char	*line;
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		lu;

	line = NULL;
	while ((lu = read(fd, buf, BUFF_SIZE)))
	{
		temp = line;
		buf[lu] = '\0';
		if (!(line = ft_sbtlejoin(line, buf)))
			return (NULL);
		if (temp)
			free(temp);
	}
	return (line);
}
