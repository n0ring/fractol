/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:48:55 by namina             #+#    #+#            */
/*   Updated: 2021/08/08 17:48:55 by namina            ###    #######.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_data
{
	void			*img;
	void			*addr;
	void			*mlx;
	void			*win;
	int				bits_per_pix;
	int				line_length;
	int				endian;
	double			min_re;
	double			min_im;
	double			max_re;
	double			max_im;
	unsigned int	color;
	double			scale_coof;
	double			len_re_current;
	double			len_im_current;
	double			const_re;
	double			const_im;
	void			*set_func;
	char			*dst;
}			t_data;

unsigned int	create_trgb(unsigned int t, unsigned int r, unsigned int
					g, unsigned int b);
void			draw(int (*is_in_set)(), t_data *data);
int				mouse_hooks(int key_code, int x, int y, t_data *data);
int				is_in_mandelbrot(double c_re, double c_im, t_data *data);
int				is_in_julia(double c_re, double c_im, t_data *data);
int				is_in_burn_ship(double c_re, double c_im, t_data *data);
int				mlx_start(int argc, char **argv);
int				key_hooks(int key_code, t_data *data);
int				scale_center(int key_code, t_data *data);
void			info_output(void);

#endif