/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:51:52 by namina             #+#    #+#            */
/*   Updated: 2021/08/08 17:51:52 by namina            ###    #######.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WIDTH 900
#define HEIGHT 900
#define SCROLLDOWN 4
#define SCROLLUP 5
#define ARROWUP 126
#define ARROWDOWN 125
#define MOUSE_MOTION 6
#define MOUSE_RELEASE 5
#define LEFT_BUTTON 1

int	scale(int key_code, int x, int y, t_data *data)
{
	double	c_x;
	double	c_y;

	if (!(key_code == SCROLLDOWN || key_code == SCROLLUP))
		return (0);
	c_x = data->min_re + x * (data->max_re - data->min_re) / (WIDTH - 1);
	c_y = data->max_im - y * (data->max_im - data->min_im) / (HEIGHT - 1);
	if (key_code == SCROLLDOWN)
	{
		data->len_re_current = data->len_re_current / data->scale_coof;
		data->len_im_current = data->len_im_current / data->scale_coof;
		data->scale_coof *= 1.01;
	}
	if (key_code == SCROLLUP)
	{
		data->len_re_current = data->len_re_current * data->scale_coof;
		data->len_im_current = data->len_im_current * data->scale_coof;
		data->scale_coof /= 1.01;
	}
	data->min_re = c_x - data->len_re_current / 2;
	data->max_re = data->min_re + data->len_re_current;
	data->min_im = c_y - data->len_im_current / 2;
	data->max_im = data->min_im + data->len_im_current;
	draw(data->set_func, data);
	return (0);
}

int	scale_center(int key_code, t_data *data)
{
	if (key_code == ARROWUP)
		scale(SCROLLDOWN, WIDTH / 2, HEIGHT / 2, data);
	else if (key_code == ARROWDOWN)
	{
		if (data->len_im_current > 8 || data->len_re_current > 8)
			return (0);
		scale(SCROLLUP, WIDTH / 2, HEIGHT / 2, data);
	}
	return (0);
}

int	change_const(int x, int y, t_data *data)
{
	data->const_re = data->min_re + x * (data->max_re - data->min_re) / (WIDTH
			- 1);
	data->const_im = data->max_im - y * (data->max_im - data->min_im)
		/ (HEIGHT - 1);
	draw(data->set_func, data);
	return (0);
}

int	release_mouse(int key_code, int x, int y, t_data *data)
{
	if (!key_code)
		return (-1);
	change_const(x, y, data);
	mlx_hook(data->win, MOUSE_MOTION, 0L, NULL, data);
	return (0);
}

int	mouse_hooks(int key_code, int x, int y, t_data *data)
{
	if (key_code == SCROLLDOWN || key_code == SCROLLUP)
	{
		if ((data->len_im_current > 8 || data->len_re_current > 8) && key_code
			== SCROLLUP)
			return (0);
		scale(key_code, x, y, data);
	}
	if (key_code == LEFT_BUTTON && data->set_func == is_in_julia)
	{
		mlx_hook(data->win, MOUSE_MOTION, 1L << 8, change_const, data);
		mlx_hook(data->win, MOUSE_RELEASE, 1L << 8, release_mouse, data);
	}
	return (0);
}
