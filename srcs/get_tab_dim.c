/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab_dim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:31:14 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/08 14:59:19 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			is_ok(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '+' || c == '-')
		return (2);
	if (c == ' ')
		return (3);
	if (c == '\n')
		return (9);
	return (0);
}

int			get_tab_dim(char *line, t_val *tv)
{
	int			i;
	int			j;
	int			x_max;

	x_max = 0;
	i = 0;
	while (line[i] && (j = is_ok(line[i])))
	{
		if (j == 2 && i != 0 && is_ok(line[i - 1]) % 3 != 0)
			return (0);
		if (j == 9)
		{
			if (x_max != tv->nb_x && tv->nb_y)
				return (0);
			tv->nb_y++;
			tv->nb_x = x_max;
			x_max = 0;
		}
		if ((j == 1 || j == 2) && (i == 0 || is_ok(line[i - 1]) % 3 == 0))
			x_max++;
		i++;
	}
	if (!j)
		return (0);
	ft_putnbr(tv->nb_y);
	write(1, "  ", 2);
	ft_putnbr(tv->nb_x);
	write(1, "\n", 1);
	return (1);
}
