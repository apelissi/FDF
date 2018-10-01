/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabaff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:06:31 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/06 15:58:10 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtabaff(char **tab)
{
	size_t	t;

	t = 0;
	while (tab[t])
	{
		ft_putstr(tab[t]);
		if (tab[t + 1])
			write(1, "\n\n\n", 3);
		t++;
	}
}