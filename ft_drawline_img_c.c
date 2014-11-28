/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 13:29:38 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/28 11:08:50 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf.h"
#include <unistd.h>
#include <math.h>

static void	case_horiz(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int xi;
	int yi;
	int dx;
	int dy;
	int e;
	int coef;
	int e_corect;
	int i_color;

	i_color = 0;
	if (p2.x - p1.x)
		i_color = (c.color_end - c.color_begin) / (p2.x - p1.x);
	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	yi = p1.y;
	xi = p1.x;
	e = dx;
	coef = dy  * 2;
	e_corect = -1 * dx * 2;
	while (xi <= p2.x)
	{
		mlx_pixel_put_img(img_ptr, xi, yi, rainbow_gen(c.color_begin));
		e = e + coef;
		if (e >= 0)
		{
			yi++;
			e = e + e_corect;
		}
		c.color_begin += i_color;
		xi++;
	}
}

static void	case_horizneg(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int xi;
	int yi;
	int dx;
	int dy;
	int e;
	int coef;
	int e_corect;
	int i_color;

	i_color = 0;
	if (p2.x - p1.x)
		i_color = (c.color_end - c.color_begin) / (p2.x - p1.x);
	dy = p1.y - p2.y;
	dx = p2.x - p1.x;
	yi = p1.y;
	xi = p1.x;
	e = dx;
	coef = dy * 2;
	e_corect = -1 * dx * 2;
	while (xi <= p2.x)
	{
		mlx_pixel_put_img(img_ptr, xi, yi, rainbow_gen(c.color_begin));
		e = e + coef;
		if (e >= 0)
		{
			yi--;
			e = e + e_corect;
		}
		c.color_begin += i_color;
		xi++;
	}
}

static void	case_verti(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int xi;
	int yi;
	int dx;
	int dy;
	int e;
	int coef;
	int e_corect;
	int i_color;

	i_color = 0;
	if (p2.y - p1.y)
		i_color = (c.color_end - c.color_begin) / (p2.y - p1.y);
	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	yi = p1.y;
	xi = p1.x;
	e = dy;
	coef = dx * 2;
	e_corect = -1 * dy * 2;
	while (yi <= p2.y)
	{
		mlx_pixel_put_img(img_ptr, xi, yi, rainbow_gen(c.color_begin));
		e = e + coef;
		if (e >= 0)
		{
			xi++;
			e = e + e_corect;
		}
		c.color_begin += i_color;
		yi++;
	}
}

static void	case_vertineg(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int xi;
	int yi;
	int dx;
	int dy;
	int e;
	int coef;
	int e_corect;
	int i_color;

	i_color = 0;
	if (p1.y - p2.y)
		i_color = (c.color_end - c.color_begin) / (p1.y - p2.y);
	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	yi = p1.y;
	xi = p1.x;
	e = dy;
	coef = dx * 2;
	e_corect = dy * 2;
	while (yi >= p2.y)
	{
		mlx_pixel_put_img(img_ptr, xi, yi, rainbow_gen(c.color_begin));
		e = e + coef;
		if (e >= 0)
		{
			xi++;
			e = e + e_corect;
		}
		c.color_begin += i_color;
		yi--;
	}
}

void	ft_drawline_img_c(void *img_ptr, t_point p1, t_point p2, t_color c)
{
	int dx;
	int dy;
	int i_color;
	//t_point tmp;

	if ((dx = p2.x - p1.x) != 0)
	{
		if (dx > 0)
		{
			if((dy = p2.y - p1.y) != 0)
			{
				if(dy > 0)
				{
					if (dx > dy)
					{
						case_horiz(img_ptr, p1, p2, c);
					}
					else
					{
						case_verti(img_ptr, p1, p2, c);
					}
				}
				else
				{
					if (dx > -dy)
					{
						case_horizneg(img_ptr, p1, p2, c);
					}
					else
					{
						case_vertineg(img_ptr, p1, p2, c);
					}
				}
			}
			else
			{
				if (p1.x < p2.x)
				{
					while (p1.x != p2.x)
					{
						mlx_pixel_put_img(img_ptr, p1.x, p2.y, c.color_begin);
						p1.x++;
					}
				}
				else
				{
					while (p1.x != p2.x)
					{
						mlx_pixel_put_img(img_ptr, p1.x, p2.y, c.color_begin);
						p2.x++;
					}
				}
			}
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
		if (p1.y < p2.y)
		{
			i_color = 0;
			if (p2.y - p1.y)
				i_color = (c.color_end - c.color_begin) / (p2.y - p1.y);
			while (p1.y != p2.y)
			{
				mlx_pixel_put_img(img_ptr, p1.x, p1.y, c.color_begin);
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
				mlx_pixel_put_img(img_ptr, p1.x, p2.y, c.color_begin);
				p2.y++;
				c.color_begin -= i_color;
			}
		}
	}
}
