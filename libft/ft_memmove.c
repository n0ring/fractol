/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:24:27 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:24:30 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			i;

	if (!destination && !source)
		return (NULL);
	p_src = (unsigned char *) source;
	p_dest = (unsigned char *) destination;
	if (!n)
		return (destination);
	if (destination > source)
	{
		while (--n > 0)
			p_dest[n] = p_src[n];
		p_dest[n] = p_src[n];
		return (destination);
	}
	i = 0;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (destination);
}
