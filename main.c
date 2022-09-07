/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:48:55 by namina             #+#    #+#            */
/*   Updated: 2021/08/08 17:48:55 by namina            ###    #######.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_in_mandelbrot(double c_re, double c_im, t_data *data)
{
	double	z_re;
	double	z_im;
	double	z_re_sq;
	double	z_im_sq;
	int		i;

	i = 0;
	z_re = c_re;
	z_im = c_im;
	if (!data)
		return (-1);
	while (i < 150)
	{
		if ((z_re * z_re + z_im * z_im) > 4)
			return (i + 1);
		z_im_sq = z_im * z_im;
		z_re_sq = z_re * z_re;
		z_im = (2 * z_re * z_im) + c_im;
		z_re = z_re_sq - z_im_sq + c_re;
		i++;
	}
	return (0);
}

int	is_in_julia(double c_re, double c_im, t_data *data)
{
	double	z_re;
	double	z_im;
	double	z_re_sq;
	double	z_im_sq;
	int		i;

	i = 0;
	z_re = c_re;
	z_im = c_im;
	while (i < 100)
	{
		z_im_sq = z_im * z_im;
		z_re_sq = z_re * z_re;
		z_im = (2 * z_re * z_im) + data->const_im;
		z_re = z_re_sq - z_im_sq + data->const_re;
		if ((z_re * z_re + z_im * z_im) > 4)
			return (i + 1);
		i++;
	}
	return (0);
}

int	is_in_burn_ship(double c_re, double c_im, t_data *data)
{
	double	z_re;
	double	z_im;
	double	z_re_sq;
	double	z_im_sq;
	int		i;

	i = 0;
	z_re = c_re;
	z_im = c_im;
	if (!data)
		return (-1);
	while (i < 150)
	{
		if ((z_re * z_re + z_im * z_im) > 4)
			return (i + 1);
		z_im_sq = z_im * z_im;
		z_re_sq = z_re * z_re;
		z_im = (2 * z_re * z_im);
		if (z_im > 0)
			z_im *= -1;
		z_im = z_im + c_im;
		z_re = z_re_sq - z_im_sq + c_re;
		i++;
	}
	return (0);
}

void	info_output(void)
{
	printf("Type name of fractal after program name to see image.\nAvailable "
		   "fractals:\n"
		   "Mandelbrot\nJulia\nBurning Ship\n"
		   "For navigate available arrows. For scale "
		   "use scroll or shift + arrows (up and down).\n"
		   "For Julia set "
		   "available input for const values, type it after fractal name.\n");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		info_output();
		return (0);
	}
	mlx_start(argc, argv);
	return (0);
}
