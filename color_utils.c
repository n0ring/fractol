/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:48:55 by namina             #+#    #+#            */
/*   Updated: 2021/08/08 17:48:55 by namina            ###    #######.fr      */
/*                                                                            */
/* ************************************************************************** */

unsigned int	create_trgb(unsigned int t, unsigned int r, unsigned int
g, unsigned int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
