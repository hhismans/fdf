/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 11:58:03 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/28 11:12:57 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include <math.h>
#include <stdlib.h>

static int		*filltab(char **tab_char)
{
	int size;
	int i;
	int *tab_int;

	size = 0;
	while (tab_char[size])
		size++;
	tab_int = (int *)ft_memalloc(sizeof(int) * (size + 1));
	tab_int[0] = size;
	i = 1;
	while (i < size + 1)
	{
		tab_int[i] = ft_atoi(tab_char[i - 1]);
		i++;
	}
	return (tab_int);
}

int		**getinfo(char *file)
{
	char *line;
	char **tab_char;
	int nbr_line;
	int i;
	int ret;
	int fd;
	int **tab_int;
	t_list *lst_line;
	t_list *tmp;

	nbr_line = 0;
	fd = open(file, O_RDONLY);
	if ((ret = get_next_line(fd, &line)))
	{
		lst_line = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1));
		nbr_line++;
	}
	tmp = lst_line;
	while ((ret = get_next_line(fd, &line)))
	{
		tmp->next = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1));
		tmp = tmp->next;
		nbr_line++;
	}
	close(fd);
	i = 0;
	tab_int = (int **)ft_taballoc(sizeof(int) * (nbr_line));
	tmp = lst_line;
	while (tmp)
	{
		tab_char = ft_strsplit((char *)tmp->content, ' ');
		tab_int[i] = filltab(tab_char);
		i++;
		tmp = tmp->next;
	}
	return(tab_int);
}

t_point		**convert_axono(int **tab_int, int zoom, double alpha, double omega, int decal_x, int decal_y, int mult_z)
{
	//int **tab_cav;
	int size;
	int i;
	int j;
	t_point **point_cav;
	size = 0;
	while (tab_int[size])
		size++;
	i = 0;
	j = 0;
	//tab_cav = (int **)ft_taballoc(sizeof(int) * (size + 1));
	point_cav = (t_point **)ft_taballoc(sizeof(t_point *) * (size + 1));
	while (tab_int[i])
	{
		point_cav[i] = (t_point *)ft_memalloc(sizeof(t_point) * tab_int[i][0] + 1);
		point_cav[i][0].x = tab_int[i][0];
		j = 1;
		while (j <= tab_int[i][0])
		{
			//ft_putendl("while interne");
			point_cav[i][j].x = ((((int)(cos(omega) * 100) * (j - 1)) - (((int)(100 * sin(omega)) * i)))) / zoom + decal_x;
			point_cav[i][j].y = ((((int)(100 * (sin(omega) * sin(alpha))) * (j - 1)) - (int)(100 * (cos(omega) * sin (alpha))) * i + ((int)(100 * cos(alpha)) * - tab_int[i][j] * mult_z / 50)) / zoom) + decal_y;

			//point_cav[i][j].x = (((87 * (j - 1)) + (50 * i))) / zoom;
			//point_cav[i][j].y = (((-17 * (j - 1)) - 30 * i + (94 * tab_int[i][j])) / zoom) + 500;
			j++;
		}
		i++;
	}
	return (point_cav);
}

t_point		**convert_cavaliere(int **tab_int)
{
	//int **tab_cav;
	int size;
	int i;
	int j;
	t_point **point_cav;
	size = 0;
	while (tab_int[size])
		size++;
	i = 0;
	j = 0;
	//tab_cav = (int **)ft_taballoc(sizeof(int) * (size + 1));
	point_cav = (t_point **)ft_taballoc(sizeof(t_point *) * (size + 1));
	while (tab_int[i])
	{
		point_cav[i] = (t_point *)ft_memalloc(sizeof(t_point) * tab_int[i][0] + 1);
		point_cav[i][0].x = tab_int[i][0];
		j = 1;
		while (j <= tab_int[i][0])
		{
			//ft_putendl("while interne");
			point_cav[i][j].x = (10 * (j - 1)) + (35 * tab_int[i][j]);
			point_cav[i][j].y = (10 * i) + (35 * tab_int[i][j]);
			j++;
		}
		i++;
	}
	return (point_cav);
}

int		key_hook(int keycode, t_env *e)
{
	static int	omega = 0;
	static int	alpha = 0;
	static int	zoom = 3;
	int j = 0;
	int i = 0;
	static int	color = GREEN;
	static int	decal_x = 0;
	static int decal_y = 500;
	static int	gamme = 2;
	static mult_z = 5;
	t_point		**tab_conv;

	if (keycode == RIGHT)
		omega--;
	if (keycode == LEFT)
		omega++;
	if (keycode == DOWN)
		alpha--;
	if (keycode == UP)
		alpha++;
	if (keycode == B_KEY)
		color = BLUE;
	if (keycode == R_KEY)
		color = RED;
	if (keycode == G_KEY)
		color = GREEN;
	if (keycode == MINUS_KEY)
		zoom++;
		if (zoom == 0)
			zoom = 1;
	if (keycode == POS_KEY)
	{
		zoom--;
		if (zoom == 0)
			zoom = -1;
	}
	if (keycode == S_KEY)
		decal_y += 10;
	if (keycode == W_KEY)
		decal_y -= 10;
	if (keycode == D_KEY)
		decal_x += 10;
	if (keycode == A_KEY)
		decal_x -= 10;
	if (keycode == OCROCH_KEY)
		gamme--;
	if (keycode == CCROCH_KEY)
		gamme++;
	if (keycode == CPAR_KEY)
		mult_z++;
	if (keycode == OPAR_KEY)
		mult_z--;
	if (keycode == ESC_KEY)
		exit(0);
	ft_putstr("\nOMEGA = ");
	ft_putnbr(omega);
	ft_putstr("\nALPHA = ");
	ft_putnbr(alpha);
	tab_conv = convert_axono((*e).tab, zoom, alpha * M_PI / 180, omega * M_PI / 180, decal_x, decal_y, mult_z);
	mlx_destroy_image((*e).mlx, (*e).img);
	(*e).img = mlx_new_image((*e).mlx, WIDTH, HEIGHT);
	draw_grid(*e, tab_conv, (*e).tab, gamme * mult_z / 5);
	//free(tab_conv);
	mlx_put_image_to_window((*e).mlx, (*e).win, (*e).img, 0, 0);
	ft_putstr("key = ");
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

	j = 0;
	i = 0;
	e.tab = getinfo(argv[1]);

	while (e.tab[j])
	{
		i = 0;
		while (i <= e.tab[j][0])
		{
			ft_putnbr(e.tab[j][i]);
			ft_putstr("\t");
			i++;
		}
		ft_putendl("");
		j++;
	}
	i = 0;
	j = 0;
	tab_cav = convert_axono(e.tab, 3, -48 * M_PI / 180, -8 * M_PI / 180, 0, 500, 5);
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
	draw_grid(e, tab_cav, e.tab, 1);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (argc);
}
