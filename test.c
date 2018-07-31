/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:22:59 by apelissi          #+#    #+#             */
/*   Updated: 2018/07/31 11:42:32 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main()
{
	void *mlx_ptr;
	void *mlx_fen;
	int x;
	int y;
	int nb_l;
	int nb_c;

	mlx_ptr = mlx_init();
	mlx_fen = mlx_new_window(mlx_ptr, 1200, 1200, "bobby");
	nb_l = 10;
	y = 0;
	while (y <= nb_l )
	{
		x = 0;
		while (x + 550 < 1600 && x + 600 < 1200)
		{
			mlx_pixel_put (mlx_ptr, mlx_fen, 550 + x - y * (500 / nb_l), 50 + x + y * (500 / nb_l), 255 * 1 + 255 * 256 + 255 * 256 * 256 );
			x++;
		}
		y++;
	}
	nb_c = 10;
	y = 0;
	while (y <= nb_l )
	{
		x = 0;
		while (x < 450)
		{
		//	mlx_pixel_put (mlx_ptr, mlx_fen, x + 50 + y * (500 /nb_c),  50 - x + y * (500 /nb_c) , 255 * 1 + 255 * 256 + 255 * 256 * 256 );
			x++;
		}
		y ++;
	}

	mlx_loop(mlx_ptr);
	return(0);
}
