/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:23:24 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:23:26 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstiter(t_list *lst, int (*f)(int, int), int num)
{
	t_list	*tmp;

	if (!lst || !f)
		return (-2);
	tmp = lst;
	while (tmp)
	{
		if ((*f)(tmp->data, num) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
