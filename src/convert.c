/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:32:22 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/01 23:11:38 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void			conv_axono(t_env e, t_point *point, int i, int j)
{
	double omega;
	double alpha;
	int i2;
	int j2;	

	omega = e.omega * M_PI / 180;
	alpha = e.alpha * M_PI / 180;
	point->x = ((int)(cos(omega) * 100) * (j - 1));
	point->x -= (((int)(100 * sin(omega)) * i));
	point->x /= e.zoom;
	point->x += e.decal.x;
	point->y = (int)(100 * (sin(omega) * sin(alpha))) * (j - 1);
	point->y -= (int)(100 * (cos(omega) * sin (alpha))) * i;
	point->y += ((int)(100 * cos(alpha)) * -e.tab_int[i][j] * e.mult_z / 50);
	point->y /= e.zoom;
	point->y += e.decal.y;
}

void			conv_cavaliere(t_env e, t_point *point, int i, int j)
{
	double omega;
	double alpha;

	omega = e.omega * M_PI / 180;
	alpha = e.alpha * M_PI / 180;
	point->x = (20 * (j - 1)) + (cos(alpha) * 20 * e.tab_int[i][j]);
	point->y = (20 * i) + (sin(alpha) * 20 * e.tab_int[i][j]);
}

t_point			**convert_map(t_env e, void (*conv)(t_env, t_point *, int, int))
{
	int		size;
	int		i;
	int		j;
	t_point **point_cav;

	size = 0;
	while (e.tab_int[size])
		size++;
	i = 0;
	j = 0;
	point_cav = (t_point **)ft_taballoc(sizeof(t_point *) * (size + 1));
	while (e.tab_int[i])
	{
		point_cav[i] = (t_point *)ft_memalloc(sizeof(t_point) *
				e.tab_int[i][0] + 1);
		point_cav[i][0].x = e.tab_int[i][0];
		j = 1;
		while (j <= e.tab_int[i][0])
		{
			conv(e, &(point_cav[i][j]), i, j);
			j++;
		}
		i++;
	}
	return (point_cav);
}
