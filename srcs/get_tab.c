/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:41:41 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/08 15:11:29 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_number(char c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	return (0);
}

int		**init_tab(int nb_x, int nb_y)
{
	int	i;
	int	**tab;

	if (!(tab = (int **)malloc((nb_y + 1) * sizeof(int *))))
		return (NULL);
	i = 0;
	while (i <= nb_y)
	{
		if (!(tab[i] = (int *)malloc(nb_x * sizeof(int))))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int		init(int *x, int *y, int *i, t_val *tv)
{
	*x = 0;
	*y = tv->nb_y - 1;
	*i = 0;
	if (!(tv->tab = init_tab(tv->nb_x, tv->nb_y)))
		return (0);
	return (1);
}

int		get_tab(char *str, t_val *tv)
{
	int		x;
	int		y;
	int		i;

	if (!(init(&x, &y, &i, tv)))
		return (0);
	while (str[i] && y >= 0)
	{
		if (str[i] && is_number(str[i]))
		{
			if ((tv->tab[y][x] = ft_atoi(&str[i])) < tv->z_min)
				tv->z_min = tv->tab[y][x];
			x++;
		}
		while (str[i] && is_number(str[i]))
			i++;
		if (str[i] && str[i] == '\n')
		{
			y--;
			x = 0;
		}
		i++;
	}
	free(str);
	return (1);
}
