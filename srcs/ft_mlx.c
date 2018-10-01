/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:05:01 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/01 20:57:05 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_val *tv)
{
	tv->t_x = 1800;
	tv->t_y = 1200;
	tv->h = tv->nb_y * 10;
	tv->f = tv->h / 4;
}

int		ft_mlx(t_val *tv)
{
	tv->ptr = mlx_init();
	ft_init(tv);
	tv->fen = mlx_new_window(tv->ptr, tv->t_y,
			tv->t_x, "fdf");
	afficher(tv);
	mlx_key_hook(tv->fen, deal_key, tv);
	mlx_loop(tv->ptr);
	return (0);
}
