/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 16:51:05 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/01 18:14:04 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void			draw_grid(t_env e, t_point **tab, int **tab_int, int gamme)
{
	int		l;
	int		co;
	t_color c;

	l = -1;
	while (tab[++l])
	{
		co = 1;
		while (co <= tab[l][0].x)
		{
			if (co + 1 <= tab[l][0].x)
			{
				c.color_begin = 950 - (1 * gamme * tab_int[l][co]);
				c.color_end = 950 - (1 * gamme * tab_int[l][co + 1]);
				ft_drawline_img_c(e.img, tab[l][co], tab[l][co + 1], c);
			}
			if (tab[l + 1] && co <= tab[l + 1][0].x)
			{
				c.color_begin = 950 - (1 * gamme * tab_int[l][co]);
				c.color_end = 950 - (1 * gamme * tab_int[l + 1][co]);
				ft_drawline_img_c(e.img, tab[l][co], tab[l + 1][co], c);
			}
			co++;
		}
	}
}
