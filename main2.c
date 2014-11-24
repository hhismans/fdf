/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:04:23 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/24 20:08:23 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <mlx.h>
#include <unistd.h>
#include "fdf.h"

int main(void)
{
		t_point p1;
	t_point p2;
	t_env e;
	void *img;
	void *img2;

	e.mlx = mlx_init(); // a tester
	e.win = mlx_new_window(e.mlx, 1000,1000, "test");
	
}
