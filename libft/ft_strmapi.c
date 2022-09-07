/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:25:12 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:25:13 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = malloc(ft_strlen((char *) s) + 1);
	if (!res)
		return (0);
	while (s[j])
	{
		res[i] = (*f)(j, s[j]);
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
