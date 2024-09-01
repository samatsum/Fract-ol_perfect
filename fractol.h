/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/02 04:15:01 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stddef.h>

# define ESC 65307

# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define R 114
# define Z 122
# define PLUS 65451
# define MINUS 65453

// https://github.com/Xyckens/fract-ol ここが元のやつ

typedef struct imaginary {
	double	x;
	double	y;
}			t_complex;

t_complex	sqr(t_complex a);
t_complex	add(t_complex a, t_complex b);

typedef struct s_fractal {
	char		*name;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_complex	c;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
}				t_fractal;

t_complex	mappoint(t_fractal *julia, double x, double y);

void		juliaset(t_fractal *julia);
void		mandelbrotset(t_fractal *mandel);
void		burningset(t_fractal *burning);

int			my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);

void		fractalsetup(t_fractal *fractal);

void		mandelbrot_param(t_fractal *fractal, char *name, int *fractal_k);
void		julia_param(t_fractal *fractal, char *name, int *fractal_k);
void		burning_param(t_fractal *fractal, char *name, int *fractal_k);

void		ft_zoom(double x, double y, t_fractal *fractal);
void		ft_dezoom(double x, double y, t_fractal *fractal);
int			key_hook(int keycode, t_fractal *fractal);
int			mouse_hook(int key_code, int x, int y, t_fractal *fractal);
int			close_game(t_fractal *fractal);

int			freeall(t_fractal *fractal);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
#endif