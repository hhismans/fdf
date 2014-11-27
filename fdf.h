/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 19:07:06 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/27 22:08:44 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#define BLUE		0x0000FF
#define GREEN		0x00FF00
#define RED			0xFF0000
#define DOWN		65364
#define UP			65362
#define LEFT		65361
#define RIGHT		65363
#define B_KEY		98
#define G_KEY		103
#define R_KEY		114
#define POS_KEY		61
#define MINUS_KEY	45
#define ESC_KEY		65307
#define S_KEY		115
#define D_KEY		100
#define A_KEY		97
#define W_KEY		119
typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img2;
	int		**tab;
}					t_env;

void		ft_drawline(t_env env, t_point p1, t_point p2, int color);
void		ft_drawline_img(void *img_ptr, t_point p1, t_point p2, int color);
int			**getinfo(char *file);
t_point		**convert_cavaliere(int **tab_int);
t_point		**convert_axono(int **tab_int, int zoom, double alpha, double omega, int decal_x, int decal_y);
void		draw_grid(t_env e, t_point **tab, int color);
void	mlx_pixel_put_img(void *img_ptr, int x, int y, int color);
void	window_color(t_env e, void *img, int color, int x, int y);
