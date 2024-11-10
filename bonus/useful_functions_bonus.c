/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:08:01 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 07:30:42 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

int	my_mlx_pixel_put(t_fractal *frac_ptr, int x, int y, int color)
{
	char	*dst;

	dst = frac_ptr->addr + (y * frac_ptr->line_length + x \
			* (frac_ptr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

int	freeall_closegame(t_fractal *frac_ptr)
{
	mlx_destroy_image(frac_ptr->mlx, frac_ptr->img);
	mlx_destroy_window(frac_ptr->mlx, frac_ptr->win);
	mlx_destroy_display(frac_ptr->mlx);
	free(frac_ptr->mlx);
	exit(0);
}

void	pan_arrow(t_fractal *frac_ptr)
{
	double	pan_x;
	double	pan_y;

	pan_x = frac_ptr->xarrow * (frac_ptr->x_max - frac_ptr->x_min) / \
		frac_ptr->width;
	pan_y = frac_ptr->yarrow * (frac_ptr->y_max - frac_ptr->y_min) / \
		frac_ptr->height;
	frac_ptr->x_min += pan_x;
	frac_ptr->x_max += pan_x;
	frac_ptr->y_min += pan_y;
	frac_ptr->y_max += pan_y;
	frac_ptr->xarrow = 0;
	frac_ptr->yarrow = 0;
}
