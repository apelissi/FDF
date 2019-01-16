/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:59:03 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/10 11:52:47 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_expose_hook(t_val *tv)
{
	int	i;

	i = 42;
	tv->img = mlx_new_image(tv->ptr, tv->t_x, tv->t_y);
	tv->data = (int *)mlx_get_data_addr(tv->img, &i, &i, &i);
	afficher(tv);
	mlx_put_image_to_window(tv->ptr, tv->fen, tv->img, 0, 0);
	mlx_destroy_image(tv->ptr, tv->img);
	return (i);
}
