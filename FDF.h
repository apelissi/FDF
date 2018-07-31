/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:29:34 by apelissi          #+#    #+#             */
/*   Updated: 2018/07/31 16:57:24 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef	FDF_H
#	define	FDF_H

#include "mlx.h"
#include "stdlib.h"
#include "unistd.h"
#define ACC 1000

int fil(float x, float y, float a, float b);
int	**get_tab(int fd);
int	get_next_line(const int fd, char **line);

#endif
