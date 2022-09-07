/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:48:55 by namina             #+#    #+#            */
/*   Updated: 2021/08/08 17:48:55 by namina            ###    #######.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_fractol(int argc, char **argv, t_data *data)
{
	if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot\0")))
		data->set_func = is_in_mandelbrot;
	else if (!ft_strncmp(argv[1], "Julia", ft_strlen("Julia\0")))
		data->set_func = is_in_julia;
	else if (!ft_strncmp(argv[1], "Burning Ship", ft_strlen("Burning Ship\0")))
		data->set_func = is_in_burn_ship;
	else if (!ft_strncmp(argv[1], "Burning", ft_strlen("Burning\0")) &&
			!ft_strncmp(argv[2], "Ship", ft_strlen("Ship\0")))
		data->set_func = is_in_burn_ship;
	else
	{
		printf("Fractal name is incorrect.\n");
		info_output();
		exit(0);
	}
	if (argc > 2)
		data->const_re = ft_atoi_fract(argv[2]);
	if (argc > 3)
		data->const_im = ft_atoi_fract(argv[3]);
	return (0);
}

int	mlx_start(int argc, char **argv)
{
	t_data	img;

	img.const_re = -1;
	img.const_im = 0;
	set_fractol(argc, argv, &img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 900, 900, argv[1]);
	img.img = mlx_new_image(img.mlx, 900, 900);
	img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pix),
			&(img.line_length), &(img.endian));
	img.min_re = -2;
	img.max_re = 2;
	img.min_im = -2;
	img.max_im = 2;
	img.scale_coof = 1.12;
	img.len_re_current = img.max_re - img.min_re;
	img.len_im_current = img.max_im - img.min_im;
	draw(img.set_func, &img);
	mlx_hook(img.win, 4, 1L << 2, mouse_hooks, &img);
	mlx_hook(img.win, 2, 1L << 0, key_hooks, &img);
	mlx_loop(img.mlx);
	return (0);
}
