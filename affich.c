/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affich.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:08:34 by apelissi          #+#    #+#             */
/*   Updated: 2018/07/31 17:00:31 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "FDF.h"

int	fil(float x, float y, float a, float b)
{
	void	*mlx_ptr;
	void	*mlx_fen;
	float	i;

	mlx_ptr = mlx_init();
	mlx_fen = mlx_new_window(mlx_ptr, 1200, 1200, "FDF");
	i = 0;
	while (i < ACC)
	{
		mlx_pixel_put(mlx_ptr, mlx_fen, (x + (a - x) * (i / ACC)),
	((x + (a - x) * (i / ACC)) * (y - b) / (x - a) + (b * x - y * a) / (x - a)),
	255 + 255 * 256 + 255 * 256 * 256);
		i++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
