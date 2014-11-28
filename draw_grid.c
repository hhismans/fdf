/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 16:51:05 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/28 10:18:10 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	draw_grid(t_env e, t_point **tab, int **tab_int, int gamme)
{
	int line;
	int column;
	t_color c;
	line = 0;
	column = 1;

	while (tab[line])
	{
		column = 1;
		while (column <= tab[line][0].x)
		{
			if (column + 1 <= tab[line][0].x)	//si le point de droite existe
			{
				c.color_begin = 950 - (1 * gamme * tab_int[line][column]);
				c.color_end = 950 - (1 * gamme * tab_int[line][column + 1]);
				ft_drawline_img_c(e.img, tab[line][column], tab[line][column + 1], c);
			}
			if (tab[line + 1] && column <= tab[line + 1][0].x) // si le point d'en dessous existe
			{
				c.color_begin = 950 - (1 * gamme * tab_int[line][column]);
				c.color_end = 950 - (1 * gamme * tab_int[line + 1][column]);
				ft_drawline_img_c(e.img, tab[line][column], tab[line + 1][column], c);
			}
			column++;
		}
		line++;
	}
}
