/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 13:29:38 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/01 20:59:44 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf.h"
#include <unistd.h>
#include <math.h>

void		case_horiz(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int dx;
	int dy;
	int e;
	int i_color;

	i_color = 0;
	if (p2.x - p1.x)
		i_color = (c.color_end - c.color_begin) / (p2.x - p1.x);
	dy = (p2.y - p1.y) * 2;
	e = p2.x - p1.x;
	dx = 2 * e;
	while (p1.x <= p2.x)
	{
		mlx_pixel_put_img(img_ptr, p1.x, p1.y, rainbow_gen(c.color_begin));
		e = e - dy;
		if (e <= 0)
		{
			p1.y++;
			e = e + dx;
		}
		c.color_begin += i_color;
		p1.x++;
	}
}

void		case_horizneg(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int dx;
	int dy;
	int e;
	int i_color;

	i_color = 0;
	if (p2.x - p1.x)
		i_color = (c.color_end - c.color_begin) / (p2.x - p1.x);
	dy = (p1.y - p2.y) * 2;
	e = p2.x - p1.x;
	dx = 2 * e;
	while (p1.x <= p2.x)
	{
		mlx_pixel_put_img(img_ptr, p1.x, p1.y, rainbow_gen(c.color_begin));
		e = e - dy;
		if (e <= 0)
		{
			p1.y--;
			e = e + dx;
		}
		c.color_begin += i_color;
		p1.x++;
	}
}

void		case_verti(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int dx;
	int dy;
	int e;
	int i_color;

	i_color = 0;
	if (p2.y - p1.y)
		i_color = (c.color_end - c.color_begin) / (p2.y - p1.y);
	dx = (p2.x - p1.x) * 2;
	e = p2.y - p1.y;
	dy = 2 * e;
	while (p1.y <= p2.y)
	{
		mlx_pixel_put_img(img_ptr, p1.x, p1.y, rainbow_gen(c.color_begin));
		e = e - dx;
		if (e <= 0)
		{
			p1.x++;
			e = e + dy;
		}
		c.color_begin += i_color;
		p1.y++;
	}
}

void		case_vertineg(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int dx;
	int dy;
	int e;
	int i_color;

	i_color = 0;
	if (p1.y - p2.y)
		i_color = (c.color_end - c.color_begin) / (p1.y - p2.y);
	e = p2.y - p1.y;
	dx = (p1.x - p2.x) * 2;
	dy = 2 * e;
	while (p1.y >= p2.y)
	{
		mlx_pixel_put_img(img_ptr, p1.x, p1.y, rainbow_gen(c.color_begin));
		e = e + dx;
		if (e <= 0)
		{
			p1.x++;
			e = e - dy;
		}
		c.color_begin += i_color;
		p1.y--;
	}
}

void		ft_drawline_img_c(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int dx;
	int dy;
	int i_color;

	if ((dx = p2.x - p1.x) != 0)
	{
		if (dx > 0)
		{
			if ((dy = p2.y - p1.y) != 0)
				ft_drawline_img_c_1(img_ptr, p1, p2, c);
			else
				ft_drawline_img_c_2(img_ptr, p1, p2, c);
		}
		else
		{
			dx = c.color_begin;
			c.color_begin = c.color_end;
			c.color_end = dx;
			ft_drawline_img_c(img_ptr, p2, p1, c);
		}
	}
	else
	{
		ft_drawline_img_c_3(img_ptr, p1, p2, c);
	}
}
