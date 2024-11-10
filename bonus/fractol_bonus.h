/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 07:34:28 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <time.h>
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "key_code_bonus.h"
# include <math.h>
# include <stdio.h>
# include <stddef.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define ZOOM_LEVEL 1.3

typedef struct imaginary {
	double	x;
	double	y;
}			t_complex;

t_complex	complex_sqr(t_complex a);
t_complex	complex_add(t_complex a, t_complex b);

typedef struct s_fractal {
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	char		*name;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			iterations;
	int			color;
	int			kinds;
	int			sum_zoom;
	double		zoom;
	double		xarrow;
	double		yarrow;
	double		x_min;
	double		y_min;
	double		x_max;
	double		y_max;
	t_complex	c;
}				t_fractal;

t_complex	mappoint(t_fractal *julia, double x, double y);

void		julia_set(t_fractal *julia);
void		mandelbrot_set(t_fractal *mandel);
void		burning_set(t_fractal *burning);

int			fractal_setup(t_fractal *frac_ptr);

void		mandelbrot_param(t_fractal *frac_ptr);
void		julia_param(t_fractal *frac_ptr);
void		burning_param(t_fractal *frac_ptr);

void		ft_zoom(double x, double y, t_fractal *frac_ptr);
void		ft_dezoom(double x, double y, t_fractal *frac_ptr);
int			key_hook(int keycode, t_fractal *frac_ptr);
int			mouse_hook(int key_code, int x, int y, t_fractal *frac_ptr);

int			freeall_closegame(t_fractal *frac_ptr);

int			my_mlx_pixel_put(t_fractal *frac_ptr, int x, int y, int color);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

double		ft_atod(const char *str);

void		format_check(int argc, char **argv, t_fractal *frac_ptr);
void		pan_arrow(t_fractal *frac_ptr);

void		ft_zoom(double x, double y, t_fractal *frac_ptr);
void		ft_dezoom(double x, double y, t_fractal *frac_ptr);
#endif