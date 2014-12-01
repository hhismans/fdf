/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:43:11 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/01 17:45:07 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include <math.h>
#include <stdlib.h>

int		key_hook(int keycode, t_env *e)
{
	int j = 0;
	int i = 0;
	static int	color = GREEN;
	static int increment = 1;

	t_point		**tab_conv;

	if (keycode == RIGHT)
		e->omega -= increment;
	if (keycode == LEFT)
		e->omega += increment;
	if (keycode == DOWN)
		e->alpha -= increment;
	if (keycode == UP)
		e->alpha += increment;
	if (keycode == B_KEY)
		color = BLUE;
	if (keycode == R_KEY)
		color = RED;
	if (keycode == G_KEY)
		color = GREEN;
	if (keycode == MINUS_KEY)
		e->zoom += increment;
		if (e->zoom == 0)
			e->zoom = 1;
	if (keycode == POS_KEY)
	{
		e->zoom -= increment;
		if (e->zoom == 0)
			e->zoom = -1;
	}
	if (keycode == S_KEY)
		e->decal.y += increment * 10;
	if (keycode == W_KEY)
		e->decal.y -= increment * 10;
	if (keycode == D_KEY)
		e->decal.x += increment * 10;
	if (keycode == A_KEY)
		e->decal.x -= increment * 10;
	if (keycode == OCROCH_KEY)
		e->gamme -= increment;
	if (keycode == CCROCH_KEY)
		e->gamme += increment;
	if (keycode == CPAR_KEY)
		e->mult_z += increment;
	if (keycode == OPAR_KEY)
		e->mult_z -= increment;
	if (keycode >= ONE_KEY && keycode <= NINE_KEY)
		increment = keycode - ONE_KEY + 1;
	if (keycode == ESC_KEY)
		exit(0);
	ft_putstr("\nOMEGA = ");
	ft_putnbr(e->omega);
	ft_putstr("\nALPHA = ");
	ft_putnbr(e->alpha);
	ft_putstr("\nGAMME= ");
	ft_putnbr(e->gamme);
	ft_putstr("\ndecal_x = ");
	ft_putnbr(e->decal.x);
	ft_putstr("\ndecal_y = ");
	ft_putnbr(e->decal.y);
	ft_putstr("\nMult_z = ");
	ft_putnbr(e->mult_z);
	ft_putstr("\nzoom = ");
	ft_putnbr(e->zoom);
//	e->omega = e->omega * M_PI / 180;
//	e->alpha = e->alpha * M_PI / 180;

	tab_conv = convert_map(*e, conv_axono);
	mlx_destroy_image((*e).mlx, (*e).img);
	(*e).img = mlx_new_image((*e).mlx, WIDTH, HEIGHT);
	draw_grid(*e, tab_conv, (*e).tab_int, e->gamme * e->mult_z / 5);
	//free(tab_conv);
	mlx_put_image_to_window((*e).mlx, (*e).win, (*e).img, 0, 0);
	ft_putstr("\nkey = ");
	ft_putnbr(keycode);
	ft_putendl("");
	return (0);
}

int		main(int argc, char **argv)
{
	int **tab;
	t_point **tab_cav;
	int i;
	int j;
	t_env e;
	int **tab_axe;

	
	j = 0;
	i = 0;
	e.tab_int = getinfo(argv[1]);

	while (e.tab_int[j])
	{
		i = 0;
		while (i <= e.tab_int[j][0])
		{
			ft_putnbr(e.tab_int[j][i]);
			ft_putstr("\t");
			i++;
		}
		ft_putendl("");
		j++;
	}
	i = 0;
	j = 0;
//	tab_cav = convert_axono(e.tab, 3, -48 * M_PI / 180, -8 * M_PI / 180, 0, 500, 5);
	//tab_cav = convert_cavaliere(tab);
	ft_putendl("CONVERTI X");
	while (tab_cav[j])
	{
		i = 0;
		while (i <= tab_cav[j][0].x)
		{
			ft_putnbr(tab_cav[j][i].x);
			ft_putstr("\t");
			i++;
		}
		ft_putendl("");
		j++;
	}
	j = 0;
	ft_putendl("CONVERTI y");
	while (tab_cav[j])
	{
		i = 0;
		while (i <= tab_cav[j][0].x)
		{
			ft_putnbr(tab_cav[j][i].y);
			ft_putstr("\t");
			i++;
		}
		ft_putendl("");
		j++;
	}
/*	t_env e;
	t_color c;
	t_point p1;
	t_point p2;

	p1.x = 500;
	p1.y = 500;
	p2.x = 250;
	p2.y = 250;

	c.color_begin = 0;
	c.color_end = 1500;*/
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "test fdf");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
/*	while (p2.x < 750)
	{
			ft_drawline_img_c(e.img, p1, p2, c);
		p2.x++;
	}

	p1.x = 500;
	p1.y = 500;
	p2.x = 750;
	p2.y = 250;

	while (p2.y <750)
	{
		ft_drawline_img_c(e.img, p1, p2, c);
		p2.y++;
	}

	while (p2.x > 250)
	{
		ft_drawline_img_c(e.img, p1, p2, c);
		p2.x--;
	}
	while (p2.y > 250)
	{
		ft_drawline_img_c(e.img, p1, p2, c);
		p2.y--;
	}*/
	e.omega = 10;
	e.alpha = -69;
	e.zoom = 2;
	e.decal.x = 470;
	e.decal.y = 360;
	e.gamme = 43;
	e.mult_z = 10;

	draw_grid(e, tab_cav, e.tab_int, 1);
//	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
//	mlx_hook_key_press(e.win, key_hoo
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (argc);
}
