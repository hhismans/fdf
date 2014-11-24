/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 18:19:44 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/24 18:35:40 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int main(int argc, char **argv)
{
	t_point p1;
	t_point p2;
	t_env e;
	void *img;

	e.mlx = mlx_init(); // a tester
	e.win = mlx_new_window(e.mlx, 1000,1000, "test");
	img = mlx_new_image(e.mlx,1000,1000);

	p1.x = 100;
	p1.y = 100;
	p2.x = 900;
	p2.y = 100;
	while (p1.y <= 900)
	{
		ft_drawline_img(img, p1, p2, RED);
		p1.y += 10;
		p2.y += 10;
	}

	p1.y = 100;
	p1.x = 100;
	p2.y = 900;
	p2.x = 100;
	while (p1.x <= 900)
	{
		ft_drawline_img(img, p1, p2, RED);
		p1.x += 10;
		p2.x += 10;
	}
	p1.x = 500;
	p1.y = 500;
	p2.x = 10;
	p2.y = 100;
	while (p2.y < 900)
	{
		ft_drawline_img(img, p2, p1, RED);
		p2.y++;
	}
	p1.x = 500;
	p1.y = 500;
	p2.x = 900;
	p2.y = 100;
	while (p2.y < 900)
	{
		ft_drawline_img(img, p2, p1, RED);
		p2.y++;
	}
	p1.x = 500;
	p1.y = 500;
	p2.x = 10;
	p2.y = 100;
	while (p2.x < 900)
	{
		ft_drawline_img(img, p1, p2, BLUE);
		p2.x++;
	}
	p1.x = 500;
	p1.y = 500;
	p2.x = 10;
	p2.y = 900;
	while (p2.x < 900)
	{
		ft_drawline_img(img, p1, p2, BLUE);
		p2.x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, img, 0, 0);
	sleep(5);
	return (0);
}
