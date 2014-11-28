/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:48:33 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/28 08:58:40 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "fdf.h"
#include <mlx.h>

void	window_color(t_env e, void *img, int color, int x, int y)
{
	int i;
	int bbp;
	int sizeline;
	int endian;
	char *data;

	data = mlx_get_data_addr(img, &bbp, &sizeline, &endian);
	i = 0;
	while (i < (x * 4 + sizeline * y))
	{
		data[i] = mlx_get_color_value(e.mlx, color);
		data[i + 1] = mlx_get_color_value(e.mlx, color >> 8);
		data[i + 2] = mlx_get_color_value(e.mlx, color >> 16);
		i = i + 4;
	}
}

void	mlx_pixel_put_img(void *img_ptr, int x, int y, int color)
{
	char	*data;
	int bbp;
	int sizeline;
	int endian;
	int i;

	data = mlx_get_data_addr(img_ptr, &bbp, &sizeline, &endian);
	bbp /=  8;
	i = x * bbp + y * sizeline;
	if (WIDTH * bbp + HEIGHT * sizeline < i)
		return ;
	if (x >= 0 && y >= 0)
	{
		data[i] = color;
		data[i + 1] = color >> 8;
		data[i + 2] = color >> 16;
	}
}

/*
int main(void)
{
	int		i;
	void	*img_ptr;
	char	*data;
	int		bbp;
	int		sizeline;
	int		endian;
	t_env	e;
	unsigned int color;
	unsigned int tmp;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "test");
	img_ptr = mlx_new_image(e.mlx, 1000, 1000);
	data = mlx_get_data_addr(img_ptr, &bbp, &sizeline, &endian);
	color = RED;//mlx_get_color_value(e.mlx, BLUE);
	tmp = color;
	i = 0 ;//150 * 4 + sizeline * 150;
//	window_color(e, img_ptr, BLUE, 1000, 1000);
	while (i < 500)
	{
		mlx_pixel_put_img(img_ptr, i, 300, BLUE);
		i += 1;
	}
	ft_putendl("");
	color = RED;
	ft_putnbr(color);
	ft_putendl("");
	ft_putnbr(mlx_get_color_value(e.mlx, color));
	ft_putendl("");
	ft_putnbr(color >> 16);
	mlx_put_image_to_window (e.mlx, e.win, img_ptr, 0, 0);
	sleep(5);
	return (0);
}*/
