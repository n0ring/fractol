/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:24:24 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:24:25 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_src;
	unsigned char	*p_dst;

	i = 0;
	if ((!dst && !src))
		return (0);
	p_src = (unsigned char *) src;
	p_dst = (unsigned char *) dst;
	while (i < n)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
		i++;
	}
	return (dst);
}
