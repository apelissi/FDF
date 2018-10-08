/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:28:02 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/08 14:58:54 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_val	*init_tv(void)
{
	t_val	*tv;

	if (!(tv = (t_val *)malloc(sizeof(t_val))))
		return (NULL);
	tv->tab = NULL;
	tv->nb_x = 0;
	tv->nb_y = 0;
	tv->nb_z = 0;
	tv->x_max = 0;
	tv->y_max = 0;
	tv->m_x = 0;
	tv->m_y = 0;
	return (tv);
}

int		main(int ac, char **av)
{
	int			fd;
	char		*line;
	t_val		*tv;

	write(1, "A\n", 2);
	if (ac != 2)
		return (0);
	write(1, "B\n", 2);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !(line = get_line(fd)))
		return (0);
	write(1, "C\n", 2);
	if (!(tv = init_tv()))
		return (0);
	write(1, "D", 1);
	if (!(get_tab_dim(line, tv)))
		return (0);
	write(1, "E\n", 2);
	if (!(get_tab(line, tv)))
		return (0);
	write(1, "F\n", 2);
	ft_mlx(tv);
	write(1, "G\n", 2);
	return (0);
}
