/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 19:07:06 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/24 18:17:48 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#define BLUE	0x0000FF
#define GREEN	0x00FF00
#define RED		0xFF0000

typedef struct		s_env
{
	void *mlx;
	void *win;
}					t_env;

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;
void	ft_drawline(t_env env, t_point p1, t_point p2, int color);
void	ft_drawline_img(void *img_ptr, t_point p1, t_point p2, int color);
