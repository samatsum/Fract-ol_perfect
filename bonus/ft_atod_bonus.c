/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:16:42 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 07:30:42 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	check_overflow(int m, unsigned long long a, const char *str, int i)
{
	if (m == 1 && a >= 9223372036854775807ULL)
		return (-1);
	if (m == -1 && a >= 9223372036854775808ULL)
		return (0);
	if (m == 1 && a >= 1844674407370955161 && str[i + 1] >= '6')
		return (-1);
	if (m == -1 && a >= 1844674407370955161 && str[i + 1] >= '7')
		return (0);
	return (2);
}

double	decimal_calculater(int ans, int i, const char *str)
{
	double	decimal_part;
	double	decimal_divisor;

	decimal_part = 0.0;
	decimal_divisor = 1.0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			decimal_part = decimal_part * 10 + (str[i] - '0');
			decimal_divisor *= 10.0;
			i++;
		}
	}
	return ((double)ans + (decimal_part / decimal_divisor));
}

double	ft_atod(const char *str)
{
	int						i;
	unsigned long long		ans;
	int						minus_flag;
	int						result;

	i = 0;
	minus_flag = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_flag = -1;
		i++;
	}
	ans = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		result = check_overflow(minus_flag, ans, str, i);
		if (result != 2)
			return (result);
		i++;
	}
	return (decimal_calculater(ans, i, str) * minus_flag);
}
