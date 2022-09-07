/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:24:51 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:24:52 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *) s;
	while (*tmp)
	{
		if (*tmp == (char) c)
			return (tmp);
		tmp++;
	}
	if (!c)
		return (tmp);
	return (NULL);
}
