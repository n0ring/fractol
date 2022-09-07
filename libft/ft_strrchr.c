/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:25:22 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:25:25 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	ch;
	size_t	len;

	ch = (char) c;
	len = ft_strlen(s);
	tmp = (char *) s;
	if (!ch)
		return (tmp + len);
	while (len--)
	{
		if (tmp[len] == ch)
			return (tmp + len);
	}
	return (NULL);
}
