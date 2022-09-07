/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:48:55 by namina             #+#    #+#            */
/*   Updated: 2021/08/08 17:48:55 by namina            ###    #######.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WIDTH 900
#define HEIGHT 900

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//
//}

unsigned int	get_color(int dinamic)
{
	if (!dinamic)
		return (create_trgb(0, 0, 0, 0));
	else if (dinamic < 50)
		return (create_trgb(0, 1 + dinamic * 4, 14 + dinamic * 4,
				90 + 2 * dinamic));
	else
		return (create_trgb(0, 250 - dinamic, 285 - dinamic * 1.7,
				270 - dinamic * 1.65));
}

void	draw(int (*is_in_set)(), t_data *data)
{
	int		x;
	int		y;
	int		dinamic;
	double	c_x;
	double	c_y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_x = data->min_re + x * (data->max_re - data->min_re) / (WIDTH
					- 1);
			c_y = data->max_im - y * (data->max_im - data->min_im) / (HEIGHT
					- 1);
			dinamic = is_in_set(c_x, c_y, data);
			data->color = get_color(dinamic);
//			my_mlx_pixel_put(data, x, y, data->color);
			data->dst = data->addr + (y * data->line_length + x *
					(data->bits_per_pix / 8));
			*(unsigned int *) data->dst = data->color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
