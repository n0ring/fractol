/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:25:39 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:25:41 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*start;
	char	*end;
	size_t	len;

	if (!s1)
		return (0);
	start = (char *) s1;
	len = ft_strlen(start);
	end = start + len - 1;
	while (ft_strchr(set, *start) && start <= end)
		start++;
	while (ft_strchr(set, *end) && start <= end)
		end--;
	res = ft_substr(start, 0, end - start + 1);
	if (!res)
		return (NULL);
	return (res);
}
