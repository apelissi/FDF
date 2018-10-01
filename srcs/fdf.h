/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:43:03 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/01 21:03:14 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FDF_H
#	define FDF_H

#include "mlx.h"
#include "../libft/libft.h"
#include "keyboard.h"
#define ACC 2000
#define BUFF_SIZE 2048

typedef struct		s_val
{
	int		**tab;
	int		nb_x;
	int		nb_y;
	int		nb_z;
	int		t_x;
	int		t_y;
	float	z_min;
	float	x_max;
	float	y_max;
	float	f;
	float	h;
	float	m_x;
	float	m_y;
	void	*ptr;
	void	*fen;
}					t_val;

typedef struct		s_point
{
	float		x;
	float		y;
	float		z;
}					t_point;

char				*get_line(int fd);
int					get_tab_dim(char *line, t_val *tv);
void				afficher(t_val *tv);
int					get_tab(char *str, t_val *tv);
int					fil(t_point p_a, t_point p_b, t_val *tv);
void				ft_link(t_point a, t_point b, t_val *tv);
int					ft_mlx(t_val *tv);
int					deal_key(int keycode, t_val *tv);

#	endif
