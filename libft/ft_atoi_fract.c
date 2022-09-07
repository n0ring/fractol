/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:53:13 by namina             #+#    #+#            */
/*   Updated: 2021/08/09 18:53:13 by namina            ###    #######.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	get_number(char *str)
{
	double	i;
	double	res;

	res = 0;
	i = 10;
	while (ft_isdigit(*str))
	{
		res = res * 10 + ((*str) - 48);
		str++;
	}
	if (*str == '.' || *str == ',')
	{
		str++;
		while (ft_isdigit(*str))
		{
			res = res + ((*str) - 48) / i;
			str++;
			i *= 10;
		}
	}
	return (res);
}

double	ft_atoi_fract(char *str)
{
	double	minus;

	minus = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	return (get_number(str) * minus);
}
