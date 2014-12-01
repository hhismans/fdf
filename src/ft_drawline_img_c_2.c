/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline_img_c_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 20:50:12 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/01 21:02:27 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf.h"
#include <unistd.h>
#include <math.h>

void	ft_drawline_img_c_1(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int dx;
	int dy;

	dx = p2.x - p1.x;
	if ((dy = p2.y - p1.y) != 0)
	{
		if (dy > 0)
		{
			if (dx > dy)
				case_horiz(img_ptr, p1, p2, c);
			else
				case_verti(img_ptr, p1, p2, c);
		}
		else
		{
			if (dx > -dy)
				case_horizneg(img_ptr, p1, p2, c);
			else
				case_vertineg(img_ptr, p1, p2, c);
		}
	}
}

void	ft_drawline_img_c_2(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int i_color;

	if (p1.x < p2.x)
	{
		i_color = (c.color_end - c.color_begin) / (p2.x - p1.x);
		while (p1.x != p2.x)
		{
			mlx_pixel_put_img(img_ptr, p1.x, p1.y, rainbow_gen(c.color_begin));
			p1.x++;
			c.color_begin += i_color;
		}
	}
	else
	{
		i_color = 0;
		if (p1.x - p2.x)
			i_color = (c.color_end - c.color_begin) / (p1.x - p2.x);
		while (p1.x != p2.x)
		{
			mlx_pixel_put_img(img_ptr, p1.x, p1.y, rainbow_gen(c.color_begin));
			p1.x--;
			c.color_begin += i_color;
		}
	}
}

void	ft_drawline_img_c_3(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int i_color;

	if (p1.y < p2.y)
	{
		if (p2.y - p1.y)
			i_color = (c.color_end - c.color_begin) / (p2.y - p1.y);
		while (p1.y != p2.y)
		{
			mlx_pixel_put_img(img_ptr, p1.x, p1.y, rainbow_gen(c.color_begin));
			p1.y++;
			c.color_begin += i_color;
		}
	}
	else
	{
		i_color = 0;
		if (p2.x - p1.x)
			i_color = (c.color_end - c.color_begin) / (p2.x - p1.x);
		while (p1.y != p2.y)
		{
			mlx_pixel_put_img(img_ptr, p1.x, p2.y, rainbow_gen(c.color_begin));
			p2.y++;
			c.color_begin -= i_color;
		}
	}
}
