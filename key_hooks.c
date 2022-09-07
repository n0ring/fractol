/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:48:55 by namina             #+#    #+#            */
/*   Updated: 2021/08/08 17:48:55 by namina            ###    #######.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ARROWUP 126
#define ARROWDOWN 125
#define ARROWLEFT 123
#define ARROWRIGHT 124
#define MOVE_COEFFICIENT 15
#define ESC 53
#define LEFT_SHIFT 257
#define KEY_PRESS 2
#define KEY_RELEASE 3

int	move_arrows(int key_code, t_data *data)
{
	if (key_code == ARROWLEFT)
	{
		data->min_re -= (data->max_re - data->min_re) / MOVE_COEFFICIENT;
		data->max_re -= (data->max_re - data->min_re) / MOVE_COEFFICIENT;
	}
	else if (key_code == ARROWRIGHT)
	{
		data->min_re += (data->max_re - data->min_re) / MOVE_COEFFICIENT;
		data->max_re += (data->max_re - data->min_re) / MOVE_COEFFICIENT;
	}
	else if (key_code == ARROWUP)
	{
		data->min_im += (data->max_im - data->min_im) / MOVE_COEFFICIENT;
		data->max_im += (data->max_im - data->min_im) / MOVE_COEFFICIENT;
	}
	else if (key_code == ARROWDOWN)
	{
		data->min_im -= (data->max_im - data->min_im) / MOVE_COEFFICIENT;
		data->max_im -= (data->max_im - data->min_im) / MOVE_COEFFICIENT;
	}
	draw(data->set_func, data);
	return (0);
}

int	set_key_hooks(int key_code, t_data *data)
{
	if (key_code == LEFT_SHIFT)
		mlx_hook(data->win, KEY_PRESS, 1L << 0, key_hooks, data);
	return (0);
}

int	key_hooks(int key_code, t_data *data)
{
	if (key_code == ESC)
		exit(0);
	if (key_code >= ARROWLEFT && key_code <= ARROWUP)
		move_arrows(key_code, data);
	if (key_code == LEFT_SHIFT)
	{
		mlx_hook(data->win, KEY_PRESS, 1L << 0, scale_center, data);
		mlx_hook(data->win, KEY_RELEASE, 1L << 1, set_key_hooks, data);
	}
	return (0);
}
