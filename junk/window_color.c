/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 18:20:27 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/01 18:20:47 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "fdf.h"
#include <mlx.h>

static void	window_color(t_env e, void *img, int color, int x, int y)
{
	int		i;
	int		bbp;
	int		sizeline;
	int		endian;
	char	*data;

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
