/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:25:42 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:25:44 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	mem;

	if (!s)
		return (0);
	s_len = ft_strlen((char *) s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len)
		mem = s_len + 1;
	else
		mem = len + 1;
	res = malloc(mem);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, mem);
	return (res);
}
