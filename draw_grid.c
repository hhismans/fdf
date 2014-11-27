/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 16:51:05 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/27 17:10:00 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	draw_grid(t_env e, t_point **tab, int color)
{
	int line;
	int column;

	line = 0;
	column = 1;

	while (tab[line])
	{
		column = 1;
		while (column <= tab[line][0].x)
		{
			if (column + 1 <= tab[line][0].x) //si le point de droite existe
				ft_drawline_img(e.img, tab[line][column], tab[line][column + 1], color);
			if (tab[line + 1] && column <= tab[line + 1][0].x) // si le point d'en dessous existe
				ft_drawline_img(e.img, tab[line][column], tab[line + 1][column], color);
			column++;
		}
		line++;
	}

}
