/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:25:06 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:25:08 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	len = ft_strlen((char *)src);
	if (!size)
		return (len);
	while (i < size - 1 && src[i])
	{
		*dst = src[i];
		i++;
		dst++;
	}
	*dst = '\0';
	return (len);
}
