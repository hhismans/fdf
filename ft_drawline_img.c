/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 13:29:38 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/24 12:49:30 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf.h"
#include <unistd.h>

static void	case_horiz(t_env env, t_point p1, t_point p2, int color)
{
	int xi;
	int yi;
	int dx;
	int dy;
	int e;
	int coef;
	int e_corect;

	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	yi = p1.y;
	xi = p1.x;
	e = dx;
	coef = dy  * 2;
	e_corect = -1 * dx * 2;
	while (xi <= p2.x)
	{
		mlx_image_pixel_put(env.mlx, env.win, xi, yi, color);
		e = e + coef;
		if (e >= 0)
		{
			yi++;
			e = e + e_corect;
		}
		xi++;
	}
}

static void	case_horizneg(t_env env, t_point p1, t_point p2, int color)
{
	int xi;
	int yi;
	int dx;
	int dy;
	int e;
	int coef;
	int e_corect;

	dy = p1.y - p2.y;
	dx = p2.x - p1.x;
	yi = p1.y;
	xi = p1.x;
	e = dx;
	coef = dy * 2;
	e_corect = -1 * dx * 2;
	while (xi <= p2.x)
	{
		mlx_image_pixel_put(env.mlx, env.win, xi, yi, color);
		e = e + coef;
		if (e >= 0)
		{
			yi--;
			e = e + e_corect;
		}
		xi++;
	}
}

static void	case_verti(t_env env, t_point p1, t_point p2, int color)
{
	int xi;
	int yi;
	int dx;
	int dy;
	int e;
	int coef;
	int e_corect;

	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	yi = p1.y;
	xi = p1.x;
	e = dy;
	coef = dx * 2;
	e_corect = -1 * dy * 2;
	while (yi <= p2.y)
	{
		mlx_image_pixel_put(env.mlx, env.win, xi, yi, color);
		e = e + coef;
		if (e >= 0)
		{
			xi++;
			e = e + e_corect;
		}
		yi++;
	}
}

static void	case_vertineg(t_env env, t_point p1, t_point p2, int color)
{
	int xi;
	int yi;
	int dx;
	int dy;
	int e;
	int coef;
	int e_corect;

	
	
	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	yi = p1.y;
	xi = p1.x;
	e = dy;
	coef = dx * 2;
	e_corect = dy * 2;
	while (yi >= p2.y)
	{
		mlx_image_pixel_put(env.mlx, env.win, xi, yi, color);
		e = e + coef;
		if (e >= 0)
		{
			xi++;
			e = e + e_corect;
		}
		yi--;
	}
}

void	ft_drawline_img(t_env env, t_point p1, t_point p2, int color)
{
	int dx;
	int dy;
	t_point tmp;

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
						case_horiz(env, p1, p2, color);
					}
					else
					{
						case_verti(env, p1, p2, color);
					}
				}
				else
				{
					if (dx > -dy)
					{
						case_horizneg(env, p1, p2, color);
					}
					else
					{
						case_vertineg(env, p1, p2, color);
					}
				}
			}
			else
			{
				if (p1.x < p2.x)
				{
					while (p1.x != p2.x)
					{
						mlx_image_pixel_put(env.mlx, env.win, p1.x, p2.y, color);
						p1.x++;
					}
				}
				else
				{
					while (p1.x != p2.x)
					{
						mlx_image_pixel_put(env.mlx, env.win, p1.x, p2.y, color);
						p2.x++;
					}
				}
			}
		}
		else
		{
			ft_drawline_img(env, p2, p1, color);
		}
	}
	else
	{
		if (p1.y < p2.y)
		{
			while (p1.y != p2.y)
			{
				mlx_image_pixel_put(env.mlx, env.win, p1.x, p1.y, color);
				p1.y++;
			}
		}
		else
		{
			while (p1.y != p2.y)
			{
				mlx_image_pixel_put(env.mlx, env.win, p1.x, p2.y, color);
				p2.y++;
			}
		}
	}
}
