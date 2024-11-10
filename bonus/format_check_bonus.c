/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:11:14 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 08:36:55 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_isdigit(int alpha)
{
	if (alpha < '0' || alpha > '9')
	{
		return (0);
	}
	return (1);
}

int	ft_is_number(const char *str)
{
	int	has_decimal_point;

	has_decimal_point = 0;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (has_decimal_point)
				return (1);
			has_decimal_point = 1;
		}
		else if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

void	tell_you_correct_format(void)
{
	ft_printf("Correctformat: ./fractol <fractol-name>\n");
	ft_printf("fractol-name = [mandelbrot, julia, burning]\n");
	ft_printf("if(fractol-name == julia)\n");
	ft_printf("	Correctformat: ./fractol julia <digit> <digit>\n");
	exit(0);
}

//c.x = -0.7, c.y = 0.27015
void	format_check(int argc, char **argv, t_fractal *frac_ptr)
{
	if (argc == 1)
		tell_you_correct_format();
	if (!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 2)
		mandelbrot_param(frac_ptr);
	else if (!ft_strncmp(argv[1], "julia", 5) && argc == 4)
	{
		if (!ft_is_number(argv[2]) && !ft_is_number(argv[3]))
		{
			frac_ptr->c.x = ft_atod(argv[2]);
			frac_ptr->c.y = ft_atod(argv[3]);
			julia_param(frac_ptr);
		}
		else
			tell_you_correct_format();
	}
	else if (!ft_strncmp(argv[1], "burning", 7) && argc == 2)
		burning_param(frac_ptr);
	else
		tell_you_correct_format();
}
