/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:24:00 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:24:01 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	unsigned char	*pdest;
	unsigned char	*psource;
	size_t			i;

	pdest = (unsigned char *) dest;
	psource = (unsigned char *) source;
	i = 0;
	while (i < count)
	{
		*pdest = *psource;
		if (*psource == (unsigned char) ch)
		{
			pdest++;
			return ((void *) pdest);
		}
		pdest++;
		psource++;
		i++;
	}
	return (NULL);
}
